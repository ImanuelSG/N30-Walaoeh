#include "Petani.hpp"
#include <set>
#include <algorithm>
#include "../../pcolor/pcolor.h"
#include "../../Utils/Utils.hpp"


int Petani::ladang_m = 5; int Petani::ladang_n = 5;
Petani::Petani(string name, int gulden, int berat) : Pemain(name, gulden, berat), ladang(ladang_n,ladang_m) 
{
}

Petani::~Petani()
{
}

void Petani::tanam()
{
    if (ladang.isFull()){
        throw LadangFullException();
    }

    if (countTanamanInventory()==0){
        throw NotEnoughTanamanException();
    }

    cout << "Pilih tanaman dari penyimpanan" << endl;
    display(inventory);
    bool valid= false;
    string slot;
    int col = 0;
    int row = 0;
    Sellable* item = nullptr;

    // Slot inventory
    do
    {
        slot = getValidInputStorage("Slot");

        col = getColStorage(slot[0]);
        row = getRowStorage(slot);
         
        item = inventory.getElementAddress(row,col);
        if (item->getJenis() == "TANAMAN"){
            valid = true;
        }
        else
        {
            cout << "Barang pada slot tersebut bukanlah Tanaman.\n Silakan pilih Slot lain!\n";
        }
    } while (!valid);
    
    cout << "Kamu memilih " << item->getNamaBarang() << "." << endl;
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
        petak = getValidInputStorage("Petak tanah");

        colP = getColStorage(petak[0]);
        rowP = getRowStorage(petak);

        cekPetak = ladang.getElementAddress(rowP,colP);
        if (cekPetak == nullptr){
            valid = true;

        } else {
            cout << "Petak yang anda pilih tidak kosong.\n Silakan pilih petak kosong." << endl;
        }

    } while (!valid);

    Tanaman *tanaman = dynamic_cast<Tanaman*>(item);
    ladang.insert(rowP,colP,*tanaman);
    inventory.deleteAt(row,col);

    cout << "Cangkul, cangkul, cangkul yang dalam~!" << endl;
    cout << item->getNamaBarang() << " berhasil ditanam!" << endl;

}

void Petani::panen()
{
    cetakLadang();
    cout << "Pilih tanaman siap panen yang kamu miliki" << endl;

    // Dapatkan semua item yang ready untuk dipanen
    map<string, tuple<vector<string>,int>> readyItems = readyPanen(ladang);
    displayReadyPanen(readyItems);

    // Pilihan tanaman yang mau dipanen
    bool valid = false;
    int size = readyItems.size();
    string input;
    string chosenItem;
    cout << endl;
    do
    {
        cout << "Nomor tanaman yang ingin dipanen: ";
        cin >> input;
        if (1 <= stoi(input) <= size)
        {
            // Jika input valid, maka cari key dari readyItems (chosenItem)
            valid = true;
            auto it = readyItems.begin();
            advance(it, stoi(input));

            chosenItem = it->first;
            cout << endl;
        }
        else
        {
            cout << "Pilihan tidak tersedia!" << endl;
        }
    } while (!valid);
    
    valid = false;
    int availableSlots = inventory.countEmptySlot();
    int numPanen;
    do
    {
        cout << "Berapa petak yang ingin dipanen: ";
        cin >> input;
        if (stoi(input) < 0 || stoi(input) > get<1>(readyItems[chosenItem]))
        {
            cout << "Masukkan jumlah yang benar!" << endl;
        }
        if (stoi(input) > availableSlots)
        {
            throw InventoryFullException();
        }
        numPanen = stoi(input);
    } while (!valid);
    
    cout << "Pilih petak yang ingin dipanen:" << endl;
    // Validasi format dan lokasi petak
    int i = 0;
    vector<string> possibleLocations = get<0>(readyItems[chosenItem]);
    vector<string> chosenLocations;
    while (i < numPanen)
    {
        string location = getValidInputStorage("Petak ke-" + to_string(i+1));
        // cari apakah element ada pada list
        auto it = find(possibleLocations.begin(), possibleLocations.end(), location);
        if (it != possibleLocations.end())
        {
            chosenLocations.push_back(location);
            i++;
        }
    }


    // Message terakhir
    cout << endl << numPanen << " petak tanaman " << chosenItem << "pada petak";

    // Konversi
    int colP, rowP;

    for (int i = 0; i < chosenLocations.size(); i++)
    {
        colP = getColStorage(chosenLocations[i][0]);
        rowP = getRowStorage(chosenLocations[i]);

        // Nanti tunggu fungsi tambahProdukTanaman
    }
    

    // Tampilkan lokasi ladang yang dipanen
    for (i = 0; i < chosenLocations.size(); i ++)
    {
        if (i == chosenLocations.size() - 1)
        {
            cout << chosenLocations[i];
        } else
        {
            cout << chosenLocations[i] << ", ";
        }
    }
    cout << " telah dipanen!" << endl;
}

