#include "Pemain.hpp"
#include "../Utils/utils.hpp"

Pemain::Pemain(string name, int gulden, int berat): name(name), gulden(gulden), berat(berat), inventory(inventory_n, inventory_m) {}

Pemain::~Pemain(){}

int Pemain::getGulden() const
{
    return this->gulden;
}

int Pemain::getBerat() const
{
    return this->berat;
}

string Pemain::getName() const
{
    return this->name;
}

void Pemain::setName(string name) 
{
    this->name = name;
}

void Pemain::setGulden(int gulden)
{
    this->gulden = gulden;
}

void Pemain::setBerat(int berat){
    this->berat = berat;
}

void Pemain::makan()
{
    cetakPenyimpanan();
    bool valid= false;
    string slot;

    do
    {
        slot = getValidInputStorage("Slot");

        int col = getColStorage(slot[0]);
        int row = getRowStorage(slot);
        
        Sellable* item = inventory.getElement(row,col);
        if (item->isEdible()){
            inventory.deleteAt(row,col);
            int addedWeight = item->getAddedWeight();

            setBerat(getBerat()-addedWeight);
            valid = true;

        } else if (!item->isEdible()) {
            cout << "Apa yang kamu lakukan??!! Kamu mencoba untuk memakan itu?!!" << endl;
            cout << "Silahkan masukan slot yang berisi makanan." << endl << endl;

        } else if (item == nullptr ){
            cout << "Kamu mengambil harapan kosong dari penyimpanan." << endl;
            cout << "Silahkan masukan slot yang berisi makanan." << endl << endl;
        }
    } while (!valid);
    
}

void Pemain::next(){}

void Pemain::cetakPenyimpanan(){

}

void Pemain::pungutPajak()
{
    throw InvalidCommandException();
}

void Pemain::cetakLadang()
{
    throw InvalidCommandException();
}

void Pemain::cetakPeternakan()
{
    
}

void Pemain::tanam()
{
    throw InvalidCommandException();
}

void Pemain::ternak()
{
    throw InvalidCommandException();
}

void Pemain::bangun()
{
    throw InvalidCommandException();
}

void Pemain::kasihMakan()
{
    throw InvalidCommandException();
}


void Pemain::panen()
{
    throw InvalidCommandException();
}

void Pemain::tambahPemain()
{
    throw InvalidCommandException();
}