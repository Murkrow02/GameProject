#pragma once

#define PLAYER_CHAR 'p'
#define GAME_DOOR '*'
#define FOE_DUMMY 'd'

class GameObject
{
public:
    virtual void DoFrame() = 0;
    virtual void Draw() = 0;
};