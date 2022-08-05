#pragma once
#include <ncurses.h>
#include <stdlib.h>
#include "../Engine/map.h"

class Entity
{
    public:
        Entity(int _y, int _x, WINDOW * player_win, char display_char);
        int x,y;
        char displayChar;
    protected:
        int xMax,yMax; // player position and player's window size
        WINDOW * gameWin;
        void showEntity();
        void mvup();
        void mvdown();
        void mvleft();
        void mvright();
        void checkCollision(int x, int y, Map map);
        int roomId;

        //game stats
        int life;
        bool dead;
};