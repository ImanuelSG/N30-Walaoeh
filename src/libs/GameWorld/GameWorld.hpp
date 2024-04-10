#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "../CommandManager/CommandManager.hpp"
#include "../Pemain/Walikota/Walikota.hpp"
#include "../Pemain/Petani/Petani.hpp"
#include "../Pemain/Peternak/Peternak.hpp"
#include "../Bangunan/Bangunan.hpp"

using namespace std;

class GameWorld
{
private:
    int winningGulden;
    int winningWeight;
    vector<Pemain *> listOfPLayers;
    vector<Sellable *> listOfBangunan;
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
