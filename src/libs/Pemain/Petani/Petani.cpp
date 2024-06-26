#include "Petani.hpp"
#include <set>
#include <algorithm>
#include "../../pcolor/pcolor.h"
#include "../../Utils/Utils.hpp"

int Petani::ladang_m = 5;
int Petani::ladang_n = 5;
Petani::Petani(string name, int gulden, int berat) : Pemain(name, gulden, berat), ladang(ladang_n, ladang_m)
{
}

Petani::~Petani()
{
}

void Petani::tanam()
{
    if (ladang.isFull())
    {
        throw LadangFullException();
    }

    if (countTanamanInventory() == 0)
    {
        throw NotEnoughTanamanException();
    }

    cout << "Pilih tanaman dari penyimpanan";
    display(inventory);
    bool valid = false;
    string slot;
    int col = 0;
    int row = 0;
    Sellable *item = nullptr;

    // Slot inventory
    do
    {
        bool acc = false;
        do
        {
            slot = getValidInputStorage("Slot");

            col = getColStorage(slot[0]);
            row = getRowStorage(slot);

            if (col < 0 || col >= inventory.getCol() || row < 0 || row >= inventory.getRow())
            {
                cout << RED << "Masukkan lokasi petak yang sesuai!" << RESET << endl;
            }
            else
            {
                acc = true;
            }

        } while (!acc);

        item = inventory.getElementAddress(row, col);
        if (item != nullptr)
        {
            if (item->getJenis() == "TANAMAN")
            {
                valid = true;
            }
            else
            {
                cout << RED << "Barang pada slot tersebut bukanlah Tanaman.\nSilakan pilih Slot lain!\n"
                     << RESET;
            }
        }
    } while (!valid);

    cout << "Kamu memilih " << CYAN << item->getNamaBarang() << "." << RESET << endl;
    cout << "Pilihlah petak tanah yang akan ditanami" << endl;

    display(ladang);

    valid = false;
    string petak;
    int colP = 0;
    int rowP = 0;
    Tanaman *cekPetak = nullptr;

    // Validasi apakah petak yang dipilih valid (kosong)
    do
    {
        bool acc = false;
        do
        {
            slot = getValidInputStorage("Petak tanah");

            colP = getColStorage(slot[0]);
            rowP = getRowStorage(slot);

            if (colP < 0 || colP >= ladang.getCol() || rowP < 0 || rowP >= ladang.getRow())
            {
                cout << RED << "Masukkan lokasi petak yang sesuai!" << RESET << endl;
            }
            else
            {
                acc = true;
            }

        } while (!acc);

        cekPetak = ladang.getElementAddress(rowP, colP);
        if (cekPetak == nullptr)
        {
            valid = true;
        }
        else
        {
            cout << RED << "Petak yang anda pilih tidak kosong.\nSilakan pilih petak kosong." << RESET << endl;
        }

    } while (!valid);

    Tanaman *tanaman = dynamic_cast<Tanaman *>(item);
    ladang.insert(rowP, colP, *tanaman);
    inventory.deleteAt(row, col);

    cout << GREEN << "Cangkul, cangkul, cangkul yang dalam~!" << endl;
    cout << RESET << YELLOW << RESET << item->getNamaBarang() << GREEN << " berhasil ditanam!" << RESET << endl;
}

