#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP

#include "../Sellable.hpp"
#include "../../../Exception/Exception.hpp"
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <tuple>

/* <ID> <KODE_HURUF> <NAME> <PRICE> <MATERIAL_1> <MATERIAL_1_QUANTITY> <MATERIAL_2> <MATERIAL_2_QUANTITY> ...*/

class Bangunan : public Sellable
{
private:
    int id_bangunan;
    map<string, int> material; // <string nama_material, int jumlah_material>
public:
    static map<string, tuple<string, int, map<string, int>, int>> list_of_bangunan;
    // map with key = nama_bangunan, value = tuple<kode_bangunan, harga_bangunan, vector<tuple<material, jumlah_material>>>

    // ctor default
    Bangunan();

    // ctor user defined
    Bangunan(int id, string kode, string nama_bangunan, int harga, map<string, int> material);

    // operator overloading
    Bangunan &operator=(const Bangunan &other);

    // dtor
    ~Bangunan();

    Sellable *Clone();

    /* Methods */
    // getter
    string getJenis();

    int getIdBangunan();

    map<string, int> getMaterial();

    // setter
    void setIdBangunan(int id);

    void setMaterial(map<string, int> material);
    tuple<string, int, map<string, int>, int> getSpecificRecipe(string name);

    map<string, tuple<string, int, map<string, int>, int>> getAllRecipe();

    static void displayAllRecipe();
    static bool isValidRecipe(string name);
    static tuple<Sellable *, int, map<string, int>> build(string name, map<string, int> material);
    // load config to list_of_bangunan
    static void loadBangunanConfig(string path);
};

#endif
