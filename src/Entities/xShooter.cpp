#include "entity.hpp"
#include "player.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../Tools/utils.hpp"
#include "../Tools/GameObjectList.hpp"
#include "bullet.cpp"


class xShooter : public Foe
{
    protected:
        int fireRange = 20;

    public:

        xShooter(int _y, int _x, GameObjectList *game_objects) : Foe{_y, _x, CHAR_X_SHOOTER, SPEED_FAST, SPEED_BULLET_SLOW, LIFE_DEFAULT, POINTS_DEFAULT, VIEWRANGE_DEFAULT, game_objects}
        {

        }

        void Shoot() {

            // spawn bullets
            Bullet *bullet1 = new Bullet(false, -1, -1, fireRange, y-1, x-1, gameItems);
            Bullet *bullet2 = new Bullet(false, 1, -1, fireRange, y-1, x+1, gameItems);
            Bullet *bullet3 = new Bullet(false, -1, 1, fireRange, y+1, x-1, gameItems);
            Bullet *bullet4 = new Bullet(false, 1, 1, fireRange, y+1, x+1, gameItems);
            gameItems->insert(bullet1);
            gameItems->insert(bullet2);
            gameItems->insert(bullet3);
            gameItems->insert(bullet4);
        }
        
};