#include "../GameWorld/GameWorld.hpp"

GameWorld::GameWorld()
{
    currPlayerIndex = 0;
    ended = false;
    winningGulden = 0;
    winningWeight = 0;
}

GameWorld::~GameWorld()
{
}

void GameWorld::displayHeader()
{
    cout << R"(
 /$$      /$$           /$$                                                   /$$$$$$$$                                  
| $$  /$ | $$          | $$                                                  |__  $$__/                                  
| $$ /$$$| $$  /$$$$$$ | $$  /$$$$$$$  /$$$$$$  /$$$$$$/$$$$   /$$$$$$          | $$  /$$$$$$                            
| $$/$$ $$ $$ /$$__  $$| $$ /$$_____/ /$$__  $$| $$_  $$_  $$ /$$__  $$         | $$ /$$__  $$                           
| $$$$_  $$$$| $$$$$$$$| $$| $$      | $$  \ $$| $$ \ $$ \ $$| $$$$$$$$         | $$| $$  \ $$                           
| $$$/ \  $$$| $$_____/| $$| $$      | $$  | $$| $$ | $$ | $$| $$_____/         | $$| $$  | $$                           
| $$/   \  $$|  $$$$$$$| $$|  $$$$$$$|  $$$$$$/| $$ | $$ | $$|  $$$$$$$         | $$|  $$$$$$/                           
|__/     \__/ \_______/|__/ \_______/ \______/ |__/ |__/ |__/ \_______/         |__/ \______/                            
                                                                                                                         
                                                                                                                         
                                                                                                                         
 /$$   /$$  /$$$$$$   /$$$$$$          /$$      /$$  /$$$$$$  /$$        /$$$$$$   /$$$$$$  /$$$$$$$$ /$$   /$$       /$$
| $$$ | $$ /$$__  $$ /$$$_  $$        | $$  /$ | $$ /$$__  $$| $$       /$$__  $$ /$$__  $$| $$_____/| $$  | $$      | $$
| $$$$| $$|__/  \ $$| $$$$\ $$        | $$ /$$$| $$| $$  \ $$| $$      | $$  \ $$| $$  \ $$| $$      | $$  | $$      | $$
| $$ $$ $$   /$$$$$/| $$ $$ $$ /$$$$$$| $$/$$ $$ $$| $$$$$$$$| $$      | $$$$$$$$| $$  | $$| $$$$$   | $$$$$$$$      | $$
| $$  $$$$  |___  $$| $$\ $$$$|______/| $$$$_  $$$$| $$__  $$| $$      | $$__  $$| $$  | $$| $$__/   | $$__  $$      |__/
| $$\  $$$ /$$  \ $$| $$ \ $$$        | $$$/ \  $$$| $$  | $$| $$      | $$  | $$| $$  | $$| $$      | $$  | $$          
| $$ \  $$|  $$$$$$/|  $$$$$$/        | $$/   \  $$| $$  | $$| $$$$$$$$| $$  | $$|  $$$$$$/| $$$$$$$$| $$  | $$       /$$
|__/  \__/ \______/  \______/         |__/     \__/|__/  |__/|________/|__/  |__/ \______/ |________/|__/  |__/      |__/)"
         << endl;
}
void GameWorld::startGame()
{
    CommandManager CommandManager;
    cout << "Berikut adalah daftar pemain yang ada dalam permainan ini : " << endl;
    for (int i = 0; i < listOfPLayers.size(); i++)
    {
        cout << i + 1 << ". " << listOfPLayers[i]->getName() << endl;
    }
    cout << endl;
    countdown(3);
    cout << "Game dimulai!" << endl;
    cout << endl;

    while (!ended)
    {
        CommandManager.setIsTakingTurn(true);
        cout << "Sekarang giliran " << listOfPLayers[currPlayerIndex]->getName() << " untuk melakukan aksi." << endl;
        cout << endl;
        while (CommandManager.getIsTakingTurn())
        {
            cout << "> ";
            string command;
            cin >> command;
            // res = -1 is normal exit
            // res = -2 is exception exit
            // res = -3 is save game
            // res >= 0 is the change to current player index
            int res = CommandManager.execute(command, listOfPLayers, currPlayerIndex, toko);
            cout << endl;

            if (res == -3)
            {
                saveGameState();
            }
            else if (res >= 0)
            {
                currPlayerIndex = res;
            }
            if (checkEndGame())
            {
                CommandManager.setIsTakingTurn(false);
            }
        }
        currPlayerIndex = CommandManager.getNextPlayerIndex();
    }
}

