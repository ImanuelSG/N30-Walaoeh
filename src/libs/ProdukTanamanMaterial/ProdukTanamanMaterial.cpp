#include "ProdukTanamanMaterial.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <utility>

// class ProdukTanamanMaterial : public Produk

// ctor default
ProdukTanamanMaterial::ProdukTanamanMaterial()
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
ProdukTanamanMaterial::ProdukTanamanMaterial(int id, string kode, string nama_produk, string origin, int added_weight, int harga)
    : Produk(id, kode, nama_produk, "PRODUCT_MATERIAL_PLANT", origin, added_weight, harga)
{
}

// operator overloading
ProdukTanamanMaterial &ProdukTanamanMaterial::operator=(const ProdukTanamanMaterial &other)
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
ProdukTanamanMaterial::~ProdukTanamanMaterial() {}

/* Methods */
ProdukTanamanMaterial ProdukTanamanMaterial::tambahProdukTanamanMaterial(Tanaman &tanaman)
{
    ProdukTanamanMaterial produk_tanaman_material_baru;
    int id_produk = Produk::getIdProduk();
    int added_weight, harga;

    cout << "Masukkan berat tambahan: ";
    cin >> added_weight;

    cout << "Masukkan harga: ";
    cin >> harga;

    if (tanaman.getKodeHuruf() == "TAW")
    {
        produk_tanaman_material_baru = ProdukTanamanMaterial(id_produk, "TAW", "TEAK_WOOD", "TEAK_TREE", added_weight, harga);
    }
    else if (tanaman.getKodeHuruf() == "SAW")
    {
        produk_tanaman_material_baru = ProdukTanamanMaterial(id_produk, "SAW", "SANDALWOOD_WOOD", "SANDALWOOD_TREE", added_weight, harga);
    }
    else if (tanaman.getKodeHuruf() == "ALW")
    {
        produk_tanaman_material_baru = ProdukTanamanMaterial(id_produk, "ALW", "ALOE_WOOD", "ALOE_TREE", added_weight, harga);
    }
    else if (tanaman.getKodeHuruf() == "IRW")
    {
        produk_tanaman_material_baru = ProdukTanamanMaterial(id_produk, "IRW", "IRONWOOD_WOOD", "IRONWOOD_TREE", added_weight, harga);
    }

    return produk_tanaman_material_baru;
}