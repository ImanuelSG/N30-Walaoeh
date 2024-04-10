#ifndef TANAMAN_HPP
#define TANAMAN_HPP

#include "../Sellable/Sellable.hpp"
#include <fstream>

/*<ID> <KODE_HURUF> <NAME> <TYPE> <DURATION_TO_HARVEST> <PRICE>*/
class Tanaman : public Sellable
{
private:
    string tipe_tanaman;
    int duration_to_harvest;
    int age;

public:
    int id_tanaman = 1;

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

};

#endif
