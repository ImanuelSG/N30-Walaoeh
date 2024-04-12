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

int CommandManager::execute(string what, vector<Pemain *> &ListOfPlayers, int CurrentPlayerIndex, Toko &toko)
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
            for (auto player : ListOfPlayers)
            {
                player->addPlantAge();
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
            currPlayer->makan();
        }
        else if (what == "KASIH_MAKAN")
        {
            currPlayer->kasihMakan();
        }
        else if (what == "BELI")
        {
            currPlayer->beli(toko);
        }
        else if (what == "JUAL")
        {
            currPlayer->jual(toko);
        }
        else if (what == "PANEN")
        {
            currPlayer->panen();
        }
        else if (what == "SIMPAN")
        {
            return -3;
        }
        else if (what == "DISPLAY")
        {
            currPlayer->displayInfo();
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
    // Exceptions for inputs
    catch (NumericException &e)
    {
        cout << e.what() << endl;
        return -2;
    }
    catch (MoreThanZeroException &e)
    {
        cout << e.what() << endl;
        return -2;
    }
    catch (InvalidInputException &e)
    {
        cout << e.what() << endl;
        return -2;
    }
    catch (InvalidSellException &e)
    {
        cout << e.what() << endl;
        return -2;
    }
    // Exception for roles
    catch (WalikotaInputException &e)
    {
        cout << e.what() << endl;
        return -2;
    }
    catch (PeternakInputException &e)
    {
        cout << e.what() << endl;
        return -2;
    }
    catch (PetaniInputException &e)
    {
        cout << e.what() << endl;
        return -2;
    }
    catch (PanenInputException &e)
    {
        cout << e.what() << endl;
        return -2;
    }

    // Exception for full
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

    // Exception for not enough
    catch (NotEnoughMoneyException &e)
    {
        cout << e.what() << endl;
        return -2;
    }
    catch (NotEnoughStockException &e)
    {
        cout << e.what() << endl;
        return -2;
    }
    catch (InventoryNotEnoughException &e)
    {
        cout << e.what() << endl;
        return -2;
    }
    catch (NotEnoughHewanException &e)
    {
        cout << e.what() << endl;
        return -2;
    }
    catch (NotEnoughTanamanException &e)
    {
        cout << e.what() << endl;
        return -2;
    }
    catch (NotEnoughFoodException &e)
    {
        cout << e.what() << endl;
        return -2;
    }
    catch (NotEnoughMaterialException &e)
    {
        cout << e.what() << endl;
        return -2;
    }

    // Exception untuk kosong
    catch (InventoryEmptyException &e)
    {
        cout << e.what() << endl;
        return -2;
    }
    catch (LadangEmptyException &e)
    {
        cout << e.what() << endl;
        return -2;
    }
    catch (TernakEmptyException &e)
    {
        cout << e.what() << endl;
        return -2;
    }

    // Invalid Index

    catch (InvalidStorageIndexException &e)
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