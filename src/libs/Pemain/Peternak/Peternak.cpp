#include "Peternak.hpp"
#include "../Utils/utils.hpp"


Peternak::Peternak(string name,int gulden, int berat) : Pemain(name,gulden,berat), peternakan(ternak_n,ternak_m) {}

Peternak::~Peternak(){}

void Peternak::ternak(){
    // Kalau peternakan full
    if (peternakan.isFull()){
        throw StorageFullException();
    }
    // Kalau di inventory gak punya hewan
    if (countHewanInventory()==0){
        throw NotEnoughHewanException();
    }

    cout << "Pilih hewan dari penyimpanan" << endl;
    cetakPenyimpananHewan();
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
         
        item = inventory.getElement(row,col);
        if (item->isHewan()){
            valid = true;
        }
        else
        {
            cout << "Barang pada slot tersebut bukanlah Hewan.\n Silakan pilih Slot lain!\n";
        }
    } while (!valid); 

    cout << "Pilih petak tanah yang akan ditinggali" << endl;

    cetakPeternakan();

    bool isEmpty = false;
    string petak;
    int colP = 0;
    int rowP = 0;

    // validasi kosong ato gak
    do 
    {
        petak = getValidInputStorage("Petak tanah");

        colP = getColStorage(petak[0]);
        rowP = getRowStorage(petak);

        // Hewan* item = new peternakan.getElement(row,col);
        // if (item == nullptr){
        //     isEmpty = true;
        // }
        


    } while (!isEmpty);

    
    




}

void Peternak::kasihMakan(){}

void Peternak::panen() {}

void Peternak::cetakPeternakan() {}

void Peternak::beli(){}

void Peternak::jual(){}

void Peternak::cetakPenyimpananHewan(){}

int Peternak::countHewanInventory(){}


