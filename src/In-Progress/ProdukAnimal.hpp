#ifndef PRODUKANIMAL_HPP
#define PRODUKANIMAL_HPP

#include "Produk.hpp"

class ProdukAnimal : public Produk
{
private:
    string tipe_produk;
    string origin;
    int added_weight;

public:
    // ctor default
    ProdukAnimal();

    // ctor user defined
    ProdukAnimal(string tipe, string origin, int weight);

    // operator overloading
    ProdukAnimal &operator=(const ProdukAnimal &produk);

    // cctor
    ProdukAnimal(const ProdukAnimal &produk);

    // dtor
    ~ProdukAnimal();
};

#endif
