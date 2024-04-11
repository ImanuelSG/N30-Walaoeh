#include <iostream>
#include <vector>
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
    int currPlayerIndex;
    bool ended;

public:
    GameWorld();
    ~GameWorld();
    void startGame();
    void displayHeader();
    void checkEndGame();
    void initializeConfigs();
    void saveGameState();
    void loadGameState();
    void initializeDefaultGame();
};
