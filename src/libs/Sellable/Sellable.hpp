#ifndef SELLABLE_HPP
#define SELLABLE_HPP

#include <string>
#include <iostream>
#include <tuple>
using namespace std;

class Sellable
{
protected:
    string kode_huruf; // 3 huruf
    string nama_barang;
    int harga_barang;

public:
    // ctor default
    Sellable();

    // ctor user defined
    Sellable(string kode, string nama, int harga);

    // operator overloading
    Sellable &operator=(const Sellable &other);

    // dtor
    virtual ~Sellable();

    /* Methods */
    // getter
    string getKodeHuruf();
    string getNamaBarang();
    int getHargaBarang();

    // setter
    void setKodeHuruf(string kode);
    void setNamaBarang(string nama);
    void setHargaBarang(int harga);

    // additional
    virtual bool isEdible();
    virtual int getAddedWeight() = 0;
    virtual bool isHewan();
};

#endif
