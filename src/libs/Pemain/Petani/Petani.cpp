#include "Petani.hpp"


int Petani::ladang_m = 0; int Petani::ladang_n = 0;
Petani::Petani(string name, int gulden, int berat) : Pemain(name, gulden, berat), ladang(ladang_n,ladang_m) 
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