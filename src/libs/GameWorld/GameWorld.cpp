#include "../GameWorld/GameWorld.hpp"

GameWorld::GameWorld()
{
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
            int res = CommandManager.execute(command, listOfPLayers, currPlayerIndex);
            cout << endl;

            if (res == 2)
            {
                saveGameState();
            }
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
        if (currPlayer->getGulden() >= 100 && currPlayer->getBerat() >= 100)
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
}

void GameWorld::loadGameState()
{
}
