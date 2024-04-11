#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <utility>
#include "../Hewan/Hewan.hpp"
#include "../Tanaman/Tanaman.hpp"
#include "../Produk/Produk.hpp"
#include "../ProdukTanamanMaterial/ProdukTanamanMaterial.hpp"
#include "../ProdukTanamanBuah/ProdukTanamanBuah.hpp"
#include "../ProdukHewan/ProdukHewan.hpp"
#include "../Bangunan/Bangunan.hpp"
#include "../Exception/Exception.hpp"

using namespace std;

class Toko
{
private:

public:
    vector<pair<Sellable*, int>> items;

    void MuatHewanTanamanToko();
    void MuatStateToko(string path);
};
