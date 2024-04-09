#ifndef PRODUK_HPP
#define PRODUK_HPP

#include "../Sellable/Sellable.hpp"
#include <vector>

/*<ID> <KODE_HURUF> <NAME> <TYPE> <ORIGIN> <ADDED_WEIGHT> <PRICE>*/
class Produk : public Sellable
{
protected:
    string tipe_produk;
    string origin;
    int added_weight;

public:
    static int id_produk;

    // ctor default
    Produk();

    // ctor user defined
    Produk(int id, string kode, string nama_produk, string tipe, string origin, int added_weight, int harga);

    // operator overloading
    Produk &operator=(const Produk &other);

    // dtor
    virtual ~Produk();

    /* Methods */
    // getter
    static int getIdProduk();
    string getTipeProduk();
    string getOrigin();
    int getAddedWeight();

    // setter
    void setIdProduk(int id);
    void setTipeProduk(string tipe);
    void setOrigin(string origin);
    void setAddedWeight(int added_weight);
};

#endif
