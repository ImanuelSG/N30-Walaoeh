#include "ProdukHewan.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <utility>

const string ProdukHewan::tipe_produk_hewan = "PRODUCT_ANIMAL";

ProdukHewan::ProdukHewan()
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
ProdukHewan::ProdukHewan(int id, string kode, string nama_produk, string tipe, string origin, int added_weight, int harga)
    : Produk(id, kode, nama_produk, tipe_produk_hewan, origin, added_weight, harga)
{
}

// operator overloading
ProdukHewan &ProdukHewan::operator=(const ProdukHewan &other)
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

// bool ProdukHewan::operator==(const ProdukHewan &a, const ProdukHewan &b)
// {
//     return a.id_produk == b.id_produk && a.kode_huruf == b.kode_huruf && a.nama_barang == b.nama_barang && a.tipe_produk == b.tipe_produk && a.origin == b.origin && a.added_weight == b.added_weight && a.harga_barang == b.harga_barang;
// }

// dtor
ProdukHewan::~ProdukHewan() {}

// CLone

Sellable *ProdukHewan::Clone()
{
    return new ProdukHewan(*this);
}

string ProdukHewan::getJenis()
{
    return "PRODUK_HEWAN";
}

bool ProdukHewan::isEdible()
{
    return true;
}

/* Methods */
Sellable* ProdukHewan::tambahProdukHewanHerbivora(Hewan &hewan)
{
    vector<tuple<int, string, string, string, int, int>> produk_herbivora_vector = Produk::productOriginMap[hewan.getNamaBarang()];

    ProdukHewan* produk_hewan_baru = new ProdukHewan(get<0>(produk_herbivora_vector[0]), get<1>(produk_herbivora_vector[0]), get<2>(produk_herbivora_vector[0]), get<3>(produk_herbivora_vector[0]), hewan.getNamaBarang(), get<4>(produk_herbivora_vector[0]), get<5>(produk_herbivora_vector[0]));
    
    delete &hewan;
    return produk_hewan_baru;
}

Sellable* ProdukHewan::tambahProdukHewanKarnivora(Hewan &hewan)
{
    vector<tuple<int, string, string, string, int, int>> produk_karnivora_vektor = Produk::productOriginMap[hewan.getNamaBarang()];

    ProdukHewan* produk_hewan_baru = new ProdukHewan(get<0>(produk_karnivora_vektor[0]), get<1>(produk_karnivora_vektor[0]), get<2>(produk_karnivora_vektor[0]), get<3>(produk_karnivora_vektor[0]), hewan.getNamaBarang(), get<4>(produk_karnivora_vektor[0]), get<5>(produk_karnivora_vektor[0]));
    
    delete &hewan;
    return produk_hewan_baru;
}

Sellable* ProdukHewan::tambahProdukHewanOmnivoraDaging(Hewan &hewan)
{
    vector<tuple<int, string, string, string, int, int>> produk_omnivora_vector = Produk::productOriginMap[hewan.getNamaBarang()];

    ProdukHewan* produk_hewan_baru = new ProdukHewan(get<0>(produk_omnivora_vector[0]), get<1>(produk_omnivora_vector[0]), get<2>(produk_omnivora_vector[0]), get<3>(produk_omnivora_vector[0]), hewan.getNamaBarang(), get<4>(produk_omnivora_vector[0]), get<5>(produk_omnivora_vector[0]));
    
 
    return produk_hewan_baru;
}

Sellable* ProdukHewan::tambahProdukHewanOmnivoraTelur(Hewan &hewan)
{
    vector<tuple<int, string, string, string, int, int>> produk_omnivora_vector = Produk::productOriginMap[hewan.getNamaBarang()];

    ProdukHewan* produk_hewan_baru = new ProdukHewan(get<0>(produk_omnivora_vector[1]), get<1>(produk_omnivora_vector[1]), get<2>(produk_omnivora_vector[1]), get<3>(produk_omnivora_vector[1]), hewan.getNamaBarang(), get<4>(produk_omnivora_vector[1]), get<5>(produk_omnivora_vector[1]));
    
    delete &hewan;
    return produk_hewan_baru;
}

// static method
// ProdukHewan ProdukHewan::tambahProdukHewan(ifstream &file)
// {
//     string kode, nama_produk, tipe, origin;
//     int id, harga, added_weight;

//     file >> id >> kode >> nama_produk >> tipe >> origin >> added_weight >> harga;

//     return ProdukHewan(jenis_produk_hewan, id, kode, nama_produk, tipe, origin, added_weight, harga);
// }
