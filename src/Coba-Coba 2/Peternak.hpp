#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include <memory>
#include "Pemain.hpp"
#include "HewanTernak.hpp"

class Peternak : public Pemain
{
public:
    Peternak(const std::string &name) : Pemain(name) {}
    void BeternakHewan(std::shared_ptr<HewanTernak> hewan);
    void PanenHewanTernak();
};

#endif
