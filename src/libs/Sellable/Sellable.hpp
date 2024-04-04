#ifndef SELLABLE_HPP
#define SELLABLE_HPP

#include <string>

using namespace std;

class Sellable
{
protected:
    int id_barang;
    string kode_huruf; // 3 huruf
    string nama_barang;
    int harga_barang;

public:
    // ctor default
    Sellable();

    // ctor user defined
    Sellable(int id, string kode, string nama, int harga);

    // operator overloading
    Sellable &operator=(const Sellable &sellable);
    
    // cctor
    Sellable(const Sellable &sellable);

    // dtor
    virtual ~Sellable();

    /* Methods */
    // getter
    int getIdBarang();
    string getKodeHuruf();
    string getNamaBarang();
    int getHargaBarang();

    // setter
    void setIdBarang(int id);
    void setKodeHuruf(string kode);
    void setNamaBarang(string nama);
    void setHargaBarang(int harga);

};

#endif
