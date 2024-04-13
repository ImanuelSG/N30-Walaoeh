#include <iostream>
#include <cassert>
#include "../src/libs/Pemain/Petani/Petani.hpp"
#include "../src/libs/Toko/Sellable/Tanaman/Tanaman.hpp"
#include "../src/libs/GameWorld/GameWorld.hpp"
#include "../src/libs/Exception/Exception.hpp"

void testPetani() {
    // Test constructor and getter methods
    Petani player("John", 100, 50);
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
    
    Tanaman lumut1(3, "BNT", "BANANA_TREE", "FRUIT_PLANT", 2, 4, 3);
    Tanaman lumut(1, "IRN", "IRONWOOD_TREE", "MATERIAL_PLANT", 4, 5, 5);
    Tanaman iron(2, "IRN", "IRONWOOD_TREE", "MATERIAL_PLANT", 4, 5, 5);
    player.inventory.insert(3,4,lumut1);
    player.inventory.insert(0,0,lumut);
    player.inventory.insert(1,1,iron);
    // player.cetakPenyimpanan();
    // player.cetakLadang();
    player.tanam();
    player.tanam();
    player.tanam();
    // player.cetakPenyimpanan();
    // player.cetakLadang();

    player.addPlantAge();
    player.cetakLadang();
    // Test panen
    player.displayInfo();
    cout << endl;
    player.panen();
    player.cetakPenyimpanan();
    player.cetakLadang();
    cout << endl;

    player.displayInfo();


    // Test other methods
    // Add more test cases for other methods as needed
}

int main() {
    // Run the test cases
    try{
    testPetani();

    std::cout << "All tests passed!" << std::endl;
    } catch (InvalidStorageIndexException& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
