#include "Pemain.hpp"

Pemain::Pemain(string name, int gulden, int berat): name(name), gulden(gulden), berat(berat), inventory(inventory_n, inventory_m) {}

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

    } while ()
    
    


}

void Pemain::next(){}

void Pemain::cetakPenyimpanan(){}

void Pemain::pungutPajak()
{
    throw InvalidCommandException();
}

void Pemain::cetakLadang()
{
    throw InvalidCommandException();
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