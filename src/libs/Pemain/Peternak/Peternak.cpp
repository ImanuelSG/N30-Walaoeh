#include "Peternak.hpp"

int Peternak::ternak_n = 0;
int Peternak::ternak_m = 0;

Peternak::Peternak(string name, int gulden, int berat) : Pemain(name, gulden, berat)
{
}

Peternak::~Peternak()
{
}

void Peternak::ternak()
{
}

void Peternak::kasihMakan()
{
}

void Peternak::panen()
{
}

void Peternak::cetakPeternakan()
{
}

void Peternak::beli()
{
}

void Peternak::jual()
{
}

int Peternak::getKKP() const
{
    return this->getKekayaan() - 11;
}
string Peternak::getRole() const
{
    return "Peternak";
}

int Peternak::getUkuranTernakN() {
    return ternak_n;
}

int Peternak::getUkuranTernakM() {
    return ternak_m;
}

void Peternak::setUkuranTernakN(int n) {
    ternak_n = n;
}

void Peternak::setUkuranTernakM(int m) {
    ternak_m = m;
}