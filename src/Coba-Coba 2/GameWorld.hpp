#ifndef GAMEWORLD_HPP
#define GAMEWORLD_HPP

#include "Pemain.hpp"
#include <vector>
#include <memory>

using namespace std;

class GameWorld
{
private:
    vector<shared_ptr<Pemain>> pemain;

public:
    void TambahPemain(const shared_ptr<Pemain> &player)
    {
        pemain.push_back(player);
    }

};

#endif
