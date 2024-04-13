#include "Produk.hpp"

// class Produk : public Sellable
// string tipe_produk;
// string origin;
// int added_weight;

int Produk::id_produk = 1;

map<string, tuple<int, string, string, string, int, int>> Produk::productMap;
map<string, vector<tuple<int, string, string, string, int, int>>> Produk::productOriginMap;

Produk::Produk() : Sellable()
{
    this->id_produk = 1;
    this->tipe_produk = "";
    this->origin = "";
    this->added_weight = 0;
}

// ctor user defined
Produk::Produk(int id, string kode, string nama_produk, string tipe, string origin, int added_weight, int harga) : Sellable(kode, nama_produk, harga)
{
    this->id_produk = id;
    this->tipe_produk = tipe;
    this->origin = origin;
    this->added_weight = added_weight;
}

// operator overloading
Produk &Produk::operator=(const Produk &other)
{
    this->id_produk = other.id_produk;
    this->tipe_produk = other.tipe_produk;
    this->origin = other.origin;
    this->added_weight = other.added_weight;
    return *this;
}

// dtor
Produk::~Produk()
{
}

// Clone

/* Methods */
// getter
int Produk::getIdProduk()
{
    return id_produk++;
}

string Produk::getTipeProduk()
{
    return this->tipe_produk;
}

string Produk::getOrigin()
{
    return this->origin;
}

int Produk::getAddedWeight()
{
    return this->added_weight;
}

// setter
void Produk::setIdProduk(int id)
{
    this->id_produk = id;
}

void Produk::setTipeProduk(string tipe)
{
    this->tipe_produk = tipe;
}

void Produk::setOrigin(string origin)
{
    this->origin = origin;
}

void Produk::setAddedWeight(int added_weight)
{
    this->added_weight = added_weight;
}

void Produk::loadProductConfig(string path)
{
    ifstream inputFile(path);
    if (!inputFile.is_open())
    {
        throw FileNotFoundException();
    }

    string line;
    int id, addedWeight, price;
    string code, name, type, origin;
    while (getline(inputFile, line) && !((line)).empty())
    {
        istringstream iss(line);
        iss >> id >> code >> name >> type >> origin >> addedWeight >> price;

        productMap[name] = make_tuple(id, code, origin, type, addedWeight, price);
    }
    inputFile.close();
}

void Produk::loadProductOriginConfig(string path)
{
    ifstream inputFile(path);
    if (!inputFile.is_open())
    {
        throw FileNotFoundException();
    }

    string line;
    int id, addedWeight, price;
    string code, name, type, origin;
    while (getline(inputFile, line) && !isEmpty(line))
    {
        istringstream iss(line);
        iss >> id >> code >> name >> type >> origin >> addedWeight >> price;
        productOriginMap[origin].push_back(make_tuple(id, code, name, type, addedWeight, price));
    }
    inputFile.close();
}
