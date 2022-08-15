#pragma once

#include "ncurses.h"

// CHAR
#define CHAR_PLAYER 'p'
#define CHAR_DOOR '*'
#define CHAR_DUMMY 'd'
#define CHAR_BULLET '#'
#define CHAR_SHOP '@'
#define CHAR_APPLE 'A'

// LIFE
#define LIFE_PLAYER 5
#define LIFE_DUMMY 3

// STUFF in frames
#define DURATION_INVINCIBILITY 120 // in frames, how much to wait before player can take more damage
#define DURATION_BLINK_ANIMATION 60 

// POINTS
#define POINTS_DUMMY 100

// VIEW RANGE
#define VIEWRANGE_DUMMY 20

class GameObjectList;

class GameObject
{

    public:
        virtual void DoFrame() = 0;
        virtual void Draw() = 0;
        int x;
        int y;
        char displayChar;
        GameObjectList *gameItems;
        
};