#include "Tanaman.hpp"
#include <iostream>


// ctor default
Tanaman::Tanaman()
{
    this->tipe_tanaman = "";
    this->duration_to_harvest = 0;
}

// ctor user defined
Tanaman::Tanaman(int id, string kode, string nama_tanaman, string tipe, int durasi_panen, int harga)
{
    this->id_barang = id;
    this->kode_huruf = kode;
    this->nama_barang = nama_tanaman;
    this->harga_barang = harga;
    this->tipe_tanaman = tipe;
    this->duration_to_harvest = 0;
}

// operator overloading
Tanaman &Tanaman::operator=(const Tanaman &other)
{
    this->tipe_tanaman = other.tipe_tanaman;
    this->duration_to_harvest = other.duration_to_harvest;
    return *this;
}

// cctor
Tanaman::Tanaman(const Tanaman &other) : Sellable(other)
{
    this->tipe_tanaman = other.tipe_tanaman;
    this->duration_to_harvest = other.duration_to_harvest;
}

// dtor
Tanaman::~Tanaman() {}

/* Methods */
// getter
string Tanaman::getTipeTanaman()
{
    return this->tipe_tanaman;
}
int Tanaman::getDurationToHarvest()
{
    return this->duration_to_harvest;
}

// setter
void Tanaman::setTipeTanaman(string tipe)
{
    this->tipe_tanaman = tipe;
}
void Tanaman::setDurationToHarvest(int durasi_panen)
{
    this->duration_to_harvest = durasi_panen;
}

Tanaman Tanaman::tambahTanaman()
{
    int id;
    string kode, nama, tipe;
    int durasi, harga;

    cout << "Masukkan ID, Kode, Nama, Tipe, Durasi, Harga: ";
    cin >> id;
    cin >> kode;
    cin >> nama;
    cin >> tipe;
    cin >> durasi;
    cin >> harga;

    Tanaman tanaman(id, kode, nama, tipe, durasi, harga);
    return tanaman;
}

Tanaman Tanaman::tambahTanamanConfig(ifstream &file)
{
    int id, durasi, harga;
    string kode, nama, tipe;

    file >> id >> kode >> nama >> tipe >> durasi >> harga;

    Tanaman tanaman(id, kode, nama, tipe, durasi, harga);

    return tanaman;
}

void Tanaman::tambahUmurTanaman(int age)
{
    this->age += age;
}