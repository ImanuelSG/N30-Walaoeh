#ifndef HEWAN_HPP
#define HEWAN_HPP

#include "../Sellable.hpp"
#include "../../../Exception/Exception.hpp"
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <tuple>

/*<ID> <KODE_HURUF> <NAME> <TYPE> <WEIGHT_TO_HARVEST> <PRICE>*/
class Hewan : public Sellable
{
private:
    int id_hewan = 1;
    string tipe_hewan;
    int weight;
    int weight_to_harvest;

public:
    // map with key =
    static map<string, tuple<int, string, string, int, int>> animalMap;

    // ctor default
    Hewan();

    // ctor user defined
    Hewan(int id, string kode, string nama_hewan, string tipe, int weight, int weight_to_harvest, int harga);

    // operator overloading
    Hewan &operator=(const Hewan &other);

    // dtor
    ~Hewan();

    Sellable *Clone();

    /* Methods */
    // getter
    string getJenis();

    int getIdHewan();
    string getTipeHewan();
    int getWeight();
    int getWeightToHarvest();

    // setter
    void setIdHewan(int id);
    void setTipeHewan(string tipe);
    void setWeight(int weight);

    static Hewan tambahHewan();
    static Hewan tambahHewanConfig(ifstream &file);

    void tambahWeightHewan(int weight);

    // boolean
    bool isCarnivore();
    bool isHerbivore();
    bool isOmnivore();
    bool isHarvestValid();

    // bool isCow();
    // bool isSheep();
    // bool isHorse();
    // bool isRabbit();
    // bool isSnake();
    // bool isChicken();
    // bool isDuck();

    // load config to animalMap
    static void loadHewanConfig(string path);
};

#endif