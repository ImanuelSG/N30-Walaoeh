#ifndef PETANI_HPP
#define PETANI_HPP

#include "../Pemain.hpp"
#include "../../Toko/Sellable/Tanaman/Tanaman.hpp"

class Petani : public Pemain
{
private:
    static int ladang_m;
    static int ladang_n;
    Storage<Tanaman> ladang;

public:
    Petani(string name, int gulden, int berat);
    ~Petani();
    void tanam();
    void panen();
    void cetakLadang();
    void addPlantAge();
    int countTanamanInventory();
    int getKekayaan();
    int getKKP();
    string getRole() const;

    void setLadang(const Storage<Tanaman> &storage);

    static int getUkuranLadangN();
    static int getUkuranLadangM();
    static void setUkuranLadangN(int n);
    static void setUkuranLadangM(int m);

    void azab();
};

#endif