#pragma once
#include "../Engine/map.h"
#include <ncurses.h>
#include "entity.hpp"
#include "../Engine/gameobject.cpp"
#include "../UI/stats.hpp"

using namespace std;

#define INVINCIBILITY_DURATION 120 // in frames, how much to wait before player can take more damage

class Player : public Entity
{
    public:
        Player(int _y, int _x, WINDOW * player_win, Stats *game_stats, Map* _map);
        void damage(); // player has been attacked
        void getmv();
        Stats* gameStats;
        virtual void DoFrame();
        virtual void Draw();
        
    private:
        int invincibilityLeft = 0;
        Map* map;

        // enter next room
        void doorCollided(); 
};