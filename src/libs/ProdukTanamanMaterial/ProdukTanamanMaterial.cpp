#include "ProdukTanamanMaterial.hpp"

// class ProdukTanamanMaterial : public Produk
ProdukTanamanMaterial::ProdukTanamanMaterial(int id, const string &kode, const string &nama_produk, int harga, const string &origin, int added_weight)
    : Produk(id, kode, nama_produk, harga, "PRODUCT_MATERIAL_PLANT", origin, added_weight) {}

// dtor
ProdukTanamanMaterial::~ProdukTanamanMaterial() {}