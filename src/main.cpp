#include "./libs/Exception/Exception.hpp"
#include "./libs/GameWorld/GameWorld.hpp"
#include <limits>
using namespace std;

int main()
{
    GameWorld MainGame;

    MainGame.displayHeader();
    MainGame.initializeConfigs();
    cout << endl;
    string ans;
    Toko t;
    t.MuatHewanTanamanToko();
    do
    {
        cout << "Apakah anda ingin memuat state? (y/n) ";
        cin >> ans;

        if (ans != "y" && ans != "n" && ans != "Y" && ans != "N")
        {
            cout << "Input tidak sesuai. Silahkan masukkan 'y' atau 'n'."
                 << endl;
        }

    } while (ans != "y" && ans != "n" && ans != "Y" && ans != "N");

    if (ans == "y" || ans == "Y")
    {
        MainGame.loadGameState(t);
    }
    else
    {
        MainGame.initializeDefaultGame();
    }

    MainGame.startGame();

    return 0;
}
