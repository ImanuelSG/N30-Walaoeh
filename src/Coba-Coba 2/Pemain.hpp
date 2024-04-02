#ifndef PEMAIN_HPP
#define PEMAIN_HPP

#include <string>
#include "Inventory.hpp"
#include "Exception.hpp"

using namespace std;

class Pemain
{
private:
    std::string name;
    int uang;
    Inventory<Entitas> inventory;

public:
    Pemain(const std::string &name) : name(name), uang(0) {}

    void operator+=(int jumlah)
    {
        uang += jumlah;
    }

    void operator-=(int jumlah)
    {
        if (uang >= jumlah)
        {
            uang -= jumlah;
        }
        else
        {
            throw KekuranganUangException();
        }
    }
};

#endif
