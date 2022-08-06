#pragma once
#include <ncurses.h>
#include <stdlib.h>
#include "../Engine/map.h"
#include "../Engine/gameobject.cpp"

class Entity : public GameObject
{
    public:
        Entity(int _y, int _x, WINDOW * player_win, char display_char);
        int x,y;
        char displayChar;
    protected:

        int xMax,yMax; // player position and player's window size
        WINDOW * gameWin;
        int roomId;

        // movement
        void mvup();
        void mvdown();
        void mvleft();
        void mvright();
        void checkCollision(int x, int y, Map map);

        // update entity status
        virtual void DoFrame();
        virtual void Draw();

        //game stats
        int life;
        bool dead;
};