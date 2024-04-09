#include "Pemain.hpp"

Pemain::Pemain(string name, int gulden, int berat)
{
    this->name = name;
    this->gulden = gulden;
    this->berat = berat;
}
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