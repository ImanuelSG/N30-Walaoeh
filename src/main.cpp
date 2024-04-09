#include "./libs/Exception/Exception.hpp"
#include "./libs/GameWorld/GameWorld.hpp"
#include <limits>
using namespace std;

int main()
{
    GameWorld MainGame;
    MainGame.initializeConfigs();
    MainGame.displayHeader();
    cout << endl;
    char ans;
    do
    {
        cout << "Apakah anda ingin memuat state? (y/n) ";
        cin >> ans;

        if (ans != 'y' && ans != 'n' && ans != 'Y' && ans != 'N')
        {
            cout << "Input tidak sesuai. Silahkan masukkan 'y' atau 'n'." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (ans != 'y' && ans != 'n' && ans != 'Y' && ans != 'N');

    if (ans == 'y' || ans == 'Y')
    {
        MainGame.loadGameState();
    }
    else
    {
        MainGame.initializeDefaultGame();
    }

    MainGame.startGame();

    return 0;
}
