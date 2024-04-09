#include <iostream>
#include <vector>
#include "../CommandManager/CommandManager.hpp"

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
    void addPlayer(Pemain &pemain);
};
