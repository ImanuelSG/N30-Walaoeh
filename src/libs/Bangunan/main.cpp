#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "Bangunan.cpp"

using namespace std;

int main()
{
     // Bangunan b1 = Bangunan(5, 1, "HUT", "HUT", 100, 10000, {{"WOOD", 100}, {"STONE", 50}});

     map<string, int> materials = {{"WOOD", 100}, {"STONE", 50}};
     Bangunan b1(5, 1, "HUT", "HUT", 10000, materials);

     cout << "ID: " << b1.getIdBangunan() << ", "
          << "Kode: " << b1.getKodeHurufBangunan() << ", "
          << "Nama: " << b1.getNamaBarang() << ", "
          << "Harga: " << b1.getHargaBarang() << ", "
          << "Material: " << endl;

     for (auto &it : b1.getMaterial())
     {
          cout << it.first << ": " << it.second << endl;
     }

     return 0;
}