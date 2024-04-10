#include "Peternak.hpp"

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

int Peternak::getKKP()
{
    return this->getKekayaan() - 11;
}
string Peternak::getRole() const
{
    return "Peternak";
}
