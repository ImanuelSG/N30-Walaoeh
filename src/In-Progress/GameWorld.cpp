#include "../Coba-Coba/GameWorld.hpp"

#include <iostream>
#include <filesystem>
#include <fstream>

using namespace std;

void GameWorld::Muat(string path) {
    ifstream inputFile(path);
    if (!inputFile.is_open()) {
        throw runtime_error("Failed to open the file.");
    }

    int playerCount;
    string username, role;
    int berat_badan, uang, itemCount;
    vector<string> inventory;

    inputFile >> playerCount;
    inputFile >> username >> role >> berat_badan >> uang;
    inputFile >> itemCount;

    string item;
    for (int i = 0; i < itemCount; i++) {
        inputFile >> item;
        inventory.push_back(item);
    }

    cout << "Username: " << username << endl;
    cout << "Role: " << role << endl;
    cout << "Weight: " << berat_badan << endl;
    cout << "Money: " << uang << endl;
    cout << "Item count: " << itemCount << endl;
    cout << "Inventory:" << endl;
    for (int i = 0; i < itemCount; i++) {
        cout << inventory[i] << endl;
    }

    // Close the file
    inputFile.close();
}

void Simpan(string path) {
    cout << path << endl;
}