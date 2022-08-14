#include "artifact.hpp"
#include "ncurses.h"
#include "../Engine/gameobject.hpp"
#include "../Tools/utils.hpp"
#include "../UI/shop.hpp"

Artifact::Artifact(int _y, int _x, char display_char, GameObjectList *_gameItems){

    // set attributes
    y = _y;
    x = _x;
    displayChar = display_char;
    gameItems = _gameItems;
}

void Artifact::DoFrame(){

    // player interacted with artifact
    if (is_in_range(x, y, gameItems->player->x, gameItems->player->y, 2) && gameItems->player->keyPressed == 'e')
    {
        user_interacted();
    }
}

void Artifact::Draw(){

    // green color
    wattron(gameItems->gameWindow, COLOR_PAIR(2));
    mvwaddch(gameItems->gameWindow, y, x, displayChar);
    wattroff(gameItems->gameWindow, COLOR_PAIR(2));
}