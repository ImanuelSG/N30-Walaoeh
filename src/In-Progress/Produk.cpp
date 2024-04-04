#include "Produk.hpp"

// class Produk : public Sellable
// string tipe_produk;
// string origin;
// int added_weight;

// ctor default
Produk::Produk() {
    tipe_produk = "";
    origin = "";
    added_weight = 0;
}

// ctor user defined
Produk::Produk(int id, string kode, string nama_produk, int harga, string tipe, string origin, int added_weight) {
    this->id_barang = id;
    this->kode_huruf = kode;
    this->nama_barang = nama_produk;
    this->harga_barang = harga;
    this->tipe_produk = tipe;
    this->origin = origin;
    this->added_weight = added_weight;
}

// operator overloading
Produk &Produk::operator=(const Produk &other) {
    this->tipe_produk = other.tipe_produk;
    this->origin = other.origin;
    this->added_weight = other.added_weight;
    return *this;
}

// cctor
Produk::Produk(const Produk &other) : Sellable(other){
    this->tipe_produk = other.tipe_produk;
    this->origin = other.origin;
    this->added_weight = other.added_weight;
}

// dtor
Produk::~Produk() {}