#include "../GameWorld/GameWorld.hpp"

GameWorld::GameWorld()
{
}

GameWorld::~GameWorld()
{
}

void GameWorld::startGame()
{
    CommandManager CommandManager;
    while (!ended)
    {

        CommandManager.setIsTakingTurn(true);
        while (CommandManager.getIsTakingTurn())
        {
            string command;
            cin >> command;
            CommandManager.execute(command, listOfPLayers, currPlayerIndex);
        }
        CommandManager.getNextPlayerIndex();
        currPlayerIndex = CommandManager.getNextPlayerIndex();
        checkEndGame();
    }
}

void GameWorld::checkEndGame()
{
    Pemain *currPlayer = listOfPLayers[currPlayerIndex];
    {
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
        }
    }
}

void GameWorld::initializeConfigs()
{
    ended = false;
}

void GameWorld::safeGameState()
{
}

void GameWorld::loadGameState()
{
}

void GameWorld::addPlayer(Pemain &pemain)
{
    bool found = false;
    int index = 0;
    while (!found && index < listOfPLayers.size())
    {
        if (listOfPLayers[index]->getName() > pemain.getName())
        {
            found = true;
            listOfPLayers.insert(listOfPLayers.begin() + index, &pemain);
        }
        index++;
    }
    if (!found)
    {
        listOfPLayers.push_back(&pemain);
    }
}

// 1 2 3 5
// index == 2
// 1 2 3 4 5
// index == 3

// 1 3 4 5
// index == 1
// 1 2 3 4 5
// current player index += 1;
