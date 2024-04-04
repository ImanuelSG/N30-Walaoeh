#include "Sellable.hpp"
#include <iostream>

// int id_barang;
// string kode_huruf; // 3 huruf
// string nama_barang;
// int harga_barang;

// ctor default
Sellable::Sellable()
{
    this->id_barang = 1;
    this->kode_huruf = "";
    this->nama_barang = "";
    this->harga_barang = 0;
}

// ctor user defined
Sellable::Sellable(int id, string kode, string nama, int harga)
{
    this->id_barang = id;
    this->kode_huruf = kode;
    this->nama_barang = nama;
    this->harga_barang = harga;
}

// operator overloading
Sellable &Sellable::operator=(const Sellable &other)
{
    this->id_barang = other.id_barang;
    this->kode_huruf = other.kode_huruf;
    this->nama_barang = other.nama_barang;
    this->harga_barang = other.harga_barang;
    return *this;
}

// cctor
Sellable::Sellable(const Sellable &other)
{
    this->id_barang = other.id_barang;
    this->kode_huruf = other.kode_huruf;
    this->nama_barang = other.nama_barang;
    this->harga_barang = other.harga_barang;
}

// dtor
Sellable::~Sellable() {}


/* Methods */
// getter
int Sellable::getIdBarang()
{
    return this->id_barang;
}
string Sellable::getKodeHuruf()
{
    return this->kode_huruf;
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
void Sellable::setIdBarang(int id){
    this->id_barang = id;
}
void Sellable::setKodeHuruf(string kode){
    this->kode_huruf = kode;
}
void Sellable::setNamaBarang(string nama){
    this->nama_barang = nama;
}
void Sellable::setHargaBarang(int harga){
    this->harga_barang = harga;
}

