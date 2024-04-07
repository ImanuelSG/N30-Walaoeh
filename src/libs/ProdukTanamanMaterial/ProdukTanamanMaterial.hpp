#ifndef PRODUCT_TANAMAN_MATERIAL_HPP
#define PRODUCT_TANAMAN_MATERIAL_HPP

#include "../Produk/Produk.hpp"

class ProdukTanamanMaterial : public Produk
{
public:
    // ctor user defined
    ProdukTanamanMaterial(int id, const string &kode, const string &nama_produk, int harga, const string &origin, int added_weight);

    // dtor
    ~ProdukTanamanMaterial();
};

#endif