bool GameWorld::checkEndGame()
{
    Pemain *currPlayer = listOfPLayers[currPlayerIndex];

    if (currPlayer->getGulden() >= winningGulden && currPlayer->getBerat() >= winningWeight)
    {

        cout << R"(
  /$$$$$$   /$$$$$$  /$$   /$$  /$$$$$$  /$$$$$$$   /$$$$$$  /$$$$$$$$ /$$   /$$ /$$        /$$$$$$  /$$$$$$$$ /$$$$$$  /$$$$$$  /$$   /$$  /$$$$$$ 
 /$$__  $$ /$$__  $$| $$$ | $$ /$$__  $$| $$__  $$ /$$__  $$|__  $$__/| $$  | $$| $$       /$$__  $$|__  $$__/|_  $$_/ /$$__  $$| $$$ | $$ /$$__  $$
| $$  \__/| $$  \ $$| $$$$| $$| $$  \__/| $$  \ $$| $$  \ $$   | $$   | $$  | $$| $$      | $$  \ $$   | $$     | $$  | $$  \ $$| $$$$| $$| $$  \__/
| $$      | $$  | $$| $$ $$ $$| $$ /$$$$| $$$$$$$/| $$$$$$$$   | $$   | $$  | $$| $$      | $$$$$$$$   | $$     | $$  | $$  | $$| $$ $$ $$|  $$$$$$ 
| $$      | $$  | $$| $$  $$$$| $$|_  $$| $$__  $$| $$__  $$   | $$   | $$  | $$| $$      | $$__  $$   | $$     | $$  | $$  | $$| $$  $$$$ \____  $$
| $$    $$| $$  | $$| $$\  $$$| $$  \ $$| $$  \ $$| $$  | $$   | $$   | $$  | $$| $$      | $$  | $$   | $$     | $$  | $$  | $$| $$\  $$$ /$$  \ $$
|  $$$$$$/|  $$$$$$/| $$ \  $$|  $$$$$$/| $$  | $$| $$  | $$   | $$   |  $$$$$$/| $$$$$$$$| $$  | $$   | $$    /$$$$$$|  $$$$$$/| $$ \  $$|  $$$$$$/
 \______/  \______/ |__/  \__/ \______/ |__/  |__/|__/  |__/   |__/    \______/ |________/|__/  |__/   |__/   |______/ \______/ |__/  \__/ \______/ 
)" << endl;

        cout << "Player " << currPlayer->getName() << " wins!" << endl;
        cout << "See You Next Time !" << endl;
        ended = true;
        return true;
    }
    return false;
}

void GameWorld::loadMiscConfig(string path)
{
    ifstream inputFile(path);
    if (!inputFile.is_open())
    {
        throw FileNotFoundException();
    }

    int inventoryN, inventoryM, fieldN, fieldM, ranchN, ranchM;
    inputFile >> winningGulden;
    inputFile >> winningWeight;
    inputFile >> inventoryN >> inventoryM;
    inputFile >> fieldN >> fieldM;
    inputFile >> ranchN >> ranchM;

    Pemain::setUkuranInventoryN(inventoryN);

    Pemain::setUkuranInventoryM(inventoryM);
    Petani::setUkuranLadangN(fieldN);
    Petani::setUkuranLadangM(fieldM);
    Peternak::setUkuranTernakN(ranchN);
    Peternak::setUkuranTernakM(ranchM);

    // cout << "Gulden: " << winningGulden << ", Weight: " << winningWeight << endl;
    // cout << "Inventory Height: " << Pemain::getUkuranInventoryN() << ", Width: " << Pemain::getUkuranInventoryM() << endl;
    // cout << "Field Height: " << Petani::getUkuranLadangN() << ", Width: " << Petani::getUkuranLadangM() << endl;
    // cout << "Ranch Height: " << Peternak::getUkuranTernakN() << ", Width: " << Peternak::getUkuranTernakM() << endl;
}

void GameWorld::initializeConfigs()
{
    loadMiscConfig("./src/libs/FileConfig/misc.txt");
    Hewan::loadHewanConfig("./src/libs/FileConfig/animal.txt");
    Produk::loadProductConfig("./src/libs/FileConfig/product.txt");
    Produk::loadProductOriginConfig("./src/libs/FileConfig/product.txt");
    Tanaman::loadTanamanConfig("./src/libs/FileConfig/plant.txt");
    Bangunan::loadBangunanConfig("./src/libs/FileConfig/recipe.txt");
    toko.MuatHewanTanamanToko();
}

void GameWorld::initializeDefaultGame()
{
    Pemain *pemain1 = new Petani("Petani1", 50, 40);
    Pemain *pemain2 = new Peternak("Peternak1", 50, 40);
    Pemain *pemain3 = new Walikota("Walikota", 50, 40);

    listOfPLayers.push_back(pemain1);
    listOfPLayers.push_back(pemain2);
    listOfPLayers.push_back(pemain3);

    // map<string, int> daftarMaterial;

    // Sellable *item = new Bangunan(1, "SMH", "SMALL_HOUSE", 50, daftarMaterial);
    // vector<Sellable *> items;
    // items.push_back(item);
    // toko.MuatHewanTanamanToko();
    // int res = toko.Jual(items, "Walikota");
    // cout << res << endl;
    // toko.displayAllBuyableItem("Petani");
}

