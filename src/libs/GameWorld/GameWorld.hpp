#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>
#include "../CommandManager/CommandManager.hpp"
#include "../Toko/Toko.hpp"
#include "../Pemain/Walikota/Walikota.hpp"
#include "../Pemain/Petani/Petani.hpp"
#include "../Pemain/Peternak/Peternak.hpp"
#include "../Utils/Utils.hpp"

using namespace std;


class GameWorld
{
private:
    int winningGulden;
    int winningWeight;
    vector<Pemain *> listOfPLayers;
    int currPlayerIndex;
    bool ended;
    Toko toko;
    string tipegame;

public:
    /**
     * @brief Construct a new Game World object
     *
     */
    GameWorld();
    /**
     * @brief Destroy the Game World object
     *
     */
    ~GameWorld();
    /**
     * @brief Set the Tipe Game attribtue
     * 
     * @param tipegame 
     */
    void setTipeGame(string tipegame);
    /**
     * @brief Method to start the game, basically running all things
     *
     */
    void startGame();
    /**
     * @brief Display the header of the game
     *
     */
    void displayHeader();
    /**
     * @brief Check the endgame condition
     *
     */
    bool checkEndGame();
    /**
     * @brief Initialize all Default Configs
     *
     */
    void initializeConfigs();
    /**
     * @brief load the game configs (winning conditions etc)
     *
     * @param path
     */
    void loadMiscConfig(string path);
    /**
     * @brief Save game state
     *
     */
    void saveGameState();
    /**
     * @brief Load game state
     *
     */
    void loadGameState();
    /**
     * @brief Initialize default game
     *
     */
    void initializeDefaultGame();

};
