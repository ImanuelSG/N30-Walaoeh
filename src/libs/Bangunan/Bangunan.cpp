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

tuple<string, int, map<string, int>> Bangunan::getSpecificRecipe(string name)
{
    return list_of_bangunan.find(name)->second;
}

map<string, tuple<string, int, map<string, int>>> Bangunan::getAllRecipe()
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
            // if (material != materials.back())
            // {
            //     cout << ",";
            // }
        }
        cout << ")" << endl;
        index++;
    }
}

bool Bangunan::isValidRecipe(string name)
{
    return list_of_bangunan.find(name) != list_of_bangunan.end();
}

void Bangunan::loadBangunanConfig(string path)
{
    ifstream inputFile(path);
    if (!inputFile.is_open()) {
        throw FileNotFoundException();
    }

    string line;
    int id, price;
    string code, name;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        iss >> id >> code >> name >> price;


        map<string, int> materials;
        string material_name;
        int quantity;
        while (iss >> material_name >> quantity) {
            materials[material_name] = quantity;
        }
        list_of_bangunan[name] = make_tuple(code, price, materials);
    }
    inputFile.close();

    // how to access
    // for (const auto& building : list_of_bangunan) {
    //     cout << "Name: " << building.first << endl;
    //     cout << "Code: " << get<0>(building.second) << endl;
    //     cout << "Price: " << get<1>(building.second) << endl;

    //     cout << "Materials:" << endl;
    //     for (const auto& material : get<2>(building.second)) {
    //         cout << "  " << material.first << " : " << material.second << endl;
    //     }
    // }
}
