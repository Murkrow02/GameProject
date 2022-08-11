#pragma once
#include <ncurses.h>
#include <stdlib.h>
#include "../Engine/map.h"
#include "../UI/stats.hpp"
#include "../Engine/gameobject.cpp"

class GameObjectList; //this instead of header because of circular dependency compile error

class Entity : public GameObject
{
    public:
        Entity(int _y, int _x, WINDOW * player_win, char display_char, int _life, GameObjectList *_gameItems, Stats *game_stats);
        char displayChar;
        virtual void Damage(); // life--

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
        virtual char checkCollision(int next_y, int next_x);

        // update entity status
        virtual void DoFrame();
        virtual void Draw();
        void Destroy(); // delete entity from game window
        

        //game stats
        int life;
        Stats* gameStats;
        GameObjectList *gameItems;

};