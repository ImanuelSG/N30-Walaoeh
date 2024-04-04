#ifndef PRODUCTPLANTFRUIT_HPP
#define PRODUCTPLANTFRUIT_HPP

#include "Produk.hpp"

class ProdukPlantMaterial : public Produk
{
public:
    ProdukPlantMaterial(int id, const string &kode, const string &nama, int harga, const string &origin, int addedWeight);
};

#endif
