#ifndef PETANI_HPP
#define PETANI_HPP

#include "../Pemain.hpp"
#include "../../Tanaman/Tanaman.hpp"

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
    void beli();
    void jual();
    int getKKP() const;
    string getRole() const;
};

#endif