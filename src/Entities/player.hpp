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
        Player(int _y, int _x, WINDOW * player_win, Map* _map, GameObjectList *game_objects, Stats *game_stats);

        void getmv();

        // override
        virtual void DoFrame();
        virtual void Draw();
        void Damage();
        
    private:
        int invincibilityLeft = 0;
        Map* map;

        // override check collision to enter doors
        char checkCollision(int next_y, int next_x) override; 
};