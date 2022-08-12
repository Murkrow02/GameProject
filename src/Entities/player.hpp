#pragma once
#include "../Engine/map.h"
#include <ncurses.h>
#include "entity.hpp"
#include "../Engine/gameobject.cpp"
#include "../UI/stats.hpp"
#include "weapon.cpp"

using namespace std;

class Player : public Entity
{
    public:
        Player(int _y, int _x, GameObjectList *game_objects);

        // convert user input into player move
        void getmv();

        // override
        virtual void DoFrame();
        virtual void Draw();
        void Damage();

        void setWeapon(Weapon *_weapon);
        
    private:
    
        int invincibilityLeft = 0;

        // player weapon
        Weapon *weapon;
        void Shoot(int dirX, int dirY, int spawnX, int spawnY);
        void Reload();

        // override check collision to enter doors
        char checkCollision(int next_y, int next_x) override; 

        // delay stuff
        int next_bullet_delay = 0, reload_delay = 0;
};