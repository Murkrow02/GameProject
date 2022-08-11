#include "../Engine/gameobject.cpp"
#include "entity.hpp"
#include "foe.cpp"
#include "../Tools/list.hpp"

class Bullet : public Foe
{

    public:
    
        virtual void DoFrame()
        {
            // speed purposes
            if(!CanMove(true))
                return;

            // clear old position
            mvwaddch(gameWin, y, x, ' ');
            
            // check if reached end of life
            if(travelledDistance >= range)
            {
                Destroy();
                return;
            }
            // check if contact with player
            else if(x == gameItems->player->x && y == gameItems->player->y)
            {
                // damage player
                gameItems->player->Damage();

                // bullet died
                Destroy();
                return;
            }
            // check if this bullet should damage foe
            else if(damageFoe){
                
                // check if bullet reached any foe
                Entity *collidedWith = gameItems->findEntityAtPos(x, y, this);

                // if collided foe exists damage it
                if(collidedWith != NULL){
                    collidedWith->Damage();
                    Destroy();
                    return;
                }
            }

            // check if bullet reached room walls
            if(nextX == 0 || nextX >= xMax || nextY == 0 || nextY == yMax)
            {
                Destroy();
                return;
            }

            // update how much the bullet did travel
            x = nextX; y = nextY;
            travelledDistance++;
        }

        virtual void Draw(){

            Foe::Draw();

            // new position next frame
            nextY = y + incY; 
            nextX = x + incX;
        }

            
        
        Bullet(bool damage_foe, int inc_x, int inc_y, int _range, int _y, int _x, WINDOW * player_win, GameObjectList *game_objects, Stats *game_stats) : Foe{ _y,  _x, player_win, CHAR_BULLET, SPEED_FASTER, 1, game_objects, game_stats} 
        {
            range = _range;
            incX = inc_x;
            incY = inc_y;
            damageFoe = damage_foe;
            nextX = x; nextY = y;
        }

    private:
        int range;
        int incX, incY;
        int nextX, nextY;
        int travelledDistance = 0;
        bool damageFoe = false;

};