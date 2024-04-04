#include "ProdukPlantMaterial.hpp"

// class ProdukPlantMaterial : public Produk
ProdukPlantMaterial::ProdukPlantMaterial(int id, const string &kode, const string &nama, int harga, const string &origin, int addedWeight)
    : Produk(id, kode, nama, harga, "PRODUCT_MATERIAL_PLANT", origin, addedWeight)
{
}
