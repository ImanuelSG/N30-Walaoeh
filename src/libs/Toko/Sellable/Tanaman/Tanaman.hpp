#ifndef TANAMAN_HPP
#define TANAMAN_HPP

#include "../Sellable.hpp"
#include "../Produk/Produk.hpp"
#include "../Produk/ProdukTanamanBuah/ProdukTanamanBuah.hpp"
#include "../Produk/ProdukTanamanMaterial/ProdukTanamanMaterial.hpp"
#include "../../../Exception/Exception.hpp"
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <tuple>

/*<ID> <KODE_HURUF> <NAME> <TYPE> <DURATION_TO_HARVEST> <PRICE>*/
class Tanaman : public Sellable
{
private:
    string tipe_tanaman;
    int id_tanaman = 1;
    int age;
    int duration_to_harvest;

public:
    static map<string, tuple<int, string, string, int, int>> plantMap;

    // ctor default
    Tanaman();

    // ctor user defined
    Tanaman(int id, string kode, string nama_tanaman, string tipe, int umur, int durasi_panen, int harga);

    // operator overloading
    Tanaman &operator=(const Tanaman &other);

    Sellable *Clone();

    // dtor
    ~Tanaman();

    /* Methods */
    // getter
    string getJenis();

    int getIdTanaman();
    string getTipeTanaman();
    int getAge();
    int getDurationToHarvest();

    // setter
    void setIdTanaman(int id);
    void setTipeTanaman(string tipe);
    void setAge(int age);

    static Tanaman tambahTanamanConfig(ifstream &file);

    void tambahUmurTanaman(int age);
    
    // Konversi tanaman menjadi produk (buah) kalau weight sudah mencapai weight_to_harvest
    void operator>>(Sellable*& produkTanamanBuahBaru);

    // boolean
    bool isMaterial();
    bool isBuah();
    bool isHarvestValid();

    // load config to animalMap
    static void loadTanamanConfig(string path);
};

#endif