void Petani::panen()
{
    cetakLadang();

    // Dapatkan semua item yang ready untuk dipanen
    map<string, tuple<vector<string>, int>> readyItems = readyPanen(ladang);
    if (readyItems.size() > 0)
    {
        cout << "Pilih tanaman siap panen yang kamu miliki" << endl;
        displayReadyPanen(readyItems);

        // Pilihan tanaman yang mau dipanen
        bool valid = false;
        int size = readyItems.size();
        int nomor;
        string chosenItem;
        cout << endl;
        do
        {
            cout << "Nomor tanaman yang ingin dipanen: ";
            cin >> nomor;
            if (cin.fail())
            {
                cout << RED << "Masukkan angka!" << RESET << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (1 <= nomor && nomor <= size)
            {
                // Jika input valid, maka cari key dari readyItems (chosenItem)
                valid = true;
                auto it = readyItems.begin();
                advance(it, nomor - 1);

                chosenItem = it->first;
                cout << endl;
            }
            else
            {
                cout << RED << "Pilihan tidak tersedia!" << RESET << endl;
            }
        } while (!valid);

        valid = false;
        int availableSlots = inventory.countEmptySlot();
        int numPanen;
        do
        {
            cout << "Berapa petak yang ingin dipanen: ";
            cin >> numPanen;
            if (cin.fail())
            {
                cout << RED << "Masukkan angka!" << RESET << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (numPanen < 0 || numPanen > get<1>(readyItems[chosenItem]))
            {
                cout << RED << "Masukkan jumlah yang benar!" << RESET << endl;
            }
            else if (numPanen > availableSlots)
            {
                throw InventoryFullException();
            }
            else
            {
                valid = true;
            }
        } while (!valid);

        cout << endl
             << "Pilih petak yang ingin dipanen:" << endl;
        // Validasi format dan lokasi petak
        int i = 0;
        vector<string> possibleLocations = get<0>(readyItems[chosenItem]);
        vector<string> chosenLocations;
        while (i < numPanen)
        {
            string location = getValidInputStorage("Petak ke-" + to_string(i + 1));
            // cari apakah element ada pada list
            auto it = find(possibleLocations.begin(), possibleLocations.end(), location);
            if (it != possibleLocations.end())
            {
                auto iter = find(chosenLocations.begin(), chosenLocations.end(), location);
                // Sudah ada element pada pilihan sebelumnya
                if (iter != chosenLocations.end())
                {
                    cout << RED << "Masukkan petak yang belum pernah dipilih!" << RESET << endl;
                }
                else
                {
                    chosenLocations.push_back(location);
                    i++;
                }
            }
            else
            {
                cout << RED << "Masukkan petak yang tepat!" << RESET << endl;
            }
        }

        // Konversi
        int colP, rowP;
        for (int i = 0; i < chosenLocations.size(); i++)
        {
            colP = getColStorage(chosenLocations[i][0]);
            rowP = getRowStorage(chosenLocations[i]);

            Tanaman *tanaman = &(ladang.deleteAt(rowP, colP));
            Sellable *newItem = nullptr;

            *tanaman >> newItem;
            inventory + *newItem;

            delete tanaman;
        }

        // Message terakhir
        cout << endl
             << GREEN
             << numPanen << " petak tanaman " << chosenItem << " pada petak ";

        // Tampilkan lokasi ladang yang dipanen
        for (i = 0; i < chosenLocations.size(); i++)
        {
            if (i == chosenLocations.size() - 1)
            {
                cout << chosenLocations[i];
            }
            else
            {
                cout << chosenLocations[i] << ", ";
            }
        }
        cout << " telah dipanen!" << RESET << endl;
    }
    else
    {
        throw NotEnoughPanenException();
    }
}

void Petani::cetakLadang()
{
    display(ladang);
    cout << endl
         << endl;
    if (!ladang.isEmpty())
    {
        displayItems(ladang);
        cout << endl;
    }
}

void Petani::addPlantAge()
{
    for (int i = 0; i < ladang.getRow(); i++)
    {
        for (int j = 0; j < ladang.getCol(); j++)
        {
            Tanaman *tanaman = ladang.getElementAddress(i, j);
            if (tanaman != nullptr)
            {
                tanaman->setAge(tanaman->getAge() + 1);
            }
        }
    }
}

int Petani::countTanamanInventory()
{
    int count = 0;
    for (int i = 0; i < inventory.getRow(); i++)
    {
        for (int j = 0; j < inventory.getCol(); j++)
        {
            Sellable *item = inventory.getElementAddress(i, j);
            if (item != nullptr)
            {
                if (item->getJenis() == "TANAMAN")
                {
                    count++;
                }
            }
        }
    }
    return count;
}

int Petani::getKekayaan()
{
    int count = Pemain::getKekayaan();
    for (int i = 0; i < ladang.getRow(); i++)
    {
        for (int j = 0; j < ladang.getCol(); j++)
        {
            Tanaman *item = ladang.getElementAddress(i, j);
            if (item != nullptr)
            {
                count += item->getHargaBarang();
            }
        }
    }
    return count;
}

int Petani::getKKP()
{
    return getKekayaan() - 13;
}
string Petani::getRole() const
{
    return "Petani";
}

int Petani::getUkuranLadangN()
{
    return ladang_n;
}

int Petani::getUkuranLadangM()
{
    return ladang_m;
}

void Petani::setUkuranLadangN(int n)
{
    ladang_n = n;
}

void Petani::setUkuranLadangM(int m)
{
    ladang_m = m;
}

template <>
void display<Tanaman>(const Storage<Tanaman> &storage)
{
    cout << endl;
    // ================[ Penyimpanan ]==================
    cout << "     ";
    int numOfEq = (1 + 6 * storage.col - 10) / 2; // 10 is len([ Ladang ])
    for (int i = 0; i < numOfEq; i++)
    {
        cout << "=";
    }
    cout << "[ Ladang ]";
    for (int i = 0; i < numOfEq; i++)
    {
        cout << "=";
    }
    cout << endl;

    // Print the letters for each column
    cout << "     ";
    for (char c = 'A'; c < 'A' + storage.col; ++c)
    {
        cout << "   " << c << "  ";
    }
    cout << " " << endl;

    for (int i = 0; i < storage.col; ++i)
    {
        if (i == 0)
        {
            cout << "     +";
        }
        cout << "-----+";
    }
    cout << endl;
    for (int i = 0; i < storage.row; ++i)
    {
        cout << "  " << intToStringWithLeadingZero(i + 1) << " |";
        for (int j = 0; j < storage.col; ++j)
        {
            cout << " ";
            string keluaran = "";
            if (storage.buffer[i][j] != nullptr)
            {
                keluaran = (*storage.buffer[i][j]).getKodeHuruf();
                if ((storage.buffer[i][j])->isHarvestValid())
                {
                    print_green(keluaran[0]);
                    print_green(keluaran[1]);
                    print_green(keluaran[2]);
                }
                else
                {
                    print_red(keluaran[0]);
                    print_red(keluaran[1]);
                    print_red(keluaran[2]);
                }
            }
            if (keluaran == "")
            {
                cout << "   ";
            }
            cout << " |";
        }
        cout << endl;
        cout << "     +";
        for (int j = 0; j < storage.col; ++j)
        {
            cout << "-----+";
        }
        cout << endl;
    }
}

template <>
map<string, tuple<vector<string>, int>> readyPanen<Tanaman>(const Storage<Tanaman> &storage)
{
    map<string, tuple<vector<string>, int>> result;
    for (int i = 0; i < storage.row; i++)
    {
        for (int j = 0; j < storage.col; j++)
        {
            Tanaman *item = storage.buffer[i][j];
            if (item != nullptr)
            {
                // klo dah siap panen
                if (item->isHarvestValid())
                {
                    string kode = item->getKodeHuruf();

                    // cari udah ada di map ato blom
                    auto it = result.find(kode);
                    if (it == result.end())
                    {
                        vector<string> position = {intToAlphabet(j) + intToStringWithLeadingZero(i + 1)};
                        result[kode] = make_tuple(position, 1);
                    }
                    else
                    {
                        auto &value = it->second;
                        get<0>(value).push_back(intToAlphabet(j) + intToStringWithLeadingZero(i + 1));
                        get<1>(value)++;
                    }
                }
            }
        }
    }
    return result;
}

template <>
void displayItems<Tanaman>(const Storage<Tanaman> &storage)
{
    set<map<string, string>> Items;
    for (const auto &innerVector : storage.buffer)
    {
        for (Tanaman *value : innerVector)
        {
            if (value != nullptr)
            {
                map<string, string> itemMap;
                if (value != nullptr)
                {
                    itemMap[value->getKodeHuruf()] = value->getNamaBarang();
                    Items.insert(itemMap);
                }
            }
        }
    }
    for (const auto &item : Items)
    {
        for (const auto &pair : item)
        {
            std::cout << " - " << pair.first << ": " << pair.second << endl;
        }
    }
}

void Petani::setLadang(const Storage<Tanaman> &storage)
{
    ladang = storage;
}

Storage<Tanaman> Petani::getLadang() {
    return ladang;
}


void Petani::azab()
{
    if (!ladang.isEmpty())
    {
        string namaTanaman;
        bool found = false;
        for (int i = 0; i < ladang.getRow(); i++)
        {
            for (int j = 0; j < ladang.getCol(); j++)
            {
                Tanaman *item = ladang.getElementAddress(i, j);
                if (item != nullptr)
                {
                    namaTanaman = item->getNamaBarang();
                    ladang.deleteAt(i, j);
                    delete item;
                    found = true;
                    break; 
                }
            }
            if (found) 
                break;
        }
        cout << endl;
        cout << BOLD << "NAKAL KAMU " << CYAN << name << RESET << MAGENTA << endl;
        cout << "Wakwaw dewa siwa marah!!! Tanaman " << BOLD << namaTanaman << RESET << MAGENTA << " kena serangan hama!!" << RESET << endl;
        cout << MAGENTA << "ヾ(￣▽￣) Bye~Bye~ " << namaTanaman << RESET << endl;
    }
    else
    {
        cout << endl;
        cout << YELLOW << "Tadinya " << BOLD << name << RESET << YELLOW <<  " membuat dewa siwa marah!!,\nnamun karena " << name << " tidak memiliki tanaman lagi dewa siwa kasian ○( ＾皿＾)っ Hehehe…\n" << name << " tidak terkena apa apa" << RESET << endl;
    }
}