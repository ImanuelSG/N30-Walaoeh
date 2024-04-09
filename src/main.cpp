#include <iostream>
#include "./libs/Exception/Exception.hpp"
#include "./libs/GameWorld/GameWorld.hpp"

using namespace std;

int main()
{
    GameWorld game;
    game.initializeConfigs();
    game.displayHeader();
    string ans;
    cin >> ans;
    game.startGame();

    return 0;
}
