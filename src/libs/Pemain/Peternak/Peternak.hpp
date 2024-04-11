#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include "../Pemain.hpp"
#include "../Storage/Storage.hpp"
#include "../../Hewan/Hewan.hpp"


class Peternak : public Pemain
{
private:
    static int ternak_n;
    static int ternak_m;
    Storage<Hewan&> peternakan;
    void cetakPenyimpananHewan();
    int countHewanInventory();
    bool isMakananAvailable(string tipeHewan);
public:
    Peternak(string name, int gulden, int berat);
    ~Peternak();
    void ternak();
    void kasihMakan();
    void panen();
    void cetakPeternakan();
    void beli();
    void jual();
    int getKKP() const;
    string getRole() const;
};

#endif