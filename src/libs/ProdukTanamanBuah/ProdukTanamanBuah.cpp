#include "ProdukTanamanBuah.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <utility>

// class ProdukTanamanBuah : public Produk

const string ProdukTanamanBuah::tipe_produk_tanaman_buah = "PRODUCT_FRUIT_PLANT";

// ctor default
ProdukTanamanBuah::ProdukTanamanBuah()
{
    this->jenis_sellable = jenis_produk_tanaman_buah;
    this->id_produk = 1;
    this->kode_huruf = "";
    this->nama_barang = "";
    this->tipe_produk = "";
    this->origin = "";
    this->added_weight = 0;
    this->harga_barang = 0;
}

// ctor user defined
ProdukTanamanBuah::ProdukTanamanBuah(int jenis_sellable, int id, string kode, string nama_produk, string tipe, string origin, int added_weight, int harga)
    : Produk(jenis_produk_tanaman_buah, id, kode, nama_produk, tipe_produk_tanaman_buah, origin, added_weight, harga)
{
}

// operator overloading
ProdukTanamanBuah &ProdukTanamanBuah::operator=(const ProdukTanamanBuah &other)
{
    this->jenis_sellable = other.jenis_sellable;
    this->id_produk = other.id_produk;
    this->kode_huruf = other.kode_huruf;
    this->nama_barang = other.nama_barang;
    this->tipe_produk = other.tipe_produk;
    this->origin = other.origin;
    this->added_weight = other.added_weight;
    this->harga_barang = other.harga_barang;
    return *this;
}

// dtor
ProdukTanamanBuah::~ProdukTanamanBuah() {}

/* Methods */
ProdukTanamanBuah ProdukTanamanBuah::tambahProdukTanamanBuah(Tanaman &tanaman)
{
    ProdukTanamanBuah produk_tanaman_buah_baru;
    int id_produk = Produk::getIdProduk();
    string origin = tanaman.getNamaBarang();
    int added_weight, harga;

    cout << "Masukkan berat tambahan: ";
    cin >> added_weight;

    cout << "Masukkan harga: ";
    cin >> harga;

    if (tanaman.isApple())
    {
        produk_tanaman_buah_baru = ProdukTanamanBuah(jenis_produk_tanaman_buah, id_produk, "APP", "APPLE", tipe_produk_tanaman_buah, origin, added_weight, harga);
    }
    else if (tanaman.isOrange())
    {
        produk_tanaman_buah_baru = ProdukTanamanBuah(jenis_produk_tanaman_buah, id_produk, "ORP", "ORANGE", tipe_produk_tanaman_buah, origin, added_weight, harga);
    }
    else if (tanaman.isBanana())
    {
        produk_tanaman_buah_baru = ProdukTanamanBuah(jenis_produk_tanaman_buah, id_produk, "BNP", "BANANA", tipe_produk_tanaman_buah, origin, added_weight, harga);
    }
    else if (tanaman.isGuava())
    {
        produk_tanaman_buah_baru = ProdukTanamanBuah(jenis_produk_tanaman_buah, id_produk, "GAP", "GUAVA", tipe_produk_tanaman_buah, origin, added_weight, harga);
    }

    return produk_tanaman_buah_baru;
}