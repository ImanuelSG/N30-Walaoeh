#ifndef TANAMAN_HPP
#define TANAMAN_HPP

#include "../Sellable/Sellable.cpp"
#include <fstream>

/*<ID> <KODE_HURUF> <NAME> <TYPE> <DURATION_TO_HARVEST> <PRICE>*/
class Tanaman : public Sellable
{
private:
    string tipe_tanaman;
    int duration_to_harvest;
    int age;

public:
    // ctor default
    Tanaman();

    // ctor user defined
    Tanaman(int id, string kode, string nama_tanaman, string tipe, int durasi_panen, int harga);

    // operator overloading
    Tanaman &operator=(const Tanaman &other);

    // cctor
    Tanaman(const Tanaman &other);

    // dtor
    ~Tanaman();

    /* Methods */
    // getter
    string getTipeTanaman();
    int getDurationToHarvest();
    //int getWeightToHarvest();

    // setter
    void setTipeTanaman(string tipe);
    void setDurationToHarvest(int durasi_panen);

    static Tanaman tambahTanaman();
    static Tanaman tambahTanamanConfig(ifstream &file);

    void tambahUmurTanaman(int age);
};

#endif
