#include "../GameWorld/GameWorld.hpp"
#include  <unistd.h>

GameWorld::GameWorld()
{
    currPlayerIndex = 0;
    ended = false;
    winningGulden = 0;
    winningWeight = 0;
    tipegame = "default";
}

GameWorld::~GameWorld()
{
}

void GameWorld::setTipeGame(string tipegame)
{
    this->tipegame = tipegame;
}
void GameWorld::displayHeader()
{
    const char* header = R"(
                                                         /)   (\
                                                    .-._((,~"~.))_.-,
                                                     `-.   > <   ,-'
                                                       / ,o---o. \      
                                 <3 <3 <3             ( ( .___. ) )     <3 <3 <3
                                                       ) `-----' (
                                                      /`-.__ __.-'\
                                                           ,8.
                                                          /___\
                     /$$      /$$           /$$                                                   /$$$$$$$$                                  
                    | $$  /$ | $$          | $$                                                  |__  $$__/                                  
                    | $$ /$$$| $$  /$$$$$$ | $$  /$$$$$$$  /$$$$$$  /$$$$$$/$$$$   /$$$$$$          | $$  /$$$$$$                            
                    | $$/$$ $$ $$ /$$__  $$| $$ /$$_____/ /$$__  $$| $$_  $$_  $$ /$$__  $$         | $$ /$$__  $$                           
                    | $$$$_  $$$$| $$$$$$$$| $$| $$      | $$  \ $$| $$ \ $$ \ $$| $$$$$$$$         | $$| $$  \ $$                           
                    | $$$/ \  $$$| $$_____/| $$| $$      | $$  | $$| $$ | $$ | $$| $$_____/         | $$| $$  | $$                           
                    | $$/   \  $$|  $$$$$$$| $$|  $$$$$$$|  $$$$$$/| $$ | $$ | $$|  $$$$$$$         | $$|  $$$$$$/                           
                    |__/     \__/ \_______/|__/ \_______/ \______/ |__/ |__/ |__/ \_______/         |__/ \______/                            
           _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _   
   _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _   
 _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_ 
(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)
 (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_) 
   _                                                                                                                             _   
 _( )_                                                                                                                         _( )_ 
(_ o _)    $$\   $$\  $$$$$$\   $$$$$$\          $$\      $$\  $$$$$$\  $$\        $$$$$$\   $$$$$$\  $$$$$$$$\ $$\   $$\     (_ o _)
 (_,_)     $$$\  $$ |$$ ___$$\ $$$ __$$\         $$ | $\  $$ |$$  __$$\ $$ |      $$  __$$\ $$  __$$\ $$  _____|$$ |  $$ |     (_,_) 
   _       $$$$\ $$ |\_/   $$ |$$$$\ $$ |        $$ |$$$\ $$ |$$ /  $$ |$$ |      $$ /  $$ |$$ /  $$ |$$ |      $$ |  $$ |       _   
 _( )_     $$ $$\$$ |  $$$$$ / $$\$$\$$ |$$$$$$\ $$ $$ $$\$$ |$$$$$$$$ |$$ |      $$$$$$$$ |$$ |  $$ |$$$$$\    $$$$$$$$ |     _( )_ 
(_ o _)    $$ \$$$$ |  \___$$\ $$ \$$$$ |\______|$$$$  _$$$$ |$$  __$$ |$$ |      $$  __$$ |$$ |  $$ |$$  __|   $$  __$$ |    (_ o _)
 (_,_)     $$ |\$$$ |$$\   $$ |$$ |\$$$ |        $$$  / \$$$ |$$ |  $$ |$$ |      $$ |  $$ |$$ |  $$ |$$ |      $$ |  $$ |     (_,_) 
   _       $$ | \$$ |\$$$$$$  |\$$$$$$  /        $$  /   \$$ |$$ |  $$ |$$$$$$$$\ $$ |  $$ | $$$$$$  |$$$$$$$$\ $$ |  $$ |       _   
 _( )_     \__|  \__| \______/  \______/         \__/     \__|\__|  \__|\________|\__|  \__| \______/ \________|\__|  \__|     _( )_ 
(_ o _)                                                                                                                       (_ o _)
 (_,_)                                                                                                                         (_,_) 
   _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _   
 _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_ 
(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)
 (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_) 
    )";
    cout << CYAN << header << RESET << endl;
}
void GameWorld::startGame()
{
    CommandManager CommandManager(tipegame);
    cout << "Berikut adalah daftar pemain yang ada dalam permainan ini : " << endl;
    for (int i = 0; i < listOfPLayers.size(); i++)
    {
        cout << i + 1 << ". " << listOfPLayers[i]->getName() << endl;
    }
    cout << endl;
    countdown(3);
    cout << YELLOW << "Game dimulai!" << RESET << endl;
    cout << endl;

    while (!ended)
    {
        CommandManager.setIsTakingTurn(true);
        cout  << "Sekarang giliran " << BOLD << YELLOW << listOfPLayers[currPlayerIndex]->getName() << RESET << " untuk melakukan aksi." << endl;
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

        cout << YELLOW << R"(
     _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _   
 _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_ 
(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)
 (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_) 
   _                                                                                                                                                                _   
 _( )_                                                                                                                                                            _( )_ 
(_ o _)     $$$$$$\   $$$$$$\  $$\   $$\  $$$$$$\  $$$$$$$\   $$$$$$\ $$$$$$$$\ $$\   $$\ $$\        $$$$$$\ $$$$$$$$\ $$$$$$\  $$$$$$\  $$\   $$\  $$$$$$\      (_ o _)
 (_,_)     $$  __$$\ $$  __$$\ $$$\  $$ |$$  __$$\ $$  __$$\ $$  __$$\\__$$  __|$$ |  $$ |$$ |      $$  __$$\\__$$  __|\_$$  _|$$  __$$\ $$$\  $$ |$$  __$$\      (_,_) 
   _       $$ /  \__|$$ /  $$ |$$$$\ $$ |$$ /  \__|$$ |  $$ |$$ /  $$ |  $$ |   $$ |  $$ |$$ |      $$ /  $$ |  $$ |     $$ |  $$ /  $$ |$$$$\ $$ |$$ /  \__|       _   
 _( )_     $$ |      $$ |  $$ |$$ $$\$$ |$$ |$$$$\ $$$$$$$  |$$$$$$$$ |  $$ |   $$ |  $$ |$$ |      $$$$$$$$ |  $$ |     $$ |  $$ |  $$ |$$ $$\$$ |\$$$$$$\       _( )_ 
(_ o _)    $$ |      $$ |  $$ |$$ \$$$$ |$$ |\_$$ |$$  __$$< $$  __$$ |  $$ |   $$ |  $$ |$$ |      $$  __$$ |  $$ |     $$ |  $$ |  $$ |$$ \$$$$ | \____$$\     (_ o _)
 (_,_)     $$ |  $$\ $$ |  $$ |$$ |\$$$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |  $$ |   $$ |  $$ |$$ |      $$ |  $$ |  $$ |     $$ |  $$ |  $$ |$$ |\$$$ |$$\   $$ |     (_,_) 
   _       \$$$$$$  | $$$$$$  |$$ | \$$ |\$$$$$$  |$$ |  $$ |$$ |  $$ |  $$ |   \$$$$$$  |$$$$$$$$\ $$ |  $$ |  $$ |   $$$$$$\  $$$$$$  |$$ | \$$ |\$$$$$$  |       _   
 _( )_      \______/  \______/ \__|  \__| \______/ \__|  \__|\__|  \__|  \__|    \______/ \________|\__|  \__|  \__|   \______| \______/ \__|  \__| \______/      _( )_ 
(_ o _)                                                                                                                                                          (_ o _)
 (_,_)                                                                                                                                                            (_,_) 
   _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _      _   
 _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_ 
(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)(_ o _)
 (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_) \______/  \______/ |__/  \__/ \______/ |__/  |__/|__/  |__/   |__/    \______/ |________/|__/  |__/   |__/   |______/ \______/ |__/  \__/ \______/ 
)" << RESET << endl;

        cout << "Player " << YELLOW << BOLD << currPlayer->getName() << RESET << " wins!" << endl;
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
}

void GameWorld::saveGameState()
{
    // todo: prompt and validate 
    string path;
    bool valid = false;
    int playerCount;

    do
    {

        cout << "Masukkan lokasi berkas state : ";

        cin >> path;

        ofstream testFile(path);
        if (!testFile.is_open())
        {
            cout << "Lokasi berkas tidak valid" << endl;
        }
        else
        {
            valid = true;
        }

    } while (!valid);

    ofstream outputFile(path);

    // write player info
    outputFile << listOfPLayers.size() << endl;
    for (const auto& player : listOfPLayers)
    {
        outputFile << player->getName() << " " << player->getRole() << " " << player->getBerat() << " " << player->getGulden() << endl;

        // write player inventory info
        outputFile << player->getInventory().getNeff() << endl;
        for (int i = 0; i < player->getInventory().getRow(); i++)
        {
            for (int j = 0; j < player->getInventory().getCol(); j++)
            {
                if (player->getInventory().getElementAddress(i, j) != nullptr)
                {
                    outputFile << (player->getInventory().getElementAddress(i, j)->getNamaBarang()) << endl;
                }
            }
        }
        
        // write specific data for each player role
        if (player->getRole() == "Peternak")
        {
            outputFile << player->getPeternakan().getNeff() << endl;
            for (int i = 0; i < player->getPeternakan().getRow(); i++)
            {
                for (int j = 0; j < player->getPeternakan().getCol(); j++)
                {
                    if (player->getPeternakan().getElementAddress(i, j) != nullptr)
                    {
                        outputFile << rowColToPetak(i, j) << " " << player->getPeternakan().getElementAddress(i, j)->getNamaBarang() << " " << player->getPeternakan().getElementAddress(i, j)->getWeight() << endl;
                    }
                }
            }
        }
        else if (player->getRole() == "Petani")
        {
            outputFile << player->getLadang().getNeff() << endl;
            for (int i = 0; i < player->getLadang().getRow(); i++)
            {
                for (int j = 0; j < player->getLadang().getCol(); j++)
                {
                    if (player->getLadang().getElementAddress(i, j) != nullptr)
                    {
                        outputFile << rowColToPetak(i, j) << " " << player->getLadang().getElementAddress(i, j)->getNamaBarang() << " " << player->getLadang().getElementAddress(i, j)->getAge() << endl;
                    }
                }
            }
        }
    }

    toko.SimpanStateToko(outputFile);

    outputFile.close();

    cout << GREEN << "Game State Saved!" << RESET << endl;
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
        if (filesystem::is_directory(path))
        {
            cout << "Path yang diberikan bukan file, silahkan coba lagi" << endl;
        } else {
            ifstream testFile(path);
            if (!testFile.is_open())
            {
                cout << "File tidak ditemukan, silahkan coba lagi" << endl;
            }
            else
            {
                valid = true;
            }
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

            inventory + *item;

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
                int weight, row, col;
                inputFile >> petak >> plantName >> weight;

                tuple<int, string, string, int, int> tanaman_item_tuple = Tanaman::plantMap[plantName];
                tanaman = new Tanaman(get<0>(tanaman_item_tuple), get<1>(tanaman_item_tuple), plantName, get<2>(tanaman_item_tuple), weight, get<3>(tanaman_item_tuple), get<4>(tanaman_item_tuple));

                row = getRowStorage(petak);
                col = getColStorage(petak[0]);
                field.insert(row, col, *tanaman);
            }
            player->setLadang(field);
        }

        listOfPLayers.push_back(player);
    }

    toko.MuatStateToko(inputFile);

    inputFile.close();

    sort(listOfPLayers.begin(), listOfPLayers.end(), [](const Pemain *p1, const Pemain *p2)
         { return p1->getName() < p2->getName(); });

    cout << GREEN << "Game State Loaded!" << RESET << endl;
}
