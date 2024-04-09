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
    void checkEndGame();
    void initializeConfigs();
    void safeGameState();
    void loadGameState();
    void addPlayer(Pemain &pemain);
};
