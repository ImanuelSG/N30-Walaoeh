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

int Petani::getUkuranLadangN() {
    return ladang_n;
}

int Petani::getUkuranLadangM() {
    return ladang_m;
}

void Petani::setUkuranLadangN(int n) {
    ladang_n = n;
}

void Petani::setUkuranLadangM(int m) {
    ladang_m = m;
}