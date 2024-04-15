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

void Toko::MuatStateToko(ifstream &inputFile)
{
    int itemCount;
    inputFile >> itemCount;

    for (int i = 0; i < itemCount; i++)
    {
        string itemName;
        int quantity;

        inputFile >> itemName >> quantity;

        Sellable *item = nullptr;
        Sellable *bangunan = nullptr;

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

            bangunan = new Bangunan(get<3>(bangunan_item_tuple), get<0>(bangunan_item_tuple), itemName, get<1>(bangunan_item_tuple), get<2>(bangunan_item_tuple));
        }
        if (item != nullptr)
        {
            items.push_back(make_pair(item, quantity));
        }
        if (bangunan != nullptr)
        {
            list_bangunan.push_back(make_pair(bangunan, quantity));
        }
    }
}

void Toko::SimpanStateToko(ofstream &outputFile)
{
    int nonLivingProducts = 0;
    for (const auto &item : items)
    {
        if (item.second != -1)
        {
            nonLivingProducts++;
        }
    }

    outputFile << (nonLivingProducts + list_bangunan.size()) << endl;

    for (const auto &item : items)
    {
        if (item.second != -1)
        {
            outputFile << item.first->getNamaBarang() << " " << item.second << endl;
        }
    }

    for (const auto &bangunan : list_bangunan)
    {
        outputFile << bangunan.first->getNamaBarang() << " " << bangunan.second << endl;
    }
}

// Display all buyable items

void Toko::displayAllBuyableItem(string role)
{
    cout << "Selamat datang di toko!!" << endl;

    cout << "Berikut merupakan hal yang dapat Anda Beli : " << endl;
    vector<pair<Sellable *, int>> temp(items);
    if (role != "Walikota")
    {
        // Concat bangunan into displayed
        temp.insert(temp.end(), list_bangunan.begin(), list_bangunan.end());
    }
    int i = 1;
    for (const auto &item : temp)
    {

        cout << i << ". " << item.first->getNamaBarang() << " - " << item.first->getHargaBarang();

        if (item.second != -1)
        {
            cout << " (" << item.second << ")" << endl;
        }
        else
        {
            cout << endl;
        }
        i++;
    }
}

bool Toko::isValidItem(int num, string role)
{
    int length = items.size();
    if (role != "Walikota")
    {
        length += list_bangunan.size();
    }

    return num >= 1 && num <= length;
}

tuple<Sellable *, int> Toko::Beli(int num, string role, int currentGulden, int quantity)
{
    vector<pair<Sellable *, int>> temp(items);

    if (role != "Walikota")
    {
        // If the role is not Walikota, then we can buy buildings
        temp.insert(temp.end(), list_bangunan.begin(), list_bangunan.end());
    }
    Sellable *chosenItem = temp[num - 1].first;
    int stock = temp[num - 1].second;

    if (stock != -1 && stock < quantity)
    {
        throw NotEnoughStockException();
    }

    int totalBelanja = quantity * temp[num - 1].first->getHargaBarang();

    if (currentGulden < totalBelanja)
    {
        throw NotEnoughMoneyException(totalBelanja - currentGulden);
    }
    // If the bought items is not plant or animal, then descrease the stock
    if (stock != -1)
    {
        if (chosenItem->getJenis() == "BANGUNAN")
        {
            list_bangunan[num - items.size() - 1].second -= quantity;
            if (list_bangunan[num - items.size() - 1].second == 0)
            {
                list_bangunan.erase(list_bangunan.begin() + num - items.size() - 1);
            }
        }
        else
        {
            items[num - 1].second -= quantity;
            if (items[num - 1].second == 0)
            {
                items.erase(items.begin() + num - 1);
            }
        }
    }

    return make_tuple(chosenItem, totalBelanja);
}

int Toko::Jual(vector<Sellable *> soldItems, string role)
{
    // Validate if peternak and petani is selling a building
    if (role == "Petani" || role == "Peternak")
    {
        for (auto &item : soldItems)
        {

            if (item->getJenis() == "BANGUNAN")
            {
                throw InvalidSellException();
            }
        }
    }

    int totalGained = 0;
    for (auto &item : soldItems)
    {
        totalGained += item->getHargaBarang();

        // If the item is not a plant or animal, then add it to the list of items
        if (item->getJenis() != "HEWAN" && item->getJenis() != "TANAMAN")
        {
            // if item not bangunan
            if (item->getJenis() != "BANGUNAN")
            {
                bool found = false;
                for (auto &it : items)
                {
                    // if barang exsist, increase the stock
                    if (*(it.first) == *item)
                    {
                        it.second++;
                        found = true;
                        break;
                    }
                }
                if (!found)
                // if not, add the item to the list
                {
                    items.push_back(make_pair(item->Clone(), 1));
                }
            }
            else
            {

                bool found = false;
                // if the item is a building, check if it exsist and add it to the list of buildings
                for (auto &it : list_bangunan)
                {

                    // if building exsist, increase the stock
                    if (*(it.first) == *item)
                    {
                        it.second++;
                        found = true;
                        break;
                    }
                }
                // if not, add the item to the list
                if (!found)
                {
                    list_bangunan.push_back(make_pair(item->Clone(), 1));
                }
            }
        }
    }
    return totalGained;
}