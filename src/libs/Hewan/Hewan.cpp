#include "Hewan.hpp"
#include <iostream>

// string tipe_hewan;
// int weight;

// ctor default
Hewan::Hewan()
{
    this->tipe_hewan = "";
    this->weight = 0;
}

// ctor user defined
Hewan::Hewan(int id, string kode, string nama_hewan, string tipe, int weight, int harga)
{
    this->id_barang = id;
    this->kode_huruf = kode;
    this->nama_barang = nama_hewan;
    this->harga_barang = harga;
    this->tipe_hewan = tipe;
    this->weight = 0;
}

// operator overloading
Hewan &Hewan::operator=(const Hewan &other)
{
    this->tipe_hewan = other.tipe_hewan;
    this->weight = other.weight;
    return *this;
}

// cctor
Hewan::Hewan(const Hewan &other) : Sellable(other)
{
    this->tipe_hewan = other.tipe_hewan;
    this->weight = other.weight;
}

// dtor
Hewan::~Hewan() {}

/* Methods */
// getter
string Hewan::getTipeHewan()
{
    return this->tipe_hewan;
}
int Hewan::getWeight()
{
    return this->weight;
}

// setter
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
    int weight, harga;

    cout << "Masukkan ID, Kode, Nama, Tipe, Weight, Harga: ";
    cin >> id;
    cin >> kode;
    cin >> nama;
    cin >> tipe;
    cin >> weight;
    cin >> harga;

    Hewan hewan(id, kode, nama, tipe, weight, harga);
    return hewan;
}

Hewan Hewan::tambahHewanConfig(ifstream &file)
{
    int id, weight, harga;
    string kode, nama, tipe;

    file >> id >> kode >> nama >> tipe >> weight >> harga;

    Hewan hewan(id, kode, nama, tipe, weight, harga);

    return hewan;
}

void Hewan::tambahWeightHewan(int weight)
{
    this->weight += weight;
}