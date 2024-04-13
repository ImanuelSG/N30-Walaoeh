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
    this->id_produk = 1;
    this->kode_huruf = "";
    this->nama_barang = "";
    this->tipe_produk = "";
    this->origin = "";
    this->added_weight = 0;
    this->harga_barang = 0;
}

// ctor user defined
ProdukTanamanBuah::ProdukTanamanBuah(int id, string kode, string nama_produk, string tipe, string origin, int added_weight, int harga) : Produk(id, kode, nama_produk, tipe_produk_tanaman_buah, origin, added_weight, harga)
{
}

Sellable *ProdukTanamanBuah::Clone()
{
    return new ProdukTanamanBuah(*this);
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

bool &ProdukTanamanBuah::operator==(const ProdukTanamanBuah &a, const ProdukTanamanBuah &b)
{
    return a.id_produk == b.id_produk && a.kode_huruf == b.kode_huruf && a.nama_barang == b.nama_barang && a.tipe_produk == b.tipe_produk && a.origin == b.origin && a.added_weight == b.added_weight && a.harga_barang == b.harga_barang;
}

// dtor
ProdukTanamanBuah::~ProdukTanamanBuah() {}

// getter
string ProdukTanamanBuah::getJenis()
{
    return "PRODUK_TANAMAN_BUAH";
}

bool ProdukTanamanBuah::isEdible()
{
    return true;
}

Sellable* ProdukTanamanBuah::tambahProdukTanamanBuah(Tanaman &tanaman)
{
    vector<tuple<int, string, string, string, int, int>> produk_buah_vektor = Produk::productOriginMap[tanaman.getNamaBarang()];

    Sellable *produk_buah_baru;
    for (int i = 0; i < produk_buah_vektor.size(); i++)
    {
        produk_buah_baru = new ProdukTanamanBuah(get<0>(produk_buah_vektor[i]), get<1>(produk_buah_vektor[i]), get<2>(produk_buah_vektor[i]), get<3>(produk_buah_vektor[i]), tanaman.getNamaBarang(), get<4>(produk_buah_vektor[i]), get<5>(produk_buah_vektor[i]));
    }

    return produk_buah_baru;
}