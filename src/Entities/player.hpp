#pragma once
#include "../Engine/map.h"
#include <ncurses.h>
#include "entity.hpp"

using namespace std;

class Player : Entity
{
    public:
        Player(int _y, int _x, WINDOW * player_win);
        void getmv(int c, Map map);
    private:
};