#include "entity.hpp"

class Dummy : Entity
{
    

    public:
        Dummy(int _y, int _x, WINDOW *player_win) : Entity{_y, _x, player_win, 'd'}
        {
        }
    
};