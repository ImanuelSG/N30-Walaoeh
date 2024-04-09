#include "Tanaman.hpp"
#include <iostream>


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
    this->age = 0;
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

// dtor
Tanaman::~Tanaman() {
    // cout << "Tanaman " << this->getNamaBarang() << " telah dihapus" << std::endl;
}

/* Methods */
// getter
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