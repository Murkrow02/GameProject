#pragma once
#include <string>
#include "../Entities/artifact.hpp"
#include "../Tools/GameObjectList.hpp"
#include "../Engine/map.hpp"
#include "../UI/dialog.hpp"

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
        message newFloor = message("Attenzione", "Stai per accedere al piano successivo");
        newFloor.wait_close.wait();

        clear();
        
        gameItems->gameMap->generateMap(gameItems->gameWindow, gameItems);
        gameItems->gameMinimap->drawMinimap(gameItems, 0);
        gameItems->gameMap->createRoom(0);
        gameItems->player->x = 40;
        gameItems->player->y = 20;
        gameItems->roomsToClear = 9;
        gameItems->difficultyLevel = gameItems->difficultyLevel*1.5;
        
        gameItems->gameStats->update_stats();
        mvwaddch(gameItems->gameWindow, y, x, ' ');
        
    }
};