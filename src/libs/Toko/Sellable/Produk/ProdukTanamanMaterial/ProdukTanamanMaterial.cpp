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
    this->id_produk = 1;
    this->kode_huruf = "";
    this->nama_barang = "";
    this->tipe_produk = "";
    this->origin = "";
    this->added_weight = 0;
    this->harga_barang = 0;
}

// ctor user defined
ProdukTanamanMaterial::ProdukTanamanMaterial(int id, string kode, string nama_produk, string tipe, string origin, int added_weight, int harga)
    : Produk(id, kode, nama_produk, tipe_produk_tanaman_material, origin, added_weight, harga)
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

//
Sellable *ProdukTanamanMaterial::Clone()
{
    return new ProdukTanamanMaterial(*this);
}
/* Methods */
// getter
string ProdukTanamanMaterial::getJenis()
{
    return "PRODUK_TANAMAN_MATERIAL";
}