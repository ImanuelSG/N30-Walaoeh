#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "../src/libs/Toko/Toko.hpp"
#include "../src/libs/GameWorld/GameWorld.hpp"

using namespace std;

int main()
{
    GameWorld g;
    g.initializeConfigs();
    Toko t;

    t.MuatStateToko("./src/libs/FileConfig/isitoko.txt");
    t.MuatHewanTanamanToko();

    for (const auto& item : t.items) {
        // Accessing the Sellable object pointer and its quantity
        Sellable* sellableItem = item.first;
        int quantity = item.second;

        // Printing the details of the Sellable object
        std::cout << "Name: " << sellableItem->getNamaBarang() << std::endl;
        // std::cout << "Code: " << sellableItem->getKod << std::endl;
        std::cout << "Price: " << sellableItem->getHargaBarang() << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
        std::cout << std::endl;
    }

    return 0;
}