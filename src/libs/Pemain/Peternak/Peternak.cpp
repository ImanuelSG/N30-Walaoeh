#include "Peternak.hpp"
#include "../../Utils/utils.hpp"


Peternak::Peternak(string name,int gulden, int berat) : Pemain(name,gulden,berat), peternakan(ternak_n,ternak_m) {}

Peternak::~Peternak(){}

void Peternak::ternak(){
    // Kalau peternakan full
    if (peternakan.isFull()){
        throw TernakFullException();
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
         
        item = inventory.getElementAddress(row,col);
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
    Hewan *cekPetak = nullptr; 

    // validasi kosong ato gak
    do 
    {
        petak = getValidInputStorage("Petak tanah");

        colP = getColStorage(petak[0]);
        rowP = getRowStorage(petak);

        cekPetak = peternakan.getElementAddress(rowP,colP);
        if (cekPetak == nullptr){
            isEmpty = true;

        } else {
            cout << "Petak yang anda pilih tidak kosong.\n Silakan pilih petak kosong." << endl;
        }

    } while (!isEmpty);
    

    // Petak dipilih sudah kosong

    Hewan *hewan = dynamic_cast<Hewan*>(item);
    peternakan.insert(rowP,colP,*hewan);
    inventory.deleteAt(row,col);

    cout << "Dengan hati-hati, kamu meletakkan seekor " << item->getNamaBarang() << " di kandang." << endl << endl;
    cout << item->getNamaBarang() << "telah menjadi peliharaanmu sekarang!";


}

void Peternak::kasihMakan()
{
    if (peternakan.isEmpty()){
        throw TernakEmptyException();
    }
    // klo gak ada makanannya beri pesan aja
    cetakPeternakan();
    bool isEmpty = false;
    string petak;
    int colP = 0;
    int rowP = 0;
    Hewan *cekPetak = nullptr; 

    // validasi kosong ato gak
    do 
    {
        petak = getValidInputStorage("Petak tanah");

        colP = getColStorage(petak[0]);
        rowP = getRowStorage(petak);

        cekPetak = peternakan.getElementAddress(rowP,colP);
        if (cekPetak == nullptr){
            isEmpty = true;

        } else {
            cout << "Petak yang anda pilih tidak kosong.\n Silakan pilih petak kosong." << endl;
        }

    } while (!isEmpty);



}

void Peternak::panen() {}

void Peternak::cetakPeternakan() {}

void Peternak::beli(){}

void Peternak::jual(){}

void Peternak::cetakPenyimpananHewan(){}

int Peternak::countHewanInventory(){}

int Peternak::getKKP() const
{
    return this->getKekayaan() - 11;
}
string Peternak::getRole() const
{
    return "Peternak";
}
