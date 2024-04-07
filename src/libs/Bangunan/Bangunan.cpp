#include "Bangunan.hpp"

/* <ID> <KODE_HURUF> <NAME> <PRICE> <MATERIAL_1> <MATERIAL_1_QUANTITY> <MATERIAL_2> <MATERIAL_2_QUANTITY> ...*/

// map<string, int> material; // <string nama_material, int jumlah_material>

// ctor default
Bangunan::Bangunan(){
    this->material = {};
}

// ctor user defined
Bangunan::Bangunan(int id, string kode, string nama_bangunan, int harga, map<string, int> material){
    this->id_barang = id;
    this->kode_huruf = kode;
    this->nama_barang = nama_bangunan;
    this->harga_barang = harga;
    this->material = material;
}

// operator overloading
Bangunan &Bangunan::operator=(const Bangunan &other){
    this->material = other.material;
    return *this;
}

// cctor
Bangunan::Bangunan(const Bangunan &other): Sellable(other){
    this->material = other.material;
}

// dtor
Bangunan::~Bangunan(){}

/* Methods */
// getter
map<string, int> Bangunan::getMaterial(){
    return this->material;
}

// setter
void Bangunan::setMaterial(map<string, int> material){
    this->material = material;
}

void Bangunan::bangun(){
    
}
