#include "entity.hpp"
#include "foe.cpp"
#include "player.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../Tools/utils.hpp"
#include "../Tools/GameObjectList.hpp"

class Dummy : public Foe
{
    

    public:

        Dummy(int _y, int _x, GameObjectList *game_objects) : Foe{_y, _x, CHAR_DUMMY, SPEED_FAST, LIFE_DUMMY, POINTS_DUMMY, VIEWRANGE_DUMMY, game_objects}
        {
        }

        

        
};