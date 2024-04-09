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

void CommandManager::execute(string what, vector<Pemain *> &ListOfPlayers, int CurrentPlayerIndex)
{
    Pemain *currPlayer = ListOfPlayers[CurrentPlayerIndex];
    if (what == "NEXT")
    {
    }
    else if (what == "CETAK_PENYIMPANAN")
    {
    }
    else if (what == "PUNGUT_PAJAK")
    {
    }
    else if (what == "CETAK_LADANG")
    {
    }
    else if (what == "CETAK_PETERNAKAN")
    {
    }
    else if (what == "TANAM")
    {
    }
    else if (what == "TERNAK")
    {
    }
    else if (what == "BANGUN")
    {
    }
    else if (what == "MAKAN")
    {
    }
    else if (what == "KASIH_MAKAN")
    {
    }
    else if (what == "BELI")
    {
    }
    else if (what == "JUAL")
    {
    }
    else if (what == "PANEN")
    {
    }
    else if (what == "SIMPAN")
    {
    }
    else if (what == "TAMBAH_PEMAIN")
    {
    }
    else
    {
        throw;
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