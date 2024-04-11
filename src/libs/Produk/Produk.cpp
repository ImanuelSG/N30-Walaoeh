#include "Produk.hpp"
#include <fstream>

// class Produk : public Sellable
// string tipe_produk;
// string origin;
// int added_weight;

int Produk::id_produk = 1;

Produk::Produk() : Sellable()
{
    this->jenis_sellable = -1;
    this->id_produk = 1;
    this->tipe_produk = "";
    this->origin = "";
    this->added_weight = 0;
}

// ctor user defined
Produk::Produk(int jenis_sellable, int id, string kode, string nama_produk, string tipe, string origin, int added_weight, int harga) : Sellable(jenis_sellable, kode, nama_produk, harga)
{
    this->jenis_sellable = jenis_sellable;
    this->id_produk = id;
    this->tipe_produk = tipe;
    this->origin = origin;
    this->added_weight = added_weight;
}

// operator overloading
Produk &Produk::operator=(const Produk &other)
{
    this->jenis_sellable = other.jenis_sellable;
    this->id_produk = other.id_produk;
    this->tipe_produk = other.tipe_produk;
    this->origin = other.origin;
    this->added_weight = other.added_weight;
    return *this;
}

// dtor
Produk::~Produk()
{
}

/* Methods */
// getter
int Produk::getIdProduk()
{
    return id_produk++;
}

string Produk::getTipeProduk()
{
    return this->tipe_produk;
}

string Produk::getOrigin()
{
    return this->origin;
}

int Produk::getAddedWeight()
{
    return this->added_weight;
}

// setter
void Produk::setIdProduk(int id)
{
    this->id_produk = id;
}

void Produk::setTipeProduk(string tipe)
{
    this->tipe_produk = tipe;
}

void Produk::setOrigin(string origin)
{
    this->origin = origin;
}

void Produk::setAddedWeight(int added_weight)
{
    this->added_weight = added_weight;
}