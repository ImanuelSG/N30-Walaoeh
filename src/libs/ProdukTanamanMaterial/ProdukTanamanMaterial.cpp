#include "ProdukTanamanMaterial.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <utility>

// class ProdukTanamanMaterial : public Produk

// ctor default
ProdukTanamanMaterial::ProdukTanamanMaterial()
{
    this->jenis_sellable = jenis_produk_tanaman_material;
    this->id_produk = 1;
    this->kode_huruf = "";
    this->nama_barang = "";
    this->tipe_produk = "";
    this->origin = "";
    this->added_weight = 0;
    this->harga_barang = 0;
}

// ctor user defined
ProdukTanamanMaterial::ProdukTanamanMaterial(int jenis_sellable, int id, string kode, string nama_produk, string origin, int added_weight, int harga)
    : Produk(jenis_produk_tanaman_material, id, kode, nama_produk, "PRODUCT_MATERIAL_PLANT", origin, added_weight, harga)
{
}

// operator overloading
ProdukTanamanMaterial &ProdukTanamanMaterial::operator=(const ProdukTanamanMaterial &other)
{
    this->jenis_sellable = other.jenis_sellable;
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

    if (tanaman.getKodeHurufTanaman(tanaman.getJenisSellable()) == "TAW")
    {
        produk_tanaman_material_baru = ProdukTanamanMaterial(jenis_produk_tanaman_material, id_produk, "TAW", "TEAK_WOOD", "TEAK_TREE", added_weight, harga);
    }
    else if (tanaman.getKodeHurufTanaman(tanaman.getJenisSellable()) == "SAW")
    {
        produk_tanaman_material_baru = ProdukTanamanMaterial(jenis_produk_tanaman_material, id_produk, "SAW", "SANDALWOOD_WOOD", "SANDALWOOD_TREE", added_weight, harga);
    }
    else if (tanaman.getKodeHurufTanaman(tanaman.getJenisSellable()) == "ALW")
    {
        produk_tanaman_material_baru = ProdukTanamanMaterial(jenis_produk_tanaman_material, id_produk, "ALW", "ALOE_WOOD", "ALOE_TREE", added_weight, harga);
    }
    else if (tanaman.getKodeHurufTanaman(tanaman.getJenisSellable()) == "IRW")
    {
        produk_tanaman_material_baru = ProdukTanamanMaterial(jenis_produk_tanaman_material, id_produk, "IRW", "IRONWOOD_WOOD", "IRONWOOD_TREE", added_weight, harga);
    }

    return produk_tanaman_material_baru;
}