#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "Bangunan.cpp"

using namespace std;

int main()
{
     Bangunan b1 = Bangunan(1, "GEDUNG", "GEDUNG", 100, {{"WOOD", 50}, {"STONE", 100}, {"IRON", 20}, {"GOLD", 10}, {"DIAMOND", 5}});

     cout << "ID: " << b1.getIdBangunan() << ", "
          << "Kode: " << b1.getKodeHuruf() << ", "
          << "Nama: " << b1.getNamaBarang() << ", "
          << "Harga: " << b1.getHargaBarang() << ", "
          << "Material: " << endl;

     for (auto &it : b1.getMaterial())
     {
          cout << it.first << ": " << it.second << endl;
     }

     return 0;
}