#include "Sellable.hpp"
#include <iostream>

// string kode_huruf; // 3 huruf
// string nama_barang;
// int harga_barang;

// ctor default
Sellable::Sellable()
{
    this->kode_huruf = "";
    this->nama_barang = "";
    this->harga_barang = 0;
}

// ctor user defined
Sellable::Sellable(string kode, string nama, int harga)
{
    this->kode_huruf = kode;
    this->nama_barang = nama;
    this->harga_barang = harga;
}

// operator overloading
Sellable &Sellable::operator=(const Sellable &other)
{
    this->kode_huruf = other.kode_huruf;
    this->nama_barang = other.nama_barang;
    this->harga_barang = other.harga_barang;
    return *this;
}


// dtor
Sellable::~Sellable() {}

/* Methods */
// getter
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
bool Sellable::isEdible(){
    return false;
}

bool Sellable::isHewan(){
    return false;
}
