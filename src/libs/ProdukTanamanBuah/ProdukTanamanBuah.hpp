#ifndef PRODUCT_TANAMAN_BUAH_HPP
#define PRODUCT_TANAMAN_BUAH_HPP

#include "../Produk/Produk.hpp"
#include "../Tanaman/Tanaman.hpp"

/*<ID> <KODE_HURUF> <NAME> <TYPE> <ORIGIN> <ADDED_WEIGHT> <PRICE>*/
class ProdukTanamanBuah : public Produk
{
private:
    const string tipe = "PRODUCT_FRUIT_PLANT";

public:
    // ctor default
    ProdukTanamanBuah();

    // ctor user defined
    ProdukTanamanBuah(int jenis_sellable, int id, string kode, string nama_produk, string origin, int added_weight, int harga);

    ProdukTanamanBuah &operator=(const ProdukTanamanBuah &other);

    // dtor
    ~ProdukTanamanBuah();

    /* Methods */
    // Konversi tanaman menjadi produk (buah) kalau weight sudah mencapai weight_to_harvest
    ProdukTanamanBuah tambahProdukTanamanBuah(Tanaman &tanaman);
};

#endif
