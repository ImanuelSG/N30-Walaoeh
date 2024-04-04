#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

#include "Pemain.hpp"
#include "Pajak.hpp"

class WaliKota : public Pemain
{
public:
    WaliKota(const std::string &nama) : Pemain(nama) {}
    void KumpulkanPajak(Pajak &pajak);
};

#endif
