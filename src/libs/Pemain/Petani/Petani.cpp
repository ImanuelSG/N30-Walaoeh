#include "Petani.hpp"

Petani::Petani(string name, int gulden, int berat) : Pemain(name, gulden, berat)
{
}

Petani::~Petani()
{
}

void Petani::tanam()
{
}

void Petani::panen()
{
}

void Petani::cetakLadang()
{
}

void Petani::beli()
{
}

void Petani::jual()
{
}

int Petani::getKKP() const
{
    return this->getKekayaan() - 13;
}
string Petani::getRole() const
{
    return "Petani";
}