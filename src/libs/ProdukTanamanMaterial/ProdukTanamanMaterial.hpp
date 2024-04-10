#ifndef PRODUCT_TANAMAN_MATERIAL_HPP
#define PRODUCT_TANAMAN_MATERIAL_HPP

#include "../Produk/Produk.hpp"
#include "../Tanaman/Tanaman.hpp"

/*<ID> <KODE_HURUF> <NAME> <TYPE> <ORIGIN> <ADDED_WEIGHT> <PRICE>*/
class ProdukTanamanMaterial : public Produk
{
private:
    const string tipe = "PRODUCT_MATERIAL_PLANT";

public:
    // ctor default
    ProdukTanamanMaterial();

    // ctor user defined
    ProdukTanamanMaterial(int jenis_sellable, int id, string kode, string nama_produk, string origin, int added_weight, int harga);

    ProdukTanamanMaterial &operator=(const ProdukTanamanMaterial &other);

    // dtor
    ~ProdukTanamanMaterial();

    /* Methods */
    // Konversi tanaman menjadi produk (material) kalau weight sudah mencapai weight_to_harvest
    ProdukTanamanMaterial tambahProdukTanamanMaterial(Tanaman &tanaman);
};

#endif
