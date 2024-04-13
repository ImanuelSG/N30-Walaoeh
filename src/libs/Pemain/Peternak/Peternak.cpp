#include <algorithm>
#include "Peternak.hpp"
#include "../../Utils/Utils.hpp"
#include "../../pcolor/pcolor.h"
#include "../../Toko/Sellable/Produk/ProdukHewan/ProdukHewan.hpp"

int Peternak::ternak_m = 5;
int Peternak::ternak_n = 5;
Peternak::Peternak(string name, int gulden, int berat) : Pemain(name, gulden, berat), peternakan(ternak_n, ternak_m) {}
Peternak::~Peternak() {}

void Peternak::ternak()
{
    // Kalau peternakan full
    if (peternakan.isFull())
    {
        throw TernakFullException();
    }
    // Kalau di inventory gak punya hewan
    if (countHewanInventory() == 0)
    {
        throw NotEnoughHewanException();
    }
    cout << endl;
    cout << "Pilih hewan dari penyimpanan" << endl;
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

            if (col < 0 || col > inventory.getCol() || row < 0 || row > inventory.getRow())
            {
                cout << "Masukkan lokasi petak yang sesuai!" << endl;
            }
            else
            {
                acc = true;
            }

        } while (!acc);

        item = inventory.getElementAddress(row, col);

        if (item != nullptr)
        {
            if (item->getJenis() == "HEWAN")
            {
                valid = true;
            }
            else
            {
                cout << "Barang pada slot tersebut bukanlah Hewan.\n Silakan pilih Slot lain!\n";
            }
        }
    } while (!valid);

    cout << "Kamu memilih " << item->getNamaBarang() << "." << endl;
    cout << "Pilih petak tanah yang akan ditinggali" << endl;

    display(peternakan);

    valid = false;
    string petak;
    int colP = 0;
    int rowP = 0;
    Hewan *cekPetak;

    // validasi kosong ato gak
    do
    {
        bool acc = false;
        do
        {
            slot = getValidInputStorage("Petak tanah");

            colP = getColStorage(slot[0]);
            rowP = getRowStorage(slot);

            if (colP < 0 || colP > peternakan.getCol() || rowP < 0 || rowP > peternakan.getRow())
            {
                cout << "Masukkan lokasi petak yang sesuai!" << endl;
            }
            else
            {
                acc = true;
            }

        } while (!acc);

        cekPetak = peternakan.getElementAddress(rowP, colP);
        if (cekPetak == nullptr)
        {
            valid = true;
        }
        else
        {
            cout << "Petak yang anda pilih tidak kosong.\n Silakan pilih petak kosong." << endl;
        }

    } while (!valid);

    // Petak dipilih sudah kosong

    Hewan *hewan = dynamic_cast<Hewan *>(item);
    peternakan.insert(rowP, colP, *hewan);
    inventory.deleteAt(row, col);

    cout << "Dengan hati-hati, kamu meletakkan seekor " << item->getNamaBarang() << " di kandang." << endl
         << endl;
    cout << item->getNamaBarang() << " telah menjadi peliharaanmu sekarang!";
}

void Peternak::kasihMakan()
{
    if (peternakan.isEmpty())
    {
        throw TernakEmptyException();
    }
    cout << endl;
    cout << "Pilih petak kandang yang akan diberi makan" << endl
         << endl;
    display(peternakan);
    bool isEmpty = true;
    string petak;
    int colP = 0;
    int rowP = 0;
    Hewan *hewan;

    // validasi kosong ato gak
    do
    {
        bool acc = false;
        do
        {
            petak = getValidInputStorage("Petak Kandang");

            colP = getColStorage(petak[0]);
            rowP = getRowStorage(petak);

            if (colP < 0 || colP > peternakan.getCol() || rowP < 0 || rowP > peternakan.getRow())
            {
                cout << "Masukkan lokasi petak yang sesuai!" << endl;
            }
            else
            {
                acc = true;
            }

        } while (!acc);

        hewan = peternakan.getElementAddress(rowP, colP);
        if (hewan == nullptr)
        {
            cout << "Petak yang anda pilih kosong.\n Silakan pilih petak tidak kosong." << endl;
        }
        else
        {
            isEmpty = false;
        }

    } while (isEmpty);

    cout << "Kamu memilih " << hewan->getKodeHuruf() << " untuk diberi makan.\n"
         << endl;

    string tipeHewan = hewan->getTipeHewan();
    // cek ada makanan tipe itu atau gak
    if (isMakananAvailable(tipeHewan))
    {
        cout << "Pilih pangan yang akan diberikan: " << endl;
        display(inventory);

        bool acc = false;
        int col = 0;
        int row = 0;
        do
        {
            string slot = getValidInputStorage("Slot");

            col = getColStorage(slot[0]);
            row = getRowStorage(slot);

            if (col < 0 || col > inventory.getCol() || row < 0 || row > inventory.getRow())
            {
                cout << "Masukkan lokasi petak yang sesuai!" << endl;
            }
            else
            {
                acc = true;
            }

        } while (!acc);

        Sellable *item = inventory.getElementAddress(row, col);
        if (item != nullptr)
        {

            if ((item->getJenis() == "PRODUK_HEWAN") || (item->getJenis() == "PRODUK_TANAMAN_BUAH"))
            {
                if ((hewan->isCarnivore() && (item->getJenis() == "PRODUK_HEWAN")) || (hewan->isHerbivore() && (item->getJenis() == "PRODUK_TANAMAN_BUAH")) || (hewan->isOmnivore() && ((item->getJenis() == "PRODUK_TANAMAN_BUAH") || (item->getJenis() == "PRODUK_HEWAN"))))
                {
                    // tambah berat
                    hewan->setWeight(hewan->getWeight() + item->getAddedWeight());
                    cout << hewan->getKodeHuruf() << " sudah diberi makan dan beratnya menjadi " << hewan->getWeight() << endl;
                    // hapus barang dri inventory
                    inventory.deleteAt(row, col);
                }
                else
                {
                    throw InvalidJenisMakananException();
                }
            }
            else
            {
                throw InvalidProdukException();
            }
        }
        else
        {
            cout << "Anda memilih slot kosong" << endl;
        }
    }
    else
    {
        cout << "Anda tidak memiliki jenis makanan yang sesuai untuk tipe hewan Anda\n"
             << endl;
    }
}

