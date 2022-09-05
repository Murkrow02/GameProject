#pragma once
#include <string>
#include "../Entities/artifact.hpp"
#include "../Tools/GameObjectList.hpp"
using namespace std;

class Ladder : public Artifact
{

public:


    Ladder(int _y, int _x, char display_char, GameObjectList* game_items)  : Artifact(_y, _x, display_char, game_items)
    {
       
    }

protected:

    // override interacted
    void user_interacted()
    {
        
        gameItems->gameMap->generateMap(gameItems->gameWindow, gameItems);
        gameItems->gameMinimap->drawMinimap(*(gameItems->gameMap), 0);
        gameItems->gameMap->createRoom(0);
        mvwaddch(gameItems->gameWindow, y, x, ' ');
        
    }
};