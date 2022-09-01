#include "entity.hpp"
#include "player.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../Tools/utils.hpp"
#include "../Tools/GameObjectList.hpp"
#include "bullet.cpp"

class Dummy : public Foe
{
    

    public:

        Dummy(int _y, int _x, GameObjectList *game_objects) : Foe{_y, _x, CHAR_DUMMY, SPEED_FAST, SPEED_BULLET_SLOW, LIFE_DUMMY, POINTS_DUMMY, VIEWRANGE_DUMMY, game_objects}
        {
        }
        

        // void Shoot() {

        //     // spawn bullet
        //     Bullet *bullet = new Bullet(false, 1, 1, 23, y+1, x, gameItems);
        //     gameItems->insert(bullet);
        // }
};