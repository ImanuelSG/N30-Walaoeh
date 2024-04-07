#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP

#include "../Sellable/Sellable.hpp"
#include <map>

/* <ID> <KODE_HURUF> <NAME> <PRICE> <MATERIAL_1> <MATERIAL_1_QUANTITY> <MATERIAL_2> <MATERIAL_2_QUANTITY> ...*/

class Bangunan : public Sellable
{
private:
    map<string, int> material; // <string nama_material, int jumlah_material>

public:
    // ctor default
    Bangunan();

    // ctor user defined
    Bangunan(int id, string kode, string nama_bangunan, int harga, map<string, int> material);

    // operator overloading
    Bangunan &operator=(const Bangunan &other);

    // cctor
    Bangunan(const Bangunan &other);

    // dtor
    ~Bangunan();

    /* Methods */
    // getter
    map<string, int> getMaterial();

    // setter
    void setMaterial(map<string, int> material);

    void bangun();
};

#endif