void GameWorld::saveGameState()
{
    cout << "Game State Saved!" << endl;
}

void GameWorld::loadGameState()
{
    string path;
    bool valid = false;
    int playerCount;

    do
    {

        cout << "Masukkan lokasi berkas state: ";

        cin >> path;

        ifstream testFile(path);
        if (!testFile.is_open())
        {
            cout << "File tidak ditemukan, silahkan coba lagi" << endl;
        }
        else
        {
            valid = true;
        }

    } while (!valid);

    ifstream inputFile(path);

    inputFile >> playerCount;
    string username, role;
    int berat_badan, uang, itemCount;

    for (int i = 0; i < playerCount; i++)
    {
        inputFile >> username >> role >> berat_badan >> uang;

        Pemain *player;
        inputFile >> itemCount;
        string itemName;
        Sellable *item = nullptr;

        if (role == "Peternak")
        {
            player = new Peternak(username, uang, berat_badan);
        }
        else if (role == "Petani")
        {
            player = new Petani(username, uang, berat_badan);
        }
        else if (role == "Walikota")
        {
            player = new Walikota(username, uang, berat_badan);
        }

        Storage<Sellable> inventory(Pemain::getUkuranInventoryN(), Pemain::getUkuranInventoryM());

        for (int j = 0; j < itemCount; j++)
        {
            inputFile >> itemName;

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
            if (Hewan::animalMap.find(itemName) != Hewan::animalMap.end())
            {
                tuple<int, string, string, int, int> hewan_item_tuple = Hewan::animalMap[itemName];

                item = new Hewan(get<0>(hewan_item_tuple), get<1>(hewan_item_tuple), itemName, get<2>(hewan_item_tuple), 0, get<3>(hewan_item_tuple), get<4>(hewan_item_tuple));
            }
            if (Tanaman::plantMap.find(itemName) != Tanaman::plantMap.end())
            {
                tuple<int, string, string, int, int> tanaman_item_tuple = Tanaman::plantMap[itemName];

                item = new Tanaman(get<0>(tanaman_item_tuple), get<1>(tanaman_item_tuple), itemName, get<2>(tanaman_item_tuple), 0, get<3>(tanaman_item_tuple), get<4>(tanaman_item_tuple));
            }

            inventory.insert(*item);

            // todo : insert item into player's inventory
        }

        player->setInventory(inventory);

        // todo : insert inventory into inventory

        if (role == "Peternak")
        {
            int ranch_animals;
            inputFile >> ranch_animals;

            Storage<Hewan> ranch(Peternak::getUkuranTernakN(), Peternak::getUkuranTernakM());
            for (int i = 0; i < ranch_animals; i++)
            {
                Hewan *hewan = nullptr;
                string petak, animalName;
                int weight, row, col;
                inputFile >> petak >> animalName >> weight;

                tuple<int, string, string, int, int> hewan_item_tuple = Hewan::animalMap[animalName];
                hewan = new Hewan(get<0>(hewan_item_tuple), get<1>(hewan_item_tuple), animalName, get<2>(hewan_item_tuple), weight, get<3>(hewan_item_tuple), get<4>(hewan_item_tuple));
                row = getRowStorage(petak);
                col = getColStorage(petak[0]);
                ranch.insert(row, col, *hewan);
            }

            player->setPeternakan(ranch);
        }

        // to
        if (role == "Petani")
        {
            int field_plants;
            inputFile >> field_plants;
            Storage<Tanaman> field(Petani::getUkuranLadangN(), Petani::getUkuranLadangM());

            for (int i = 0; i < field_plants; i++)
            {
                Tanaman *tanaman = nullptr;
                string petak, plantName;
                int weight;
                inputFile >> petak >> plantName >> weight;

                tuple<int, string, string, int, int> tanaman_item_tuple = Tanaman::plantMap[plantName];
                tanaman = new Tanaman(get<0>(tanaman_item_tuple), get<1>(tanaman_item_tuple), plantName, get<2>(tanaman_item_tuple), weight, get<3>(tanaman_item_tuple), get<4>(tanaman_item_tuple));

                field.insert(*tanaman);
            }
            player->setLadang(field);
        }

        listOfPLayers.push_back(player);
    }

    toko.MuatStateToko(inputFile);

    inputFile.close();

    sort(listOfPLayers.begin(), listOfPLayers.end(), [](const Pemain *p1, const Pemain *p2)
         { return p1->getName() < p2->getName(); });

    cout << "Game State Loaded!" << endl;
}
