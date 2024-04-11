#include "Petani.hpp"
#include "../../pcolor/pcolor.h"


int Petani::ladang_m = 0; int Petani::ladang_n = 0;
Petani::Petani(string name, int gulden, int berat) : Pemain(name, gulden, berat), ladang(ladang_n,ladang_m) 
{
}

Petani::~Petani()
{
}

void Petani::tanam()
{
    if (ladang.isFull()){
        throw TernakFullException();
    }

    if (countTanamanInventory()==0){
        throw NotEnoughTanamanException();
    }

}

void Petani::panen()
{
}

void Petani::cetakLadang()
{
    display(ladang);
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