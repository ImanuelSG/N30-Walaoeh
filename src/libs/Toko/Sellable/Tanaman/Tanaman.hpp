#ifndef TANAMAN_HPP
#define TANAMAN_HPP

#include "../Sellable.hpp"
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
    int age;
    int duration_to_harvest;

public:
    int id_tanaman = 1;
    static map<string, tuple<int, string, string, int, int>> plantMap;

    // ctor default
    Tanaman();

    // ctor user defined
    Tanaman(int id, string kode, string nama_tanaman, string tipe, int umur, int durasi_panen, int harga);

    // operator overloading
    Tanaman &operator=(const Tanaman &other);

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

    static Tanaman tambahTanaman();
    static Tanaman tambahTanamanConfig(ifstream &file);

    void tambahUmurTanaman(int age);

    // boolean
    bool isMaterial();
    bool isBuah();
    
    // bool isTeak();
    // bool isSandalwood();
    // bool isAloe();
    // bool isIronwood();
    // bool isApple();
    // bool isOrange();
    // bool isBanana();
    // bool isGuava();

    // load config to animalMap
    static void loadTanamanConfig(string path);
};

#endif
