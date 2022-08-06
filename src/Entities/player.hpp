#pragma once
#include "../Engine/map.h"
#include <ncurses.h>
#include "entity.hpp"
#include "../Engine/gameobject.cpp"

using namespace std;

class Player : public Entity
{
    public:
        Player(int _y, int _x, WINDOW * player_win);
        void getmv(Map map);
        
    private:
};