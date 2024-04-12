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

// dtor
ProdukHewan::~ProdukHewan() {}

string ProdukHewan::getJenis()
{
    return "PRODUK_HEWAN";
}

bool ProdukHewan::isEdible() {
    return true;
}

/* Methods */
vector<ProdukHewan> ProdukHewan::tambahProdukHewanHerbivora(Hewan &hewan)
{
    vector<tuple<int, string, string, string, int, int>> produk_herbivora_vector = Produk::productOriginMap[hewan.getNamaBarang()];
    vector<ProdukHewan> produk_hewan_baru_list;

    for (int i = 0; i < produk_herbivora_vector.size(); i++) {
        ProdukHewan produk_hewan_baru = ProdukHewan(get<0>(produk_herbivora_vector[i]), get<1>(produk_herbivora_vector[i]), get<2>(produk_herbivora_vector[i]), get<3>(produk_herbivora_vector[i]), hewan.getNamaBarang(), get<4>(produk_herbivora_vector[i]), get<5>(produk_herbivora_vector[i]));
        produk_hewan_baru_list.push_back(produk_hewan_baru);
    }

    return produk_hewan_baru_list;
}

vector<ProdukHewan> ProdukHewan::tambahProdukHewanKarnivora(Hewan &hewan)
{
    vector<tuple<int, string, string, string, int, int>> produk_karnivora_vektor = Produk::productOriginMap[hewan.getNamaBarang()];
    vector<ProdukHewan> produk_hewan_baru_list;

    for (int i = 0; i < produk_karnivora_vektor.size(); i++) {
        ProdukHewan produk_hewan_baru = ProdukHewan(get<0>(produk_karnivora_vektor[i]), get<1>(produk_karnivora_vektor[i]), get<2>(produk_karnivora_vektor[i]), get<3>(produk_karnivora_vektor[i]), hewan.getNamaBarang(), get<4>(produk_karnivora_vektor[i]), get<5>(produk_karnivora_vektor[i]));
        produk_hewan_baru_list.push_back(produk_hewan_baru);
    }

    return produk_hewan_baru_list;
}

vector<ProdukHewan> ProdukHewan::tambahProdukHewanOmnivora(Hewan &hewan)
{
    vector<tuple<int, string, string, string, int, int>> produk_omnivora_vector = Produk::productOriginMap[hewan.getNamaBarang()];
    vector<ProdukHewan> produk_hewan_baru_list;

    for (int i = 0; i < produk_omnivora_vector.size(); i++) {
        ProdukHewan produk_hewan_baru = ProdukHewan(get<0>(produk_omnivora_vector[i]), get<1>(produk_omnivora_vector[i]), get<2>(produk_omnivora_vector[i]), get<3>(produk_omnivora_vector[i]), hewan.getNamaBarang(), get<4>(produk_omnivora_vector[i]), get<5>(produk_omnivora_vector[i]));
        produk_hewan_baru_list.push_back(produk_hewan_baru);
    }

    return produk_hewan_baru_list;
}

// static method
// ProdukHewan ProdukHewan::tambahProdukHewan(ifstream &file)
// {
//     string kode, nama_produk, tipe, origin;
//     int id, harga, added_weight;

//     file >> id >> kode >> nama_produk >> tipe >> origin >> added_weight >> harga;

//     return ProdukHewan(jenis_produk_hewan, id, kode, nama_produk, tipe, origin, added_weight, harga);
// }
