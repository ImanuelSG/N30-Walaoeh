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
ProdukHewan ProdukHewan::tambahProdukHewanHerbivora(Hewan &hewan)
{
    tuple<int, string, string, string, int, int> produk_herbivora_tuple = Produk::productOriginMap[hewan.getNamaBarang()];
    ProdukHewan produk_hewan_baru = ProdukHewan(get<0>(produk_herbivora_tuple), get<1>(produk_herbivora_tuple), get<2>(produk_herbivora_tuple), get<3>(produk_herbivora_tuple), hewan.getNamaBarang(), get<4>(produk_herbivora_tuple), get<5>(produk_herbivora_tuple));

    return produk_hewan_baru;
}

ProdukHewan ProdukHewan::tambahProdukHewanKarnivora(Hewan &hewan)
{
    tuple<int, string, string, string, int, int> produk_karnivora_tuple = Produk::productOriginMap[hewan.getNamaBarang()];
    ProdukHewan produk_hewan_baru = ProdukHewan(get<0>(produk_karnivora_tuple), get<1>(produk_karnivora_tuple), get<2>(produk_karnivora_tuple), get<3>(produk_karnivora_tuple), hewan.getNamaBarang(), get<4>(produk_karnivora_tuple), get<5>(produk_karnivora_tuple));

    return produk_hewan_baru;
}

pair<ProdukHewan, ProdukHewan> ProdukHewan::tambahProdukHewanOmnivora(Hewan &hewan)
{
    ProdukHewan produk_hewan_baru_meat, produk_hewan_baru_egg;

    if (hewan.getKodeHuruf() == "CHK")
    {
        produk_hewan_baru_meat = ProdukHewan(14, "CHM", "CHICKEN_MEAT", tipe_produk_hewan, "CHICKEN", 3, 7);
        produk_hewan_baru_egg = ProdukHewan(16, "CHE", "CHICKEN_EGG", tipe_produk_hewan, "CHICKEN", 1, 4);
    }
    else if (hewan.getKodeHuruf() == "DCK")
    {
        produk_hewan_baru_meat = ProdukHewan(15, "DCM", "DUCK_MEAT", tipe_produk_hewan, "DUCK", 3, 7);
        produk_hewan_baru_egg = ProdukHewan(17, "DCE", "DUCK_EGG", tipe_produk_hewan, "DUCK", 2, 4);
    }

    return make_pair(produk_hewan_baru_meat, produk_hewan_baru_egg);
}

// static method
// ProdukHewan ProdukHewan::tambahProdukHewan(ifstream &file)
// {
//     string kode, nama_produk, tipe, origin;
//     int id, harga, added_weight;

//     file >> id >> kode >> nama_produk >> tipe >> origin >> added_weight >> harga;

//     return ProdukHewan(jenis_produk_hewan, id, kode, nama_produk, tipe, origin, added_weight, harga);
// }
