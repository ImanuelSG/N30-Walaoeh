#ifndef PRODUCT_TANAMAN_BUAH_HPP
#define PRODUCT_TANAMAN_BUAH_HPP

#include "../Produk/Produk.hpp"

class ProdukTanamanBuah : public Produk
{
public:
    // ctor user defined
    ProdukTanamanBuah(int id, const string &kode, const string &nama_produk, int harga, const string &origin, int added_weight);

    // dtor
    ~ProdukTanamanBuah();
};

#endif
