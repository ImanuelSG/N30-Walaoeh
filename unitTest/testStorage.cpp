#include "../src/libs/Pemain/Storage/Storage.hpp"
#include "../src/libs/Toko/Sellable/Sellable.hpp"
#include "../src/libs/Toko/Sellable/Produk/ProdukTanamanBuah/ProdukTanamanBuah.hpp"
#include "../src/libs/Toko/Sellable/Produk/ProdukTanamanMaterial/ProdukTanamanMaterial.hpp"
#include "../src/libs/Toko/Sellable/Produk/ProdukHewan/ProdukHewan.hpp"

#include <cassert>

void testStorage()
{
    // Create a storage with 2 rows and 3 columns
    Storage<Sellable> storage(4, 5);

    // Test isEmpty() function
    assert(storage.isEmpty());

    // Test isFull() function
    assert(!storage.isFull());

    // Test insert() function

    Sellable *product1 = new ProdukHewan(1, "SNM", "SNAKE_MEAT", "HOHO", "SNK", 10, 10);
    Sellable *product2 = new ProdukHewan(2, "CMT", "SNAKE_MEAT", "HOHO", "COW", 10, 10);
    Sellable *product3 = new ProdukTanamanBuah(3, "GAP", "GUAVA", "GUAVA_TREE", 10, 10);
    Sellable *product4 = new ProdukTanamanBuah(4, "BNP", "BANANA", "BANANA_TREE", 10, 10);
    Sellable *product5 = new ProdukTanamanMaterial(5, "TAW", "TEAK_WOOD", "TEAK_TREE", 10, 10);
    Sellable *product6 = new ProdukTanamanMaterial(6, "SAW", "SANDALWOOD_WOOD", "SANDALWOOD_TREE", 10, 10);

    storage.insert(0, 0, *product1);
    storage.insert(0, 1, *product2);
    storage.insert(0, 2, *product3);
    storage.insert(1, 0, *product4);
    storage.insert(1, 1, *product5);
    storage.insert(1, 2, *product6);

    // Test getElement() function

    // Test deleteAt() function

    // Test isEmpty() function after deletion

    Sellable product6_deleted = storage.deleteAt(1, 2);
    assert(!storage.isEmpty());

    // Test isFull() function after insertion

    display(storage);

    cout << product6_deleted.getNamaBarang() << endl;
}

int main()
{
    testStorage();
    return 0;
}
