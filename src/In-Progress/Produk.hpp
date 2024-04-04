#ifndef PRODUK_HPP
#define PRODUK_HPP

#include "Sellable.hpp"

class Produk : public Sellable
{
private:
    string tipe_produk;
    string origin;
    int added_weight;

public:
    // ctor default
    Produk();

    // ctor user defined
    Produk(int id, string kode, string nama_produk, int harga, string tipe, string origin, int added_weight);

    // operator overloading
    Produk &operator=(const Produk &other);

    // cctor
    Produk(const Produk &other);

    // dtor
    ~Produk();
};

#endif
