#include "Bangunan.hpp"

/* <ID> <KODE_HURUF> <NAME> <PRICE> <MATERIAL_1> <MATERIAL_1_QUANTITY> <MATERIAL_2> <MATERIAL_2_QUANTITY> ...*/

// map<string, int> material; // <string nama_material, int jumlah_material>

int Bangunan::id_bangunan = 1;
map<string, tuple<string, int, vector<tuple<string, int>>>> Bangunan::list_of_bangunan;
// ctor default
Bangunan::Bangunan()
{
    this->material = {};
}

// ctor user defined
Bangunan::Bangunan(int id, string kode, string nama_bangunan, int harga, map<string, int> material) : Sellable(kode, nama_bangunan, harga)
{
    this->id_bangunan = id;
    this->material = material;
}

// operator overloading
Bangunan &Bangunan::operator=(const Bangunan &other)
{
    this->id_bangunan = other.id_bangunan;
    this->material = other.material;
    return *this;
}

// dtor
Bangunan::~Bangunan()
{
    // this->material.clear();
    cout << "Bangunan " << this->getNamaBarang() << " telah dihancurkan" << endl;
}

/* Methods */
// getter
int Bangunan::getIdBangunan()
{
    return id_bangunan++;
}

map<string, int> Bangunan::getMaterial()
{
    return this->material;
}

// setter
void Bangunan::setIdBangunan(int id)
{
    this->id_bangunan = id;
}

void Bangunan::setMaterial(map<string, int> material)
{
    this->material = material;
}

void Bangunan::getListBangunan()
{
    for (auto &it : list_of_bangunan)
    {
        cout << it.first << " : " << get<0>(it.second) << " " << get<1>(it.second) << " ";
        for (auto &it2 : get<2>(it.second))
        {
            cout << get<0>(it2) << " " << get<1>(it2) << " ";
        }
        cout << endl;
    }
}