void Petani::cetakLadang()
{
    display(ladang);
    cout << endl << endl;
    if (!ladang.isEmpty())
    {
        displayItems(ladang);
        cout << endl;
    }
}

void Petani::beli()
{
}

void Petani::jual()
{
}

int Petani::countTanamanInventory()
{
    int count = 0;
    for (int i = 0; i < inventory_n; i++) {
        for (int j = 0; j < inventory_m; j++) {
            Sellable* item = inventory.getElementAddress(i,j);
            if (item->getJenis() == "TANAMAN"){
                count++;
            }
        }
    }
    return count;
}

int Petani::getKekayaan()
{
    int count = Pemain::getKekayaan();
    for (int i = 0; i < inventory_n; i++)
    {
        for (int j = 0; j < inventory_m; j++)
        {
            Tanaman* item = ladang.getElementAddress(i, j);
            if (item != nullptr){
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

template<>
void display<Tanaman>(const Storage<Tanaman> &storage)
{
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
                if ((*storage.buffer[i][j]).getDurationToHarvest() - (*storage.buffer[i][j]).getAge() <= 0)
                {
                    print_green(keluaran[0]); print_green(keluaran[1]); print_green(keluaran[2]);
                }
                else{
                    print_red(keluaran[0]); print_red(keluaran[1]); print_red(keluaran[2]);
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

template<>
map<string, tuple<vector<string>,int>> readyPanen<Tanaman>(const Storage<Tanaman> &storage){
    map<string, tuple<vector<string>, int>> result;
    for (int i =0 ;i < storage.row; i++)
    {
        for (int j=0; j < storage.col;j++)
        {
            Tanaman *item = storage.buffer[i][j];
            if (item != nullptr)
            {
                // klo dah siap panen
                if (item->getDurationToHarvest() - item->getAge() <= 0)
                {  
                    string kode = item->getKodeHuruf();

                    // cari udah ada di map ato blom
                    auto it = result.find(kode);
                    if (it == result.end())
                    {
                        vector<string> position = {intToAlphabet(j) + intToStringWithLeadingZero(i)};
                        result[kode] = make_tuple(position,1);
                    } else {
                        auto &value = it->second;
                        get<0>(value).push_back(intToAlphabet(j) + intToStringWithLeadingZero(i));
                        get<1>(value) ++;
                    }
                }
            }
        }
    }
    return result;
}

template<>
void displayItems<Tanaman>(const Storage<Tanaman> &storage)
{
    set<map<string,string>> Items;
    for (const auto& innerVector : storage.buffer)
    {
        for (Tanaman* value : innerVector)
        {
            map<string, string> itemMap;
            itemMap[value->getKodeHuruf()] = value->getNamaBarang();
            Items.insert(itemMap);
        }
    }
    for (const auto& item : Items)
    {
        for (const auto& pair : item)
        {
            std::cout << " - " << pair.first << ": " << pair.second << endl;
        }
    }
}