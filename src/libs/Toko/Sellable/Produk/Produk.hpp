#ifndef PRODUK_HPP
#define PRODUK_HPP

#include "../Sellable.hpp"
#include "../../../Exception/Exception.hpp"
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <tuple>

/*<ID> <KODE_HURUF> <NAME> <TYPE> <ORIGIN> <ADDED_WEIGHT> <PRICE>*/
class Produk : public Sellable
{
protected:
    string tipe_produk;
    string origin;
    int added_weight;

public:
    static int id_produk;
    // key: nama barang origin;  value: id, code, name, type, addedWeight, price
    static map<string, vector<tuple<int, string, string, string, int, int>>> productOriginMap;
    static map<string, tuple<int, string, string, string, int, int>> productMap;


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

    // load config to productMap
    static void loadProductOriginConfig(string path);
    static void loadProductConfig(string path);

};

#endif
