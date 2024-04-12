#ifndef PRODUCT_TANAMAN_BUAH_HPP
#define PRODUCT_TANAMAN_BUAH_HPP

#include "../Produk.hpp"
#include "../../Tanaman/Tanaman.hpp"

/*<ID> <KODE_HURUF> <NAME> <TYPE> <ORIGIN> <ADDED_WEIGHT> <PRICE>*/
class ProdukTanamanBuah : public Produk
{
private:
    const static string tipe_produk_tanaman_buah;

public:
    // ctor default
    ProdukTanamanBuah();

    // ctor user defined
    ProdukTanamanBuah(int id, string kode, string nama_produk, string tipe, string origin, int added_weight, int harga);

    ProdukTanamanBuah &operator=(const ProdukTanamanBuah &other);

    // dtor
    ~ProdukTanamanBuah();

    /* Methods */
    // getter   
    string getJenis();
    bool isEdible() override;
    
    // Konversi tanaman menjadi produk (buah) kalau weight sudah mencapai weight_to_harvest
    vector<ProdukTanamanBuah> tambahProdukTanamanBuah(Tanaman &tanaman);
};

#endif
