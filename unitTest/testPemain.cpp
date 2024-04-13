#include <iostream>
#include <cassert>
#include "../src/libs/Pemain/Petani/Petani.hpp"
#include "../src/libs/Toko/Sellable/Produk/ProdukHewan/ProdukHewan.hpp"

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
    player.inventory.insert(0,0,ayam);
    ProdukHewan babi(2, "PIM", "Pig Meat", "PRODUK_HEWAN", "Pig", 10, 10);
    player.inventory.insert(babi);
    player.cetakPenyimpanan();

    // Test makan method
    cout << player.getBerat() << endl;
    player.makan();
    player.cetakPenyimpanan();
    cout << player.getBerat() << endl;
    assert(player.getKekayaan() == 210);

    // Test other methods
    // Add more test cases for other methods as needed
}

int main() {
    // Run the test cases
    testPemain();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
