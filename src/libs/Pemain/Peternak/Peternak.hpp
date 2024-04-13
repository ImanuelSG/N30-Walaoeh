#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include "../Pemain.hpp"
#include "../Storage/Storage.hpp"
#include "../../Toko/Sellable/Hewan/Hewan.hpp"
#include "../../pcolor/pcolor.h"

class Peternak : public Pemain
{
private:
    static int ternak_n;
    static int ternak_m;
    Storage<Hewan> peternakan;
    int countHewanInventory();
    bool isMakananAvailable(string tipeHewan);

public:
    Peternak(string name, int gulden, int berat);
    ~Peternak();
    void ternak();
    void kasihMakan();
    void panen();
    void cetakPeternakan();
    int getKekayaan();
    int getKKP();
    string getRole() const;

    void setPeternakan(const Storage<Hewan> &storage);
    static int getUkuranTernakN();
    static int getUkuranTernakM();
    static void setUkuranTernakN(int n);
    static void setUkuranTernakM(int m);

    void azab();
};

#endif