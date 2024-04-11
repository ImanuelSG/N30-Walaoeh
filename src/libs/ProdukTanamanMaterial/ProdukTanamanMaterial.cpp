#include "ProdukTanamanMaterial.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <utility>

// class ProdukTanamanMaterial : public Produk

const string ProdukTanamanMaterial::tipe_produk_tanaman_material = "PRODUCT_MATERIAL_PLANT";

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
ProdukTanamanMaterial::ProdukTanamanMaterial(int jenis_sellable, int id, string kode, string nama_produk, string tipe, string origin, int added_weight, int harga)
    : Produk(jenis_produk_tanaman_material, id, kode, nama_produk, tipe_produk_tanaman_material, origin, added_weight, harga)
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
    tuple<int, string, string, string, int, int> produk_material_tuple = Produk::productOriginMap[tanaman.getNamaBarang()];
    ProdukTanamanMaterial produk_material_baru = ProdukTanamanMaterial(jenis_produk_tanaman_material, get<0>(produk_material_tuple), get<1>(produk_material_tuple), get<2>(produk_material_tuple), get<3>(produk_material_tuple), tanaman.getNamaBarang(), get<4>(produk_material_tuple), get<5>(produk_material_tuple));

    return produk_material_baru;
}