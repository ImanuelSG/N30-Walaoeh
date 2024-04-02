#ifndef PETANI_HPP
#define PETANI_HPP

#include <memory>
#include "Pemain.hpp"
#include "Tanaman.hpp"

using namespace std;

class Petani : public Pemain
{
public:
    Petani(const string &nama) : Pemain(nama) {}
    void Tanaman(shared_ptr<Tanaman> tanaman);
    void PanenTanaman();
};

#endif
