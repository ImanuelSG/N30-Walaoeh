#ifndef HEWAN_HPP
#define HEWAN_HPP

#include "../Sellable/Sellable.hpp"
#include <fstream>

/*<ID> <KODE_HURUF> <NAME> <TYPE> <WEIGHT_TO_HARVEST> <PRICE>*/
class Hewan : public Sellable
{
private:
    string tipe_hewan;
    int weight_to_harvest;
    int weight;

public:
    int id_hewan = 1;
    
    // ctor default
    Hewan();

    // ctor user defined
    Hewan(int id, string kode, string nama_hewan, string tipe, int weight, int weight_to_harvest, int harga);

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

    // setter
    void setIdHewan(int id);
    void setTipeHewan(string tipe);
    void setWeight(int weight);

    static Hewan tambahHewan();
    static Hewan tambahHewanConfig(ifstream &file);

    void tambahWeightHewan(int weight);
};

#endif