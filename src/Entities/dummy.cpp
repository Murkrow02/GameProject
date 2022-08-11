#include "entity.hpp"
#include "foe.cpp"
#include "player.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../Tools/utils.hpp"
#include "../Tools/list.hpp"

class Dummy : public Foe
{
    

    public:

        Dummy(int _y, int _x, WINDOW *player_win, GameObjectList *game_objects, Stats *game_stats) : Foe{_y, _x, player_win, CHAR_DUMMY, SPEED_FAST, LIFE_DUMMY, POINTS_DUMMY, VIEWRANGE_DUMMY, game_objects, game_stats}
        {
        }

        

        
};