void Peternak::panen()
{
    // cetak ternak
    cout << endl;
    cetakPeternakan();

    auto readyItems = readyPanen(peternakan);
    if (readyItems.size() > 0)
    {
        cout << "Pilih hewan siap panen yang kamu miliki" << endl;

        displayReadyPanen(readyItems);

        string chosenItem;
        bool valid = false;
        int size = readyItems.size();
        int input;
        cout << endl;
        do
        {
            cout << "Nomor hewan yang ingin dipanen: ";
            cin >> input;

            if (cin.fail())
            {
                cout << "Masukkan angka!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (1 <= input && input <= size)
            {
                // Jika input valid, maka cari key dari readyItems (chosenItem)
                valid = true;
                auto it = readyItems.begin();
                advance(it, input - 1);

                chosenItem = it->first;
                cout << endl;
            }
            else
            {
                cout << "Pilihan tidak tersedia!" << endl;
            }

        } while (!valid);

        // sudah dipilih dapet keynya buat map
        vector<string> positions = get<0>(readyItems[chosenItem]);
        int count = get<1>(readyItems[chosenItem]);

        valid = false;
        int num;

        // validasi jumlah petak
        do
        {
            cout << "Berapa petak yang ingin dipanen: ";
            cin >> num;
            if (cin.fail())
            {
                cout << "Masukkan angka!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (num >= 1 && num <= count)
            {
                valid = true;
            }
            else
            {
                cout << "Jumlah petak tidak tersedia.\n Silakan pilih jumlah yang sesuai!" << endl;
            }

        } while (!valid);

        // validasi jumlah penyimpanan cukup atau tidak
        int tempCol = getColStorage(positions[0][0]);
        int tempRow = getRowStorage(positions[0]);

        Hewan *tempHewan = peternakan.getElementAddress(tempRow, tempCol);
        if (tempHewan != nullptr)
        {
            int tambahan = (tempHewan->isOmnivore()) ? (num * 2) : num;
            // inventory gak cukup
            if (((inventory.getNeff() + tambahan) > inventory.getCapacity()))
            {
                throw InventoryFullException();
            }
            // inventory cukup
            else
            {
                // pilih petak
                int iter = 0;
                vector<string> chosenPositions;

                cout << endl
                     << "Pilih petak yang ingin dipanen:" << endl;
                do
                {

                    string slot;
                    slot = getValidInputStorage("Petak ke-" + to_string(iter + 1));

                    auto it = find(positions.begin(), positions.end(), slot);
                    auto it2 = find(chosenPositions.begin(), chosenPositions.end(), slot);

                    // if slot is not available
                    if (it == positions.end())
                    {
                        cout << "Lokasi petak tidak tersedia" << endl;
                    }
                    else if (it2 != chosenPositions.end()) // klo udh pernah diipilh
                    {
                        cout << "Anda sudah memilih petak tersebut" << endl;
                    }
                    else if ((it != positions.end()) && (it2 == chosenPositions.end()))
                    {
                        chosenPositions.push_back(slot);
                        iter++;
                    }

                } while (iter < num);

                // masukin petaknya

                for (int i = 0; i < num; i++)
                {
                    int col = getColStorage(chosenPositions[i][0]);
                    int row = getRowStorage(chosenPositions[i]);

                    Hewan *hewan = peternakan.getElementAddress(row, col);

                    if (hewan->isOmnivore())
                    {
                        Sellable *item = ProdukHewan::tambahProdukHewanOmnivoraDaging(*hewan);
                        Sellable *item2 = ProdukHewan::tambahProdukHewanOmnivoraTelur(*hewan);
                        inventory.insert(*item);
                        inventory.insert(*item2);
                    }
                    else if (hewan->isCarnivore())
                    {
                        Sellable *item = ProdukHewan::tambahProdukHewanKarnivora(*hewan);
                        inventory.insert(*item);
                    }
                    else if (hewan->isHerbivore())
                    {
                        Sellable *item = ProdukHewan::tambahProdukHewanHerbivora(*hewan);
                        inventory.insert(*item);
                    }

                    peternakan.deleteAt(row, col);
                }

                cout << endl
                     << num << " petak hewan " << chosenItem << " pada petak ";
                for (int i = 0; i < chosenPositions.size(); i++)
                {
                    cout << chosenPositions[i];
                    if (i != (chosenPositions.size() - 1))
                    {
                        cout << ",";
                    }
                    cout << " ";
                }
                cout << "telah dipanen!" << endl;
            }
        }
    }
    else
    {
        throw NotEnoughPanenException();
    }
}

void Peternak::cetakPeternakan()
{
    display(peternakan);
    if (!peternakan.isEmpty())
    {
        displayItems(peternakan);
        cout << endl;
    }
}

int Peternak::getKekayaan()
{
    int count = Pemain::getKekayaan();
    for (int i = 0; i < peternakan.getRow(); i++)
    {
        for (int j = 0; j < peternakan.getCol(); j++)
        {
            Hewan *item = peternakan.getElementAddress(i, j);
            if (item != nullptr)
            {
                count += item->getHargaBarang();
            }
        }
    }
    return count;
}

int Peternak::countHewanInventory()
{
    int count = 0;
    for (int i = 0; i < inventory.getRow(); i++)
    {
        for (int j = 0; j < inventory.getCol(); j++)
        {
            Sellable *item = inventory.getElementAddress(i, j);
            if (item != nullptr)
            {
                if (item->getJenis() == "HEWAN")
                {
                    count++;
                }
            }
        }
    }
    return count;
}

bool Peternak::isMakananAvailable(string tipeHewan)
{
    for (int i = 0; i < inventory.getRow(); i++)
    {
        for (int j = 0; j < inventory.getCol(); j++)
        {
            Sellable *item = inventory.getElementAddress(i, j);

            if (item != nullptr)
            {
                if (tipeHewan == "CARNIVORE")
                {
                    if ((item->getJenis() == "PRODUK_HEWAN"))
                    {
                        return true;
                    }
                }
                else if (tipeHewan == "HERBIVORE")
                {
                    if ((item->getJenis() == "PRODUK_TANAMAN_BUAH"))
                    {
                        return true;
                    }
                }
                else if (tipeHewan == "OMNIVORE")
                {
                    if ((item->getJenis() == "PRODUK_HEWAN") || (item->getJenis() == "PRODUK_TANAMAN_BUAH"))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int Peternak::getKKP()
{
    return getKekayaan() - 11;
}
string Peternak::getRole() const
{
    return "Peternak";
}

template <>
void display<Hewan>(const Storage<Hewan> &storage)
{
    // ================[ Penyimpanan ]==================
    cout << "     ";
    int numOfEq = (1 + 6 * storage.col - 14) / 2; // 14 is len([ Peternakan ])
    for (int i = 0; i < numOfEq; i++)
    {
        cout << "=";
    }
    cout << "[ Peternakan ]";
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
                if ((*storage.buffer[i][j]).isHarvestValid())
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
map<string, tuple<vector<string>, int>> readyPanen<Hewan>(const Storage<Hewan> &storage)
{
    map<string, tuple<vector<string>, int>> result;
    for (int i = 0; i < storage.row; i++)
    {
        for (int j = 0; j < storage.col; j++)
        {
            Hewan *item = storage.buffer[i][j];
            if (item != nullptr)
            {
                // klo siap panen
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
void displayItems<Hewan>(const Storage<Hewan> &storage)
{
    set<map<string, string>> Items;
    for (const auto &innerVector : storage.buffer)
    {
        for (Hewan *value : innerVector)
        {
            map<string, string> itemMap;
            if (value != nullptr)
            {
                itemMap[value->getKodeHuruf()] = value->getNamaBarang();
                Items.insert(itemMap);
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

void Peternak::setPeternakan(const Storage<Hewan> &storage)
{
    peternakan = storage;
}

int Peternak::getUkuranTernakN()
{
    return ternak_n;
}

int Peternak::getUkuranTernakM()
{
    return ternak_m;
}

void Peternak::setUkuranTernakN(int n)
{
    ternak_n = n;
}

void Peternak::setUkuranTernakM(int m)
{
    ternak_m = m;
}

void Peternak::azab()
{
    cout << this->getName() << " terkena azab, hewannya kabur" << endl;
}
