#include <iostream>
#include <cassert>
#include "../src/libs/Pemain/Peternak/Peternak.hpp"
#include "../src/libs/Toko/Sellable/Hewan/Hewan.hpp"
#include "../src/libs/Toko/Sellable/Produk/ProdukHewan/ProdukHewan.hpp"
#include "../src/libs/Toko/Sellable/Produk/ProdukTanamanBuah/ProdukTanamanBuah.hpp"
#include "../src/libs/Toko/Sellable/Tanaman/Tanaman.hpp"
#include "../src/libs/GameWorld/GameWorld.hpp"
#include "../src/libs/Exception/Exception.hpp"

void testPeternak() {
    // Test constructor and getter methods
    Peternak player("John", 100, 50);
    assert(player.getName() == "John");
    assert(player.getGulden() == 100);
    assert(player.getBerat() == 50);

    // Test setter methods
    player.setName("Alice");
    player.setGulden(200);
    player.setBerat(75);
    assert(player.getName() == "Alice");
    assert(player.getGulden() == 200);
    assert(player.getBerat() == 75);

    // Test getKekayaan method
    // Assuming player's inventory has items with a total value of 300
    assert(player.getKekayaan() == 200);

    GameWorld world;
    world.initializeConfigs();
    Tanaman iron(2, "IRN", "IRONWOOD_TREE", "MATERIAL_PLANT", 4, 5, 5);
    Hewan sapi(3, "COW", "SAPI", "HERBIVORE", 5, 4, 3);
    Hewan *ayam = new Hewan(1, "CHK", "CHICKEN", "OMNIVORE", 4, 5, 5);
    Hewan ular(2, "SNK", "ULAR", "CARNIVORE", 3, 5, 5);
    // 01nMaterial material(3,"IRN","IRON","PRODUK_TANAMAN_MATERIAL","IRONWOOD_TREE",0,1);

    Sellable *food = new ProdukHewan(4,"COM","COW_MEAT","PRODUK_HEWAN","COW",1,1);;
    Sellable *food2 = new ProdukHewan(2,"COM","COW_MEAT","PRODUK_HEWAN","COW",1,1);
    Sellable *food3 = new ProdukTanamanBuah(1,"BNN","BANANA","PRODUK_TANAMAN_BUAH","BANANA_TREE",1,1);
    Sellable *food4 = new ProdukTanamanBuah (2,"BNN","BANANA","PRODUK_TANAMAN_BUAH","BANANA_TREE",1,1);
    Sellable *falseFood = new ProdukTanamanMaterial (3,"IRN","IRON","PRODUK_TANAMAN_MATERIAL","IRONWOOD_TREE",0,1);
    player.inventory.insert(3,4,sapi);
    player.inventory.insert(0,0,*ayam);
    player.inventory.insert(1,1,ular);
    player.inventory.insert(1,2,iron);
    player.inventory.insert(0,1,*food);
    player.inventory.insert(0,3,*food2);
    player.inventory.insert(2,0,*food3);
    player.inventory.insert(2,1,*food4);
    player.inventory.insert(2,2,*falseFood);

    Sellable *item = player.inventory.getElementAddress(0,1);

    cout << "ITEM: " << item->getNamaBarang() << endl;
    player.cetakPenyimpanan();
    player.ternak();
    
    player.cetakPeternakan();
    player.kasihMakan();
    // player.kasihMakan();

    player.cetakPenyimpanan();
    // Test panen
    player.displayInfo();
    // cout << endl;
    player.panen();
    player.cetakPenyimpanan();
    player.cetakPeternakan();
    // cout << endl;

    player.displayInfo();


    // Test other methods
    // Add more test cases for other methods as needed
}

int main() {
    // Run the test cases
    try{
    testPeternak();

    std::cout << "All tests passed!" << std::endl;
    } 
    catch (InvalidProdukException& e)
    {
        cout << e.what() << endl;
    }
    catch (InvalidJenisMakananException& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
