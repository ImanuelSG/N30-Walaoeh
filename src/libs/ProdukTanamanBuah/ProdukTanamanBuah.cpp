#include "ProdukTanamanBuah.hpp"

// class ProdukTanamanBuah : public Produk
// ctor user defined
ProdukTanamanBuah::ProdukTanamanBuah(int id, const string &kode, const string &nama_produk, int harga, const string &origin, int added_weight)
    : Produk(id, kode, nama_produk, harga, "PRODUCT_FRUIT_PLANT", origin, added_weight)
{
}

// dtor
ProdukTanamanBuah::~ProdukTanamanBuah() {}