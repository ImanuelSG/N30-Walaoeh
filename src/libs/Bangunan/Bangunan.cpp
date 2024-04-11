#include "Bangunan.hpp"

/* <ID> <KODE_HURUF> <NAME> <PRICE> <MATERIAL_1> <MATERIAL_1_QUANTITY> <MATERIAL_2> <MATERIAL_2_QUANTITY> ...*/

// map<string, int> material; // <string nama_material, int jumlah_material>

int Bangunan::id_bangunan = 1;
map<string, tuple<string, int, map<string, int>>> Bangunan::list_of_bangunan;
// ctor default
Bangunan::Bangunan()
{
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

// tuple<string, int, vector<tuple<string, int>>> Bangunan::getSpecificRecipe(string name)
// {
//     return list_of_bangunan.find(name)->second;
// }

// map<string, tuple<string, int, vector<tuple<string, int>>>> Bangunan::getAllRecipe()
// {
//     return list_of_bangunan;
// }

void Bangunan::displayAllRecipe()
{
    int index = 1;

    cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;

    // Example tuple with entry.first = "SMALL_HOUSE"  is <SMH,50, vector<<TEAK_WOOD,1>,<SANDAL_WOOD,1>>
    for (const auto &entry : list_of_bangunan)
    {
        cout << "    " << index << ". " << entry.first << "(" << get<1>(entry.second) << "gulden"
             << ",";

        // Iterate through all materials
        const auto &materials = get<2>(entry.second);
        for (auto material = materials.begin(); material != materials.end(); material++)
        {
            cout << " " << material->first << " " << material->second;

            // Display comma except the last material
            if (material != prev(materials.end()))
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

tuple<Sellable *, int, map<string, int>> Bangunan::build(string name, map<string, int> materials, int gulden)
{
    tuple<string, int, map<string, int>> data = list_of_bangunan.find(name)->second;
    // Get the gulden
    int neededGulden = get<1>(data);
    // Get the materials
    map<string, int> neededMaterials = get<2>(data);
    map<string, int> remainingNeededMaterials;

    // Check if player has enough money (diffrence between needed and available)
    int remainingNeededGulden = neededGulden - gulden;

    for (auto &material : neededMaterials)
    {
        // Iterate through all neededMaterials
        string materialName = material.first;
        int materialQuantity = material.second;

        // Check if player has enough materials, it will return > 0 if player still need material
        int diffrence = materialQuantity - materials[materialName];

        // if it is mroe than 0 (means player still need a material), add it to the map
        if (diffrence > 0)
        {
            remainingNeededMaterials[materialName] = diffrence;
        }
    }
    // Check if player has enough money and materials
    if (remainingNeededGulden > 0 || !remainingNeededMaterials.empty())
    {
        throw NotEnoughMaterialException(remainingNeededGulden, remainingNeededMaterials);
    }
    else
    {
        // Create the building
        Sellable *building = new Bangunan(getIdBangunan(), get<0>(data), name, neededGulden, neededMaterials);
        return make_tuple(building, neededGulden, neededMaterials);
    }
};