#include "Toko.hpp"

void Toko::MuatHewanTanamanToko()
{
    Sellable *item;

    // Load all items from Hewan and Tanaman
    // The animal map is
    // Key = nama animal
    // Value = tuple of
    // 1. id
    // 2. kode huruf
    // 3. type
    // 4. weight to harvest
    // 5. price
    for (const auto &hewan : Hewan::animalMap)
    {
        int id = get<0>(hewan.second);
        string kode = get<1>(hewan.second);
        string namaHewan = hewan.first;
        string tipe = get<2>(hewan.second);
        int weightToHarvest = get<3>(hewan.second);
        int harga = get<4>(hewan.second);
        item = new Hewan(id, kode, namaHewan, tipe, 0, weightToHarvest, harga);
        if (item != nullptr)
        {
            items.push_back(make_pair(item, -1));
        }
    }

    // The tumbuhan map is
    // Key = nama tumbuhan
    // Value = tuple of
    // 1. id
    // 2. kode huruf
    // 3. type
    // 4. duration to harvest
    // 5. price
    for (const auto &tanaman : Tanaman::plantMap)
    {
        int id = get<0>(tanaman.second);
        string kode = get<1>(tanaman.second);
        string namaTumbuhan = tanaman.first;
        string tipe = get<2>(tanaman.second);
        int weightToHarvest = get<3>(tanaman.second);
        int harga = get<4>(tanaman.second);
        item = new Tanaman(id, kode, namaTumbuhan, tipe, 0, weightToHarvest, harga);
        if (item != nullptr)
        {
            items.push_back(make_pair(item, -1));
        }
    }
}

void Toko::MuatStateToko(string path)
{
    ifstream inputFile(path);
    if (!inputFile.is_open())
    {
        throw FileNotFoundException();
    }

    int itemCount;
    inputFile >> itemCount;

    for (int i = 0; i < itemCount; i++)
    {
        string itemName;
        int quantity;

        inputFile >> itemName >> quantity;

        Sellable *item = nullptr;

        if (Produk::productMap.find(itemName) != Produk::productMap.end())
        {
            tuple<int, string, string, string, int, int> product_item_tuple = Produk::productMap[itemName];

            if (get<3>(product_item_tuple) == "PRODUCT_MATERIAL_PLANT")
            {
                item = new ProdukTanamanMaterial(get<0>(product_item_tuple), get<1>(product_item_tuple), itemName, get<3>(product_item_tuple), get<2>(product_item_tuple), get<4>(product_item_tuple), get<5>(product_item_tuple));
            }
            else if (get<3>(product_item_tuple) == "PRODUCT_FRUIT_PLANT")
            {
                item = new ProdukTanamanBuah(get<0>(product_item_tuple), get<1>(product_item_tuple), itemName, get<3>(product_item_tuple), get<2>(product_item_tuple), get<4>(product_item_tuple), get<5>(product_item_tuple));
            }
            else if (get<3>(product_item_tuple) == "PRODUCT_ANIMAL")
            {
                item = new ProdukHewan(get<0>(product_item_tuple), get<1>(product_item_tuple), itemName, get<3>(product_item_tuple), get<2>(product_item_tuple), get<4>(product_item_tuple), get<5>(product_item_tuple));
            }
        }
        if (Bangunan::list_of_bangunan.find(itemName) != Bangunan::list_of_bangunan.end())
        {
            tuple<string, int, map<string, int>, int> bangunan_item_tuple = Bangunan::list_of_bangunan[itemName];

            item = new Bangunan(get<3>(bangunan_item_tuple), get<0>(bangunan_item_tuple), itemName, get<1>(bangunan_item_tuple), get<2>(bangunan_item_tuple));
        }
        if (item != nullptr)
        {
            items.push_back(make_pair(item, quantity));
        }
    }
    inputFile.close();
}

// Display all buyable items

void Toko::displayAllBuyableItem(string role)
{
    cout << "Selamat datang di toko!!" << endl;
    cout << "List of items available for purchase: " << endl;

    cout << "Berikut merupakan hal yang dapat Anda Beli" << endl;
    vector<pair<Sellable *, int>> temp(items);
    if (role != "Walikota")
    {
        // Concat bangunan into displayed
        temp.insert(temp.end(), list_bangunan.begin(), list_bangunan.end());
    }
    int i = 1;
    for (const auto &item : items)
    {

        cout << i << ". " << item.first->getNamaBarang() << " - " << item.first->getHargaBarang() << endl;

        if (item.second != -1)
        {
            cout << " (" << item.second << ")" << endl;
        }
    }
}

int Toko::Beli(Sellable *, string role, int currentGulden, int quantity)
{
    // vector<pair<Sellable *, int>> temp(items);
    // if (role != "Walikota")
    // {
    //     // If the role is not Walikota, then we can buy buildings
    //     temp.insert(temp.end(), list_bangunan.begin(), list_bangunan.end());
    // }
    // for (const auto &item : temp)
    // {
    //     if (item.first->getNamaBarang() == item->getNamaBarang())
    //     {
    //         if (item->getHargaBarang() * quantity > currentGulden)
    //         {
    //             return -1;
    //         }
    //         else
    //         {
    //             return item->getHargaBarang() * quantity;
    //         }
    //     }
    // }
}

int Jual(vector<Sellable *>, string role)
{
}