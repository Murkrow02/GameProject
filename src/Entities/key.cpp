#pragma once
#include <string>
#include "../Entities/artifact.hpp"
#include "../Tools/GameObjectList.hpp"
using namespace std;

class Key : public Artifact
{

public:


    Key(int _y, int _x, char display_char, GameObjectList* game_items)  : Artifact(_y, _x, display_char, game_items)
    {
       
    }

protected:

    // override interacted
    void user_interacted()
    {
        // add life and destroy element only if player has not full life
        gameItems->key = true;
        mvwaddch(gameItems->gameWindow, y, x, ' ');
        gameItems->remove(this);
        
    }
};