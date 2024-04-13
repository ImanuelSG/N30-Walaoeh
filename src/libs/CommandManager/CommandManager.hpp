#ifndef COMMANDMANAGER_HPP
#define COMMANDMANAGER_HPP

#include <iostream>
#include "../Pemain/Pemain.hpp"
#include "vector"
#include "../Toko/Toko.hpp"
using namespace std;

class CommandManager
{
private:
    int nextPlayerIndex;
    bool isTakingTurn;

public:
    /**
     * @brief Construct a new Command Manager object
     *
     */
    CommandManager();
    /**
     * @brief Destroy the Command Manager object
     *
     */
    ~CommandManager();
    /**
     * @brief Do Something with the command given to them
     *
     * @param what The command string given
     * @param ListOfPlayers List Of Players (IF pemain is walikota, we need to modify this)
     * @param CurrentPlayerIndex To know who is executing the command
     *
     * @return int 1 if the command is invalid, 1 if the command is valid
     */
    int execute(string what, vector<Pemain *> &ListOfPlayers, int CurrentPlayerIndex, Toko &toko);

    /**
     * @brief Get the Next Player Index
     *
     * @return int
     */
    int getNextPlayerIndex();
    /**
     * @brief Set the Is Taking Turn attribute
     *
     * @param isTakingTurn
     */
    void setIsTakingTurn(bool isTakingTurn);
    /**
     * @brief Get the Is Taking Turn attribute
     *
     * @return true
     * @return false
     */
    bool getIsTakingTurn();
};

#endif