#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "../CommandManager/CommandManager.hpp"
#include "../Toko/Sellable/Hewan/Hewan.hpp"
#include "../Toko/Sellable/Tanaman/Tanaman.hpp"
#include "../Toko/Sellable/Produk/Produk.hpp"
#include "../Toko/Sellable/Bangunan/Bangunan.hpp"
#include "../Pemain/Walikota/Walikota.hpp"
#include "../Pemain/Petani/Petani.hpp"
#include "../Pemain/Peternak/Peternak.hpp"

using namespace std;

class GameWorld
{
private:
    int winningGulden;
    int winningWeight;
    vector<Pemain *> listOfPLayers;
    int currPlayerIndex;
    bool ended;

public:
    GameWorld();
    ~GameWorld();
    void startGame();
    void displayHeader();
    void checkEndGame();
    void initializeConfigs();
    void loadMiscConfig(string path);
    void saveGameState();
    void loadGameState();
    void initializeDefaultGame();
};
