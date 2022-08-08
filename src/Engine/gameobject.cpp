#pragma once

// CHAR
#define CHAR_PLAYER 'p'
#define CHAR_DOOR '*'
#define CHAR_DUMMY 'd'

// LIFE
#define LIFE_PLAYER 5
#define LIFE_DUMMY 3


class GameObject
{
public:
    virtual void DoFrame() = 0;
    virtual void Draw() = 0;
};