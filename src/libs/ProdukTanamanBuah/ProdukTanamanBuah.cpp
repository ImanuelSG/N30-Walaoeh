#include "ProdukTanamanBuah.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <utility>

// class ProdukTanamanBuah : public Produk

// ctor default
ProdukTanamanBuah::ProdukTanamanBuah()
{
    this->id_produk = 1;
    this->kode_huruf = "";
    this->nama_barang = "";
    this->tipe_produk = "";
    this->origin = "";
    this->added_weight = 0;
    this->harga_barang = 0;
}

// ctor user defined
ProdukTanamanBuah::ProdukTanamanBuah(int id, string kode, string nama_produk, string origin, int added_weight, int harga)
    : Produk(id, kode, nama_produk, "PRODUCT_FRUIT_PLANT", origin, added_weight, harga)
{
}

// operator overloading
ProdukTanamanBuah &ProdukTanamanBuah::operator=(const ProdukTanamanBuah &other)
{
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
    int added_weight, harga;

    cout << "Masukkan berat tambahan: ";
    cin >> added_weight;

    cout << "Masukkan harga: ";
    cin >> harga;

    if (tanaman.getKodeHuruf() == "APP")
    {
        produk_tanaman_buah_baru = ProdukTanamanBuah(id_produk, "APP", "APPLE", "APPLE_TREE", added_weight, harga);
    }
    else if (tanaman.getKodeHuruf() == "ORP")
    {
        produk_tanaman_buah_baru = ProdukTanamanBuah(id_produk, "ORP", "ORANGE", "ORANGE_TREE", added_weight, harga);
    }
    else if (tanaman.getKodeHuruf() == "BNP")
    {
        produk_tanaman_buah_baru = ProdukTanamanBuah(id_produk, "BNP", "BANANA", "BANANA_TREE", added_weight, harga);
    }
    else if (tanaman.getKodeHuruf() == "GAP")
    {
        produk_tanaman_buah_baru = ProdukTanamanBuah(id_produk, "GAP", "GUAVA", "GUAVA_TREE", added_weight, harga);
    }

    return produk_tanaman_buah_baru;
}