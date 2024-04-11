#include "CommandManager.hpp"

CommandManager::CommandManager()
{
    nextPlayerIndex = 0;
}

CommandManager::~CommandManager()
{
}

int CommandManager::getNextPlayerIndex()
{
    return nextPlayerIndex;
}

int CommandManager::execute(string what, vector<Pemain *> &ListOfPlayers, int CurrentPlayerIndex)
{
    try
    {
        Pemain *currPlayer = ListOfPlayers[CurrentPlayerIndex];
        if (what == "NEXT")
        {
            nextPlayerIndex++;
            if (nextPlayerIndex >= ListOfPlayers.size())
            {
                nextPlayerIndex = 0;
            }
            isTakingTurn = false;
        }
        else if (what == "CETAK_PENYIMPANAN")
        {
            currPlayer->cetakPenyimpanan();
        }
        else if (what == "PUNGUT_PAJAK")
        {
            currPlayer->pungutPajak(ListOfPlayers);
        }
        else if (what == "CETAK_LADANG")
        {
            currPlayer->cetakLadang();
        }
        else if (what == "CETAK_PETERNAKAN")
        {
            currPlayer->cetakPeternakan();
        }
        else if (what == "TANAM")
        {
            currPlayer->tanam();
        }
        else if (what == "TERNAK")
        {
            currPlayer->ternak();
        }
        else if (what == "BANGUN")
        {
            currPlayer->bangunBangunan();
        }
        else if (what == "MAKAN")
        {
            currPlayer->kasihMakan();
        }
        else if (what == "KASIH_MAKAN")
        {
            currPlayer->kasihMakan();
        }
        else if (what == "BELI")
        {
            currPlayer->beli();
        }
        else if (what == "JUAL")
        {
            currPlayer->jual();
        }
        else if (what == "PANEN")
        {
            currPlayer->panen();
        }
        else if (what == "SIMPAN")
        {
            return -3;
        }
        else if (what == "TAMBAH_PEMAIN")
        {
            int addedPlayerIndex = currPlayer->tambahPemain(ListOfPlayers);
            cout << "addedPlayerIndex: " << addedPlayerIndex << endl;
            if (addedPlayerIndex <= CurrentPlayerIndex)
            {
                // if the player is added behind the current player
                // the next player index and current player index should be incremented

                nextPlayerIndex++;
                CurrentPlayerIndex++;
            }
            return CurrentPlayerIndex;
        }
        else
        {
            throw InvalidInputException();
        }
        return -1;
    }
    catch (InvalidInputException &e)
    {
        cout << e.what() << endl;
        return -2;
    }
    catch (WalikotaInputException &e)
    {
        cout << e.what() << endl;
        return -2;
    }

    catch (NotEnoughMoneyException &e)
    {
        cout << e.what() << endl;
        return -2;
    }
    catch (InvalidStorageIndexException &e)
    {
        cout << e.what() << endl;
        return -2;
    }
    catch (InventoryFullException &e)
    {
        cout << e.what() << endl;
        return -2;
    }
    catch (LadangFullException &e)
    {
        cout << e.what() << endl;
        return -2;
    }
    catch (TernakFullException &e)
    {
        cout << e.what() << endl;
        return -2;
    }
}

void CommandManager::setIsTakingTurn(bool isTakingTurn)
{
    this->isTakingTurn = isTakingTurn;
}

bool CommandManager::getIsTakingTurn()
{
    return isTakingTurn;
}