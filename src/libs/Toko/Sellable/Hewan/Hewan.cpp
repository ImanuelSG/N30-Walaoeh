#include "Hewan.hpp"
#include <iostream>

map<string, tuple<int, string, string, int, int>> Hewan::animalMap;

// ctor default
Hewan::Hewan() : Sellable()
{
    this->id_hewan = 1;
    this->tipe_hewan = "";
    this->weight = 0;
    this->weight_to_harvest = 0;
}

// ctor user defined
Hewan::Hewan(int id, string kode, string nama_hewan, string tipe, int weight, int weight_to_harvest, int harga)
    : Sellable(kode, nama_hewan, harga)
{
    this->id_hewan = id;
    this->tipe_hewan = tipe;
    this->weight = weight;
    this->weight_to_harvest = weight_to_harvest;
}

// operator overloading
Hewan &Hewan::operator=(const Hewan &other)
{
    this->id_hewan = other.id_hewan;
    this->tipe_hewan = other.tipe_hewan;
    this->weight = other.weight;
    this->weight_to_harvest = other.weight_to_harvest;
    return *this;
}

// dtor
Hewan::~Hewan()
{
}

Sellable *Hewan::Clone()
{
    return new Hewan(*this);
}

/* Methods */
// getter
string Hewan::getJenis()
{
    return "HEWAN";
}

int Hewan::getIdHewan()
{
    return this->id_hewan;
}
string Hewan::getTipeHewan()
{
    return this->tipe_hewan;
}
int Hewan::getWeight()
{
    return this->weight;
}

int Hewan::getWeightToHarvest()
{
    return this->weight_to_harvest;
}

// setter
void Hewan::setIdHewan(int id)
{
    this->id_hewan = id;
}

void Hewan::setTipeHewan(string tipe)
{
    this->tipe_hewan = tipe;
}

void Hewan::setWeight(int weight)
{
    this->weight = weight;
}

Hewan Hewan::tambahHewan()
{
    int id;
    string kode, nama, tipe;
    int weight, weight_to_harvest, harga;

    cout << "Masukkan ID, Kode, Nama, Tipe, Weight, Harga: ";
    cin >> id;
    cin >> kode;
    cin >> nama;
    cin >> tipe;
    cin >> weight_to_harvest;
    cin >> harga;

    Hewan hewan(id, kode, nama, tipe, weight, weight_to_harvest, harga);
    return hewan;
}

Hewan Hewan::tambahHewanConfig(ifstream &file)
{
    int id, weight, weight_to_harvest, harga;
    string kode, nama, tipe;

    file >> id >> kode >> nama >> tipe >> weight_to_harvest >> harga;

    Hewan hewan(id, kode, nama, tipe, weight, weight_to_harvest, harga);

    return hewan;
}

void Hewan::tambahWeightHewan(int weight)
{
    this->weight += weight;
}

void Hewan::operator>>(vector<Sellable*>& vectorProdukHewan)
{
    vector<tuple<int, string, string, string, int, int>> produkBaruVektor = Produk::productOriginMap[getNamaBarang()];

    for (int i = 0; i < produkBaruVektor.size(); i++)
    {
        Sellable* produkHewanBaru = new ProdukHewan(get<0>(produkBaruVektor[i]), get<1>(produkBaruVektor[i]), get<2>(produkBaruVektor[i]), get<3>(produkBaruVektor[i]), getNamaBarang(), get<4>(produkBaruVektor[i]), get<5>(produkBaruVektor[i]));
        
        vectorProdukHewan.push_back(produkHewanBaru);
    }
    return;
}

// boolean
bool Hewan::isCarnivore()
{
    return this->tipe_hewan == "CARNIVORE";
}

bool Hewan::isHerbivore()
{
    return this->tipe_hewan == "HERBIVORE";
}

bool Hewan::isOmnivore()
{
    return this->tipe_hewan == "OMNIVORE";
}

bool Hewan::isHarvestValid()
{
    return this->weight >= this->weight_to_harvest;
}

void Hewan::loadHewanConfig(string path)
{
    ifstream inputFile(path);
    if (!inputFile.is_open())
    {
        throw FileNotFoundException();
    }

    string line;
    int id, weightToHarvest, price;
    string code, name, type, origin;
    while (getline(inputFile, line))
    {
        istringstream iss(line);
        iss >> id >> code >> name >> type >> weightToHarvest >> price;
        animalMap[name] = make_tuple(id, code, type, weightToHarvest, price);
    }
    inputFile.close();
}
