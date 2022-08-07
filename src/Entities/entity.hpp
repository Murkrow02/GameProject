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

        // returns the char encountered in next move
        char checkCollision(int next_y, int next_x);

        // update entity status
        virtual void DoFrame();
        virtual void Draw();
        void Destroy(); // delete entity from game window

        //game stats
        int life;
        bool dead;
};