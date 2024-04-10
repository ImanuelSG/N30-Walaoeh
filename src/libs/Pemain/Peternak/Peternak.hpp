#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include "../Pemain.hpp"

class Peternak : public Pemain
{
private:
    static int ternak_n;
    static int ternak_m;
    // storage HEWAN
public:
    Peternak(string name, int gulden, int berat);
    ~Peternak();
    void ternak();
    void kasihMakan();
    void panen();
    void cetakPeternakan();
    void beli();
    void jual();
    int getKKP();
    string getRole() const;
};

#endif