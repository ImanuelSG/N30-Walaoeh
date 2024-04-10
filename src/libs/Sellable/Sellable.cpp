#include "Sellable.hpp"
#include "../Exception/Exception.hpp"
#include <iostream>

// int jenis_sellable;
// string kode_huruf; // 3 huruf
// string nama_barang;
// int harga_barang;

const int Sellable::jenis_hewan = 0;
const int Sellable::jenis_tanaman = 1;
const int Sellable::jenis_produk_tanaman_material = 2;
const int Sellable::jenis_produk_tanaman_buah = 3;
const int Sellable::jenis_produk_hewan = 4;
const int Sellable::jenis_bangunan = 5;

// ctor default
Sellable::Sellable()
{
    this->jenis_sellable = -1;
    this->kode_huruf = "";
    this->nama_barang = "";
    this->harga_barang = 0;
}

// ctor user defined
Sellable::Sellable(int jenis_sellable, string kode, string nama, int harga)
{
    this->jenis_sellable = jenis_sellable;
    this->kode_huruf = kode;
    this->nama_barang = nama;
    this->harga_barang = harga;
}

// operator overloading
Sellable &Sellable::operator=(const Sellable &other)
{
    this->jenis_sellable = other.jenis_sellable;
    this->kode_huruf = other.kode_huruf;
    this->nama_barang = other.nama_barang;
    this->harga_barang = other.harga_barang;
    return *this;
}


// dtor
Sellable::~Sellable() {}

/* Methods */
// getter
int Sellable::getJenisSellable()
{
    return this->jenis_sellable;
}

string Sellable::getKodeHurufTanaman(int jenis_sellable)
{
    return (jenis_sellable == jenis_tanaman) ? this->kode_huruf : throw InvalidJenisTanamanException();
}

string Sellable::getKodeHurufHewan(int jenis_sellable)
{
    return (jenis_sellable == jenis_hewan) ? this->kode_huruf : throw InvalidJenisHewanException();
}

string Sellable::getKodeHurufProdukMaterial(int jenis_sellable)
{
    return (jenis_sellable == jenis_produk_tanaman_material) ? this->kode_huruf : throw InvalidJenisProdukMaterialException();
}

string Sellable::getKodeHurufProdukBuah(int jenis_sellable)
{
    return (jenis_sellable == jenis_produk_tanaman_buah) ? this->kode_huruf : throw InvalidJenisProdukBuahException();
}

string Sellable::getKodeHurufProdukHewan(int jenis_sellable)
{
    return (jenis_sellable == jenis_produk_hewan) ? this->kode_huruf : throw InvalidJenisProdukHewanException();
}

string Sellable::getKodeHurufBangunan(int jenis_sellable)
{
    return (jenis_sellable == jenis_bangunan) ? this->kode_huruf : throw InvalidJenisBangunanException();
}

string Sellable::getNamaBarang()
{
    return this->nama_barang;
}

int Sellable::getHargaBarang()
{
    return this->harga_barang;
}

// setter
void Sellable::setKodeHuruf(string kode)
{
    this->kode_huruf = kode;
}

void Sellable::setNamaBarang(string nama)
{
    this->nama_barang = nama;
}

void Sellable::setHargaBarang(int harga)
{
    this->harga_barang = harga;
}
