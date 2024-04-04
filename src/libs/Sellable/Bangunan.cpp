#include "Bangunan.hpp"
#include <map>

/* <ID> <KODE_HURUF> <NAME> <PRICE> <MATERIAL_1> <MATERIAL_1_QUANTITY> <MATERIAL_2> <MATERIAL_2_QUANTITY> ...*/

// map<string, int> material; // <string nama_material, int jumlah_material>

// ctor default
Bangunan:: Bangunan(){}

// ctor user defined
Bangunan::Bangunan(int id, string kode, string nama_bangunan, int harga, map<string, int> material){}

// operator overloading
Bangunan &Bangunan::operator=(const Bangunan &other){}

// cctor
Bangunan::Bangunan(const Bangunan &other){}

// dtor
Bangunan:: ~Bangunan(){}

/* Methods */
// getter
map<string, int> Bangunan::getMaterial(){}

// setter
void Bangunan::setMaterial(map<string, int> material){}

void Bangunan::bangun(){}