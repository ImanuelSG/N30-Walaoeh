#ifndef PEMAIN_HPP
#define PEMAIN_HPP

#include <iostream>

using namespace std;
class Pemain {
    protected:
        static int inventory_n;
        static int inventory_m;
        string name;
        int gulden;
        int berat;
        // storage
    public:
        Pemain(string name, int gulden, int berat);
        ~Pemain();
        string getName();
        int getGulden();
        int getWeight();
        void setName();
        void setGulden();
        void setWeight();
        void makan();
        virtual void beli() = 0;
        virtual void jual() = 0;
        void cetakPenyimpanan();        
};

#endif