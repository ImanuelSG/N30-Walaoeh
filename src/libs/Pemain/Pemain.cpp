#include "Pemain.hpp"

Pemain::Pemain(string name, int gulden, int berat)
{
    this->name = name;
    this->gulden = gulden;
    this->berat = berat;
}

Pemain::~Pemain()
{
    for (auto item : this->inventory)
    {
        delete item;
    }
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

void Pemain::setName()
{
    this->name = name;
}
void Pemain::setGulden(int num)
{
    this->gulden = num;
}

void Pemain::setBerat(int num)
{
    this->berat = num;
}

int Pemain::getKekayaan() const
{
    int kekayaan = 0;
    for (auto item : this->inventory)
    {
        kekayaan += item->getHargaBarang();
    }

    return kekayaan + this->getGulden();
}

void Pemain::next()
{
}

void Pemain::pungutPajak(const vector<Pemain *> &pemain)
{
    throw WalikotaInputException();
}
void Pemain::cetakLadang() {}
void Pemain::cetakPeternakan() {}
void Pemain::tanam() {}
void Pemain::ternak() {}

void Pemain::bangunBangunan()
{
    throw WalikotaInputException();
}
void Pemain::kasihMakan()
{
}
void Pemain::beli() {}
void Pemain::jual() {}
void Pemain::panen() {}

void Pemain::makan()
{
}

void Pemain::cetakPenyimpanan()
{
}
int Pemain::tambahPemain(vector<Pemain *> &pemain)
{
    throw WalikotaInputException();
}

int Pemain::getKKP()
{
    return 0;
}
