#ifndef SELLABLE_HPP
#define SELLABLE_HPP

#include <string>
#include <iostream>
#include <tuple>
using namespace std;

class Sellable
{
protected:
  /*Aturan Jenis Sellable:
  - hewan = 0,
  - tanaman = 1,
  - produk,
    produk tanaman material = 2
    produk tanaman buah = 3
    produk hewan = 4
  - bangunan = 5
  */

  int jenis_sellable;
  const static int jenis_hewan = 0;
  const static int jenis_tanaman = 1;
  const static int jenis_produk_tanaman_material = 2;
  const static int jenis_produk_tanaman_buah = 3;
  const static int jenis_produk_hewan = 4;
  const static int jenis_bangunan = 5;

  string kode_huruf; // 3 huruf
  string nama_barang;
  int harga_barang;

public:
  // ctor default
  Sellable();

  // ctor user defined
  Sellable(int jenis_sellable, string kode, string nama, int harga);

  // operator overloading
  Sellable &operator=(const Sellable &other);

  // dtor
  virtual ~Sellable();

  /* Methods */
  // getter
  int getJenisSellable();

  string getKodeHurufTanaman();
  string getKodeHurufHewan();
  string getKodeHurufProdukMaterial();
  string getKodeHurufProdukBuah();
  string getKodeHurufProdukHewan();
  string getKodeHurufBangunan();

  string getNamaBarang();
  int getHargaBarang();

  // setter
  void setKodeHuruf(string kode);
  void setNamaBarang(string nama);
  void setHargaBarang(int harga);

    // additional
    virtual bool isEdible();
    virtual int getAddedWeight() = 0;
    virtual bool isHewan();  // boolean
  // bool isHewan();
  bool isTanaman();
  bool isProdukMaterial();
  bool isProdukBuah();
  bool isProdukHewan();
  bool isBangunan();
};

#endif
