#ifndef PRODUCT_TANAMAN_MATERIAL_HPP
#define PRODUCT_TANAMAN_MATERIAL_HPP

#include "../Produk/Produk.hpp"
#include "../Tanaman/Tanaman.hpp"

/*<ID> <KODE_HURUF> <NAME> <TYPE> <ORIGIN> <ADDED_WEIGHT> <PRICE>*/
class ProdukTanamanMaterial : public Produk
{
private:
    const static string tipe_produk_tanaman_material;

public:
    // ctor default
    ProdukTanamanMaterial();

    // ctor user defined
    ProdukTanamanMaterial(int jenis_sellable, int id, string kode, string nama_produk, string tipe, string origin, int added_weight, int harga);

    ProdukTanamanMaterial &operator=(const ProdukTanamanMaterial &other);

    // dtor
    ~ProdukTanamanMaterial();

    /* Methods */
    // getter
    string getJenis();
    
    // Konversi tanaman menjadi produk (material) kalau weight sudah mencapai weight_to_harvest
    ProdukTanamanMaterial tambahProdukTanamanMaterial(Tanaman &tanaman);
};

#endif
