#ifndef PRODUCT_TANAMAN_MATERIAL_HPP
#define PRODUCT_TANAMAN_MATERIAL_HPP

#include "../Produk.hpp"

/*<ID> <KODE_HURUF> <NAME> <TYPE> <ORIGIN> <ADDED_WEIGHT> <PRICE>*/
class ProdukTanamanMaterial : public Produk
{
private:
    const static string tipe_produk_tanaman_material;

public:
    // ctor default
    ProdukTanamanMaterial();

    // ctor user defined
    ProdukTanamanMaterial(int id, string kode, string nama_produk, string tipe, string origin, int added_weight, int harga);

    // operator overloading
    ProdukTanamanMaterial &operator=(const ProdukTanamanMaterial &other);

    // dtor
    ~ProdukTanamanMaterial();

    // Clone
    Sellable *Clone();

    /* Methods */
    // getter
    string getJenis();
};

#endif
