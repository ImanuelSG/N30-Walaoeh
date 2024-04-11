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
Bangunan::Bangunan(int jenis_sellable, int id, string kode, string nama_bangunan, int harga, map<string, int> material) : Sellable(jenis_sellable, kode, nama_bangunan, harga)
{
    this->jenis_sellable = jenis_bangunan;
    this->id_bangunan = id;
    this->material = material;
}

// operator overloading
Bangunan &Bangunan::operator=(const Bangunan &other)
{
    this->jenis_sellable = other.jenis_sellable;
    this->id_bangunan = other.id_bangunan;
    this->material = other.material;
    return *this;
}

// dtor
Bangunan::~Bangunan()
{
    // this->material.clear();
    // cout << "Bangunan " << this->getNamaBarang() << " telah dihancurkan" << endl;
}

/* Methods */
// getter
string Bangunan::getJenis()
{
    return "BANGUNAN";
}

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

tuple<string, int, vector<tuple<string, int>>> Bangunan::getSpecificRecipe(string name)
{
    return list_of_bangunan.find(name)->second;
}

map<string, tuple<string, int, vector<tuple<string, int>>>> Bangunan::getAllRecipe()
{
    return list_of_bangunan;
}

void Bangunan::displayAllRecipe()
{
    int index = 1;

    cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;

    // Example tuple with entry.first = "SMALL_HOUSE"  is <SMH,50, vector<<TEAK_WOOD,1>,<SANDAL_WOOD,1>>
    for (const auto &entry : list_of_bangunan)
    {
        cout << "    " << index << ". " << entry.first << "(" << get<1>(entry.second) << "gulden"
             << ",";

        // Iterate through all material
        const auto &materials = get<2>(entry.second);
        for (const auto &material : materials)
        {
            cout << " " << get<0>(material) << " " << get<1>(material);
            if (material != materials.back())
            {
                cout << ",";
            }
        }
        cout << ")" << endl;
        index++;
    }
}

bool Bangunan::isValidRecipe(string name)
{
    return list_of_bangunan.find(name) != list_of_bangunan.end();
}
