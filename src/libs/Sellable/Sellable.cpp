#include "Sellable.hpp"
#include "../Exception/Exception.hpp"
#include <iostream>

// int jenis_sellable;
// string kode_huruf; // 3 huruf
// string nama_barang;
// int harga_barang;

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

string Sellable::getKodeHuruf()
{
    return this->kode_huruf;
}

string Sellable::getKodeHurufTanaman()
{
    return (isTanaman()) ? this->kode_huruf : throw InvalidJenisTanamanException();
}

string Sellable::getKodeHurufHewan()
{
    return (isHewan()) ? this->kode_huruf : throw InvalidJenisHewanException();
}

string Sellable::getKodeHurufProdukMaterial()
{
    return (isProdukMaterial()) ? this->kode_huruf : throw InvalidJenisProdukMaterialException();
}

string Sellable::getKodeHurufProdukBuah()
{
    return (isProdukBuah()) ? this->kode_huruf : throw InvalidJenisProdukBuahException();
}

string Sellable::getKodeHurufProdukHewan()
{
    return (isProdukHewan()) ? this->kode_huruf : throw InvalidJenisProdukHewanException();
}

string Sellable::getKodeHurufBangunan()
{
    return (isBangunan()) ? this->kode_huruf : throw InvalidJenisBangunanException();
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

// additional
bool Sellable::isEdible()
{
    return false;
}

bool Sellable::isHewan()
{
    return false;
}

// boolean
bool Sellable::isHewan()
{
    return this->jenis_sellable == jenis_hewan;
}

bool Sellable::isTanaman()
{
    return this->jenis_sellable == jenis_tanaman;
}

bool Sellable::isProdukMaterial()
{
    return this->jenis_sellable == jenis_produk_tanaman_material;
}

bool Sellable::isProdukBuah()
{
    return this->jenis_sellable == jenis_produk_tanaman_buah;
}

bool Sellable::isProdukHewan()
{
    return this->jenis_sellable == jenis_produk_hewan;
}

bool Sellable::isBangunan()
{
    return this->jenis_sellable == jenis_bangunan;
}