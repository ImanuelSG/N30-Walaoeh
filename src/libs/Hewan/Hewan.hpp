#ifndef HEWAN_HPP
#define HEWAN_HPP

#include "../Sellable/Sellable.hpp"
#include <fstream>

/*<ID> <KODE_HURUF> <NAME> <TYPE> <WEIGHT_TO_HARVEST> <PRICE>*/
class Hewan : public Sellable
{
private:
    string tipe_hewan;
    int weight;
    int weight_to_harvest;

public:
    int id_hewan = 1;
    
    // ctor default
    Hewan();

    // ctor user defined
    Hewan(int jenis_sellable, int id, string kode, string nama_hewan, string tipe, int weight, int weight_to_harvest, int harga);

    // operator overloading
    Hewan &operator=(const Hewan &other);

    // dtor
    ~Hewan();

    /* Methods */
    // getter
    int getIdHewan();
    string getTipeHewan();
    int getWeight();
    int getWeightToHarvest();
    int getAddedWeight

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
    bool isHarvestValid(int weight, int weight_to_harvest);

    bool isCow();
    bool isSheep();
    bool isHorse();
    bool isRabbit();
    bool isSnake();
    bool isChicken();
    bool isDuck();
};

#endif
