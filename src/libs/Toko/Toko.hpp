#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <utility>
#include "Sellable/Hewan/Hewan.hpp"
#include "Sellable/Tanaman/Tanaman.hpp"
#include "Sellable/Produk/Produk.hpp"
#include "Sellable/Produk/ProdukTanamanMaterial/ProdukTanamanMaterial.hpp"
#include "Sellable/Produk/ProdukTanamanBuah/ProdukTanamanBuah.hpp"
#include "Sellable/Produk/ProdukHewan/ProdukHewan.hpp"
#include "Sellable/Bangunan/Bangunan.hpp"
#include "../Exception/Exception.hpp"

using namespace std;

class Toko
{
private:
public:
    vector<pair<Sellable *, int>> items;
    vector<pair<Sellable *, int>> list_bangunan;

    bool isValidItem(int num, string role);

    void MuatHewanTanamanToko();
    void displayAllBuyableItem(string role);
    tuple<Sellable *, int> Beli(int choice, string role, int currentGulden, int quantity);
    int Jual(vector<Sellable *> soldItems, string role);
    void MuatStateToko(ifstream& inputFile);
};
