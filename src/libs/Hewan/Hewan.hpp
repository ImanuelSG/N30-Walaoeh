#ifndef HEWAN_HPP
#define HEWAN_HPP

#include "../Sellable/Sellable.cpp"
#include <fstream>

/*<ID> <KODE_HURUF> <NAME> <TYPE> <WEIGHT_TO_HARVEST> <PRICE>*/
class Hewan : public Sellable
{
private:
    string tipe_hewan;
    int weight_to_harvest;
    int weight;

public:
    // ctor default
    Hewan();

    // ctor user defined
    Hewan(int id, string kode, string nama_hewan, string tipe, int weight, int harga);

    // operator overloading
    Hewan &operator=(const Hewan &other);

    // cctor
    Hewan(const Hewan &other);

    // dtor
    ~Hewan();

    /* Methods */
    // getter
    string getTipeHewan();
    int getWeight();
    int getWeightToHarvest();

    // setter
    void setTipeHewan(string tipe);
    void setWeight(int weight);

    static Hewan tambahHewan();
    static Hewan tambahHewanConfig(ifstream &file);

    void tambahWeightHewan(int weight);
};

#endif
