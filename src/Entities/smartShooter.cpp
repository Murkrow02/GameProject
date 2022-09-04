#include "entity.hpp"
#include "player.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../Tools/utils.hpp"
#include "../Tools/GameObjectList.hpp"
#include "bullet.cpp"


class smartShooter : public Foe
{
    protected:
        int fireRange = 50;

    public:

        smartShooter(int _y, int _x, GameObjectList *game_objects) : Foe{_y, _x, CHAR_SMART_SHOOTER, SPEED_FAST, SPEED_BULLET_FAST, LIFE_DEFAULT, POINTS_DEFAULT, VIEWRANGE_DEFAULT, game_objects, game_objects->difficultyLevel}
        {

        }

        void Shoot() {

            int xDir, yDir, spawnX, spawnY;

            //Detect player direction
            int pX = gameItems->player->x, pY = gameItems->player->y;

            //X
            //Player is east
            if(pX - x > 0)
            {
                spawnX = x+1;
                xDir = 1;
            }
            //Player is south or nord
            else if (pX - x == 0)
            {
                spawnX = x;
                xDir = 0;
            }
            //Player is west
            else 
            {
                spawnX = x-1;
                xDir = -1;
            }

            //Y
            //Player is south
            if(pY - y > 0)
            {
                spawnY = y+1;
                yDir = 1;
            }
                
            //Player is east or west
            else if (pY - y == 0)
            {
                spawnY = y;
                yDir = 0;
            }
                
            //Player is north
            else 
            {
                spawnY = y-1;
                yDir = -1;
            }

            // spawn bullet
            Bullet *smartBullet = new Bullet(false, xDir, yDir, fireRange, spawnY, spawnX, gameItems);
            gameItems->insert(smartBullet);
        }
        
};