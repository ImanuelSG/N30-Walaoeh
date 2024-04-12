#include <iostream>
#include <cassert>
#include "../src/libs/Pemain/Petani/Petani.hpp"
#include "../src/libs/Toko/Sellable/Tanaman/Tanaman.hpp"

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

    Tanaman lumut(1, "LUM", "Lumut Hijau", "TANAMAN", 3, 4, 10);
    player.inventory.insert(0,0,lumut);
    // player.cetakPenyimpanan();
    // player.cetakLadang();
    player.tanam();
    player.cetakPenyimpanan();
    player.cetakLadang();

    // Test makan method


    // Test other methods
    // Add more test cases for other methods as needed
}

int main() {
    // Run the test cases
    testPetani();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
