#include "Tanaman.hpp"
#include <iostream>

map<string, tuple<int, string, string, int, int>> Tanaman::plantMap;

// ctor default
Tanaman::Tanaman()
{
    this->id_tanaman = 1;
    this->tipe_tanaman = "";
    this->age = 0;
    this->duration_to_harvest = 0;
}

// ctor user defined
Tanaman::Tanaman(int id, string kode, string nama_tanaman, string tipe, int umur, int durasi_panen, int harga) : Sellable(kode, nama_tanaman, harga)
{
    this->id_tanaman = id;
    this->tipe_tanaman = tipe;
    this->age = umur;
    this->duration_to_harvest = durasi_panen;
}

// operator overloading
Tanaman &Tanaman::operator=(const Tanaman &other)
{
    this->id_tanaman = other.id_tanaman;
    this->tipe_tanaman = other.tipe_tanaman;
    this->age = other.age;
    this->duration_to_harvest = other.duration_to_harvest;
    return *this;
}

// bool Tanaman::operator==(const Tanaman &a, const Tanaman &b)
// {
//     return a.id_tanaman == b.id_tanaman && a.tipe_tanaman == b.tipe_tanaman && a.age == b.age && a.duration_to_harvest == b.duration_to_harvest;
// }

// dtor
Tanaman::~Tanaman()
{
    // cout << "Tanaman " << this->getNamaBarang() << " telah dihapus" << std::endl;
}

// Clone

Sellable *Tanaman::Clone()
{
    return new Tanaman(*this);
}

/* Methods */
// getter
string Tanaman::getJenis()
{
    return "TANAMAN";
}

int Tanaman::getIdTanaman()
{
    return this->id_tanaman;
}

string Tanaman::getTipeTanaman()
{
    return this->tipe_tanaman;
}

int Tanaman::getAge()
{
    return this->age;
}

int Tanaman::getDurationToHarvest()
{
    return this->duration_to_harvest;
}

// setter
void Tanaman::setIdTanaman(int id)
{
    this->id_tanaman = id;
}

void Tanaman::setTipeTanaman(string tipe)
{
    this->tipe_tanaman = tipe;
}

void Tanaman::setAge(int age)
{
    this->age = age;
}

Tanaman Tanaman::tambahTanaman()
{
    int id;
    string kode, nama, tipe;
    int umur, durasi, harga;

    cout << "Masukkan ID, Kode, Nama, Tipe, Umur, Durasi, Harga: ";
    cin >> id;
    cin >> kode;
    cin >> nama;
    cin >> tipe;
    cin >> umur;
    cin >> durasi;
    cin >> harga;

    Tanaman tanaman(id, kode, nama, tipe, umur, durasi, harga);
    return tanaman;
}

Tanaman Tanaman::tambahTanamanConfig(ifstream &file)
{
    int id, umur, durasi, harga;
    string kode, nama, tipe;

    file >> id >> kode >> nama >> tipe >> durasi >> harga;

    Tanaman tanaman(id, kode, nama, tipe, umur, durasi, harga);

    return tanaman;
}

void Tanaman::tambahUmurTanaman(int age)
{
    this->age += age;
}

// boolean
bool Tanaman::isMaterial()
{
    return this->tipe_tanaman == "MATERIAL_PLANT";
}

bool Tanaman::isBuah()
{
    return this->tipe_tanaman == "FRUIT_PLANT";
}

bool Tanaman::isHarvestValid()
{
    return this->age >= this->duration_to_harvest;
}

void Tanaman::loadTanamanConfig(string path)
{
    ifstream inputFile(path);
    if (!inputFile.is_open())
    {
        throw FileNotFoundException();
    }

    string line;
    int id, durationToHarvest, price;
    string code, name, type, origin;
    while (getline(inputFile, line))
    {
        istringstream iss(line);
        iss >> id >> code >> name >> type >> durationToHarvest >> price;
        plantMap[name] = make_tuple(id, code, type, durationToHarvest, price);
    }
    inputFile.close();
}
