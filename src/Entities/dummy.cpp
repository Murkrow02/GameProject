#include "entity.hpp"
#include "foe.cpp"
#include "player.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../Tools/utils.hpp"

class Dummy : public Foe
{
    

    public:

        Dummy(int _y, int _x, WINDOW *player_win, Player *player) : Foe{_y, _x, player_win, player, 'd', SPEED_NORMAL}
        {
        }

        virtual void DoFrame()
        {
            // used to detect if can update frame
            if(!Foe::CanUpdateFrame())
                return;

            srand(time(NULL));

            int i = rand() % 4;
            switch (i)
            {
            case 0:
                Foe::Entity::mvup();
                break;
            case 2:
                Foe::Entity::mvdown();
                break;
            case 1:
                Foe::Entity::mvleft();
                break;
            case 3:
                Foe::Entity::mvright();
                break;

            default:
                break;
            }
        }

        
};