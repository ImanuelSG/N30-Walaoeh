#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "../src/libs/Toko/Sellable/Bangunan/Bangunan.hpp"

using namespace std;

int main()
{
    // Bangunan b1 = Bangunan(5, 1, "GEDUNG", "GEDUNG", 100, {{"WOOD", 50}, {"STONE", 100}, {"IRON", 20}, {"GOLD", 10}, {"DIAMOND", 5}});

    // cout << "ID: " << b1.getIdBangunan() << ", "
    //      << "Kode: " << b1.getKodeHuruf() << ", "
    //      << "Nama: " << b1.getNamaBarang() << ", "
    //      << "Harga: " << b1.getHargaBarang() << ", "
    //      << "Material: " << endl;

    // for (auto &it : b1.getMaterial())
    // {
    //     cout << it.first << ": " << it.second << endl;
    // }

    Sellable *b1 = new Bangunan(1, "SMALL_HOUSE", "SMALL HOUSE", 50, {{"TEAK_WOOD", 1}, {"SANDAL_WOOD", 1}});
    Sellable *b2 = new Bangunan(1, "SMALL_HOUSE", "SMALL HOUSE", 50, {{"TEAK_WOOD", 1}, {"SANDAL_WOOD", 1}});

    cout << (*b1 == *b2) << endl;

    return 0;
}