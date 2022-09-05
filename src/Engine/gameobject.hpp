#pragma once

#include "ncurses.h"

// CHAR
#define CHAR_PLAYER 'p'
#define CHAR_DOOR_OPEN '*'
#define CHAR_DOOR_CLOSED_VERTICAL '|'
#define CHAR_DOOR_CLOSED_HORIZONTAL '-'
#define CHAR_DOOR_SHOP 'o'
#define CHAR_DUMMY 'd'
#define CHAR_CROSS_SHOOTER '+'
#define CHAR_X_SHOOTER 'x'
#define CHAR_X_CROSS_SHOOTER '*'
#define CHAR_SMART_SHOOTER 's'
#define CHAR_BULLET '#'
#define CHAR_SHOP '@'
#define CHAR_APPLE 'A'
#define CHAR_KEY 'K'
#define CHAR_LADDER 'H'

// LIFE
#define LIFE_PLAYER 5
#define LIFE_DUMMY 3
#define LIFE_DEFAULT 3

//SPEED
#define SPEED_BULLET_SLOW 110
#define SPEED_BULLET_FAST 40
#define SPEED_SLOWER 35
#define SPEED_SLOW 30
#define SPEED_NORMAL 18
#define SPEED_FAST 10
#define SPEED_FASTER 5

// STUFF in frames
#define DURATION_INVINCIBILITY 120 // in frames, how much to wait before player can take more damage
#define DURATION_BLINK_ANIMATION 60 

// POINTS
#define POINTS_DUMMY 100
#define POINTS_DEFAULT 100

// VIEW RANGE
#define VIEWRANGE_DUMMY 20
#define VIEWRANGE_DEFAULT 20


class GameObjectList;

class GameObject
{

    public:
    
        virtual void DoFrame() = 0; // called once per frame
        virtual void Draw() = 0; // called once per frame, after DoFrame

        // position
        int x; 
        int y;
        int xMax,yMax; // player's window size
        
        char displayChar; // the char displayed on screen for this object
        GameObjectList *gameItems; 
        
};