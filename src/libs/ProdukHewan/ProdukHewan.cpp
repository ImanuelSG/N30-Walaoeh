#include "ProdukHewan.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <utility>

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
    : Produk(id, kode, nama_produk, "PRODUCT_ANIMAL", origin, added_weight, harga)
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

/* Methods */
ProdukHewan ProdukHewan::tambahProdukHewanHerbivora(Hewan &hewan)
{
    ProdukHewan produk_hewan_baru;
    int id_produk = Produk::getIdProduk();
    int added_weight, harga;

    cout << "Masukkan berat tambahan: ";
    cin >> added_weight;

    cout << "Masukkan harga: ";
    cin >> harga;

    if (hewan.getKodeHuruf() == "COW")
    {
        produk_hewan_baru = ProdukHewan(id_produk, "COM", "COW_MEAT", "PRODUCT_ANIMAL", "COW", added_weight, harga);
    }
    else if (hewan.getKodeHuruf() == "SHP")
    {
        produk_hewan_baru = ProdukHewan(id_produk, "SHM", "SHEEP_MEAT", "PRODUCT_ANIMAL", "SHEEP", added_weight, harga);
    }
    else if (hewan.getKodeHuruf() == "HRS")
    {
        produk_hewan_baru = ProdukHewan(id_produk, "HRM", "HORSE_MEAT", "PRODUCT_ANIMAL", "HORSE", added_weight, harga);
    }
    else if (hewan.getKodeHuruf() == "RBT")
    {
        produk_hewan_baru = ProdukHewan(id_produk, "RBM", "RABBIT_MEAT", "PRODUCT_ANIMAL", "RABBIT", added_weight, harga);
    }

    return produk_hewan_baru;
}

ProdukHewan ProdukHewan::tambahProdukHewanKarnivora(Hewan &hewan)
{
    ProdukHewan produk_hewan_baru;
    int id_produk = Produk::getIdProduk();
    int added_weight, harga;

    cout << "Masukkan berat tambahan: ";
    cin >> added_weight;

    cout << "Masukkan harga: ";
    cin >> harga;

    if (hewan.getKodeHuruf() == "SNK")
    {
        produk_hewan_baru = ProdukHewan(id_produk, "SNM", "SNAKE_MEAT", "PRODUCT_ANIMAL", "SNAKE", added_weight, harga);
    }

    return produk_hewan_baru;
}

pair<ProdukHewan, ProdukHewan> ProdukHewan::tambahProdukHewanOmnivora(Hewan &hewan)
{
    ProdukHewan produk_hewan_baru_meat, produk_hewan_baru_egg;
    int id_produk = Produk::getIdProduk();
    int added_weight, harga;

    cout << "Masukkan berat tambahan: ";
    cin >> added_weight;

    cout << "Masukkan harga: ";
    cin >> harga;

    if (hewan.getKodeHuruf() == "CHK")
    {
        produk_hewan_baru_meat = ProdukHewan(id_produk, "CHM", "CHICKEN_MEAT", "PRODUCT_ANIMAL", "CHICKEN", added_weight, harga);
        produk_hewan_baru_egg = ProdukHewan(id_produk, "CHE", "CHICKEN_EGG", "PRODUCT_ANIMAL", "CHICKEN", added_weight, harga);
    }
    else if (hewan.getKodeHuruf() == "DCK")
    {
        produk_hewan_baru_meat = ProdukHewan(id_produk, "DCM", "DUCK_MEAT", "PRODUCT_ANIMAL", "DUCK", added_weight, harga);
        produk_hewan_baru_egg = ProdukHewan(id_produk, "DCE", "DUCK_EGG", "PRODUCT_ANIMAL", "DUCK", added_weight, harga);
    }

    return make_pair(produk_hewan_baru_meat, produk_hewan_baru_egg);
}

// static method
ProdukHewan ProdukHewan::tambahProdukHewan(ifstream &file)
{
    string kode, nama_produk, tipe, origin;
    int id, harga, added_weight;

    file >> id >> kode >> nama_produk >> tipe >> origin >> added_weight >> harga;

    return ProdukHewan(id, kode, nama_produk, tipe, origin, added_weight, harga);
}

bool ProdukHewan::isEdible()  {return true;}