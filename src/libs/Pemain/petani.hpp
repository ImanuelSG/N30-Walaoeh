#ifndef PETANI_HPP
#define PETANI_HPP

#include "pemain.hpp"


class Petani : public Pemain{
    private:
        static int ladang_m;
        static int ladang_n;
        // storage
    public:
        Petani(string name, int gulden, int berat);
        ~Petani();
        void tanam();
        void panen();
        void cetakLadang();
        void beli();
        void jual();
};


#endif