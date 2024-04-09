#ifndef PRODUK_HEWAN_HPP
#define PRODUK_HEWAN_HPP

#include "../Produk/Produk.cpp"
#include "../Hewan/Hewan.cpp"

// #include "../Sellable/Sellable.cpp"

/*<ID> <KODE_HURUF> <NAME> <TYPE> <ORIGIN> <ADDED_WEIGHT> <PRICE>*/
class ProdukHewan : public Produk
{

private:
    const string tipe = "PRODUCT_ANIMAL";

public:
    // ctor default
    ProdukHewan();

    // ctor user defined
    ProdukHewan(int id, string kode, string nama_produk, string tipe, string origin, int added_weight, int harga);

    // operator overloading
    ProdukHewan &operator=(const ProdukHewan &other);

    // dtor
    ~ProdukHewan();

    /* Methods */
    /*
    1. Herbivora
    Cow -> 1 Cow Meat
    Sheep -> 1 Sheep Meat
    Horse -> 1 Horse Meat
    Rabbit -> 1 Rabbit Meat

    2. Karnivora
    Snake -> 1 Snake Meat

    3. Omnivora
    Chicken -> 1 Chicken Meat & 1 Chicken Egg
    Duck -> 1 Duck Meat & 1 Duck Egg
    */

    // Konversi hewan menjadi produk (hewan) kalau weight sudah mencapai weight_to_harvest
    ProdukHewan tambahProdukHewanHerbivora(Hewan &hewan);
    ProdukHewan tambahProdukHewanKarnivora(Hewan &hewan);
    static pair<ProdukHewan, ProdukHewan> tambahProdukHewanOmnivora(Hewan& hewan);

    // static method
    static ProdukHewan tambahProdukHewan(ifstream &file);

};

#endif
