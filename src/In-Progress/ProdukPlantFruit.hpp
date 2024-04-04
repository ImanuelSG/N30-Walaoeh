#ifndef PRODUK_HPP
#define PRODUK_HPP

#include "Sellable.hpp"

class Produk
{
private:
    string tipe_produk;
    string origin;
    int added_weight;

public:
    // ctor default
    Produk();

    // ctor user defined
    Produk(string tipe, string origin, int weight);

    // operator overloading
    Produk &operator=(const Produk &produk);

    // cctor
    Produk(const Produk &produk);

    // dtor
    ~Produk();
};

#endif
