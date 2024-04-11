#include "Toko.hpp"

void Toko::MuatHewanTanamanToko() 
{
    Sellable* item;

    for (const auto& hewan : Hewan::animalMap) {
        item = new Hewan(0, get<0>(hewan.second), get<1>(hewan.second), hewan.first, get<2>(hewan.second), 0, get<3>(hewan.second), get<4>(hewan.second));
        if (item != nullptr) {
            items.push_back(make_pair(item, -1));
        }
    }
    for (const auto& tanaman : Tanaman::plantMap) {
        item = new Tanaman(0, get<0>(tanaman.second), get<1>(tanaman.second), tanaman.first, get<2>(tanaman.second), 0, get<3>(tanaman.second), get<4>(tanaman.second));
        if (item != nullptr) {
            items.push_back(make_pair(item, -1));
        }
    }
}

void Toko::MuatStateToko(string path) 
{
    ifstream inputFile(path);
    if (!inputFile.is_open()) {
        throw FileNotFoundException();
    }

    int itemCount;
    inputFile >> itemCount;

    for (int i = 0; i < itemCount; i++) {
        string itemName;
        int quantity;

        inputFile >> itemName >> quantity;

        Sellable* item = nullptr;

        if (Produk::productMap.find(itemName) != Produk::productMap.end()) {
            tuple<int, string, string, string, int, int> product_item_tuple = Produk::productMap[itemName];

            if (get<3>(product_item_tuple) == "PRODUCT_MATERIAL_PLANT") {
                item = new ProdukTanamanMaterial(2, get<0>(product_item_tuple), get<1>(product_item_tuple), itemName, get<3>(product_item_tuple), get<2>(product_item_tuple), get<4>(product_item_tuple), get<5>(product_item_tuple));
                
            } else if (get<3>(product_item_tuple) == "PRODUCT_FRUIT_PLANT") {
                item = new ProdukTanamanBuah(3, get<0>(product_item_tuple), get<1>(product_item_tuple), itemName, get<3>(product_item_tuple), get<2>(product_item_tuple), get<4>(product_item_tuple), get<5>(product_item_tuple));

            } else if (get<3>(product_item_tuple) == "PRODUCT_ANIMAL") {
                item = new ProdukHewan(4, get<0>(product_item_tuple), get<1>(product_item_tuple), itemName, get<3>(product_item_tuple), get<2>(product_item_tuple), get<4>(product_item_tuple), get<5>(product_item_tuple));

            }
        }
        if (Bangunan::list_of_bangunan.find(itemName) != Bangunan::list_of_bangunan.end()) {
            tuple<string, int, map<string, int>, int> bangunan_item_tuple = Bangunan::list_of_bangunan[itemName];

            item = new Bangunan(5, get<3>(bangunan_item_tuple), get<0>(bangunan_item_tuple), itemName, get<1>(bangunan_item_tuple), get<2>(bangunan_item_tuple));
        }

        if (item != nullptr) {
            items.push_back(make_pair(item, quantity));
        }
    }
    inputFile.close();
}