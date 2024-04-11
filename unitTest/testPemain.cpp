#include <iostream>
#include <cassert>
#include "../src/libs/Pemain/Petani/Petani.hpp"
#include "../src/libs/ProdukHewan/ProdukHewan.hpp"

void testPemain() {
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

    ProdukHewan ayam(1, "COM", "Cow Meat", "PRODUK_HEWAN", "Cow", 10, 10);
    Sellable* ayams = &ayam;
    player.inventory.insert(0,0,*ayams);
    player.cetakPenyimpanan();
    assert(player.getKekayaan() == 210);
    // Test makan method
    // Assuming the player's inventory has edible items
    // Ensure makan method modifies the player's inventory correctly
    // Note: This part requires more detailed testing with mocking or stubbing the input stream

    // Test other methods
    // Add more test cases for other methods as needed
}

int main() {
    // Run the test cases
    testPemain();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
