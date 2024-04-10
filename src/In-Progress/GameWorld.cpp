#include "../Coba-Coba/GameWorld.hpp"

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// note : kelas dll cuma buat testing

class Plant {
    public:
        int id;
        string code;
        string name;
        string type;
        int duration;
        int price;
};

class Animal {
    public:
        int id;
        string code;
        string name;
        string type;
        int weight;
        int price;
};

class Product {
    public:
        int id;
        string code;
        string name;
        string type;
        string origin;
        int addedWeight;
        int price;
};

class Material {
    public:
        string name;
        int quantity;
};

class Recipe {
    public:
        int id;
        string code;
        string name;
        int price;
        vector<Material> materials;
};

class Plane {
    public:
        int height;
        int width;
};

class Config {
    public:
        int gulden;
        int weight;
        Plane inventory;
        Plane field;
        Plane ranch;
};

void GameWorld::Muat(string path) {
    ifstream inputFile(path);
    if (!inputFile.is_open()) {
        throw runtime_error("Failed to open the file.");
    }

    int playerCount;
    inputFile >> playerCount;

    string username, role;
    int berat_badan, uang, itemCount;
    vector<string> inventory;
    for (int i = 0; i < playerCount; i++) {
        inputFile >> username >> role >> berat_badan >> uang;
        inputFile >> itemCount;

        string item;
        for (int j = 0; j < itemCount; j++) {
            inputFile >> item;
            inventory.push_back(item);
        }

        cout << "Username: " << username << ", Role: " << role << ", Weight: " << berat_badan << ", Money: " << uang << ", Item count: " << itemCount << ", Inventory:" << endl;
        for (int j = 0; j < itemCount; j++) {
            cout << inventory[j] << endl;
        }
        cout << endl;
    }

    inputFile.close();
}

// void Simpan(string path) {
//     cout << path << endl;
// }

void GameWorld::MuatTanaman() {
    ifstream inputFile("../libs/File Config/plant.txt");
    if (!inputFile.is_open()) {
        throw runtime_error("Failed to open the file.");
    }

    std::vector<Plant> plants;

    string line; 
    while (getline(inputFile, line)) {
        istringstream iss(line);
        Plant plant;
        iss >> plant.id >> plant.code >> plant.name >> plant.type >> plant.duration >> plant.price;
        plants.push_back(plant);
    }
    inputFile.close();

    for (const Plant& plant : plants) {
        std::cout << "ID: " << plant.id << ", Code: " << plant.code << ", Name: " << plant.name << ", Type: " << plant.type << ", Duration: " << plant.duration << ", Price: " << plant.price << std::endl;
    }
}

void GameWorld::MuatHewan() {
    ifstream inputFile("../libs/File Config/animal.txt");
    if (!inputFile.is_open()) {
        throw runtime_error("Failed to open the file.");
    }

    std::vector<Animal> animals;

    string line; 
    while (getline(inputFile, line)) {
        istringstream iss(line);
        Animal animal;
        iss >> animal.id >> animal.code >> animal.name >> animal.type >> animal.weight >> animal.price;
        animals.push_back(animal);
    }
    inputFile.close();

    for (const Animal& animal : animals) {
        cout << "ID: " << animal.id << ", Code: " << animal.code << ", Name: " << animal.name << ", Type: " << animal.type << ", Weight: " << animal.weight << ", Price: " << animal.price << endl;
    }
}

void GameWorld::MuatProduk() {
    ifstream inputFile("../libs/File Config/product.txt");
    if (!inputFile.is_open()) {
        throw runtime_error("Failed to open the file.");
    }

    std::vector<Product> products;

    string line; 
    while (getline(inputFile, line)) {
        istringstream iss(line);
        Product product;
        iss >> product.id >> product.code >> product.name >> product.type >> product.origin >> product.addedWeight >> product.price;
        products.push_back(product);
    }
    inputFile.close();

    for (const Product& product : products) {
        cout << "ID: " << product.id << ", Code: " << product.code << ", Name: " << product.name << ", Type: " << product.type << ", Origin: " << product.origin << ", Weight: " << product.addedWeight << ", Price: " << product.price << endl;
    }
}

void GameWorld::MuatResep() {
    ifstream inputFile("../libs/File Config/recipe.txt");
    if (!inputFile.is_open()) {
        throw runtime_error("Failed to open the file.");
    }

    std::vector<Recipe> recipes;

    string line; 
    while (getline(inputFile, line)) {
        istringstream iss(line);
        Recipe recipe;
        iss >> recipe.id >> recipe.code >> recipe.name >> recipe.price;
        
        vector<Material> materials;
        string name;
        int quantity;
        while (iss >> name >> quantity) {
            Material material;
            material.name = name;
            material.quantity = quantity;
            materials.push_back(material);
        }

        recipe.materials = materials;

        recipes.push_back(recipe);
    }
    inputFile.close();

    for (const Recipe& recipe : recipes) {
        cout << "ID: " << recipe.id << ", Code: " << recipe.code << ", Name: " << recipe.name << ", Price: " << recipe.price;
        for (const Material& material : recipe.materials) {
           cout << ", Material: " << material.name << ", Quantity: " << material.quantity; 
        }
        cout << endl;
    }
}

void GameWorld::MuatLainLain() {
    ifstream inputFile("../libs/File Config/misc.txt");
    if (!inputFile.is_open()) {
        throw runtime_error("Failed to open the file.");
    }

    Config config;
    
    inputFile >> config.gulden;
    inputFile >> config.weight;
    inputFile >> config.inventory.height >> config.inventory.width;
    inputFile >> config.field.height >> config.field.width;
    inputFile >> config.ranch.height >> config.ranch.width;

    cout << "Gulden: " << config.gulden << ", Weight: " << config.weight << endl;
    cout << "Inventory Height: " << config.inventory.height << ", Width: " << config.inventory.width << endl;
    cout << "Field Height: " << config.field.height << ", Width: " << config.field.width << endl;
    cout << "Ranch Height: " << config.ranch.height << ", Width: " << config.ranch.width << endl;
}

int main() {
    GameWorld g;
    g.MuatTanaman();
    cout << endl;
    g.MuatHewan();
    cout << endl;
    g.MuatProduk();
    cout << endl;
    g.MuatResep();
    cout << endl;
    g.MuatLainLain();
    cout << endl;
    g.Muat("../../test/input/statein.txt");




    return 0;
}