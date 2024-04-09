#include "Petani.hpp"

Petani::Petani(string name, int gulden, int berat) : Pemain(name, gulden, berat)
{
}

Petani::~Petani()
{
}

string Petani::getRole()
{
    return "Petani";
}