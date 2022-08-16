#include "../Engine/gameobject.hpp"
#include "entity.hpp"
#include "foe.cpp"
#include "../Tools/GameObjectList.hpp"
#include "string"

class Bullet : public Foe
{

    public:
    
        virtual void DoFrame()
        {
            // speed purposes
            if(!CanMove(true))
                return;

            // clear old position
            mvwaddch(gameItems->gameWindow, y, x, ' ');
            
            // check if reached end of life
            if(travelledDistance >= range)
            {
                Destroy();
                return;
            }
            // check if contact with player
            else if(!damageFoe)
            {
                // check contact with player or passed through player
                if((gameItems->player->x == x && gameItems->player->y == y) || EntityPassedThroughBullet(gameItems->player))
                {
                    // damage player
                    gameItems->player->Damage();

                    // bullet died
                    Destroy();
                    return;
                }
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
                else
                {
                    // check if bullet passed through enemy
                    Entity *passedThrough = gameItems->findEntityAtPos(oldX, oldY, this);
                    if(passedThrough != NULL && EntityPassedThroughBullet(passedThrough)){
                        passedThrough->Damage();
                        Destroy();
                        return;
                    }
                }
            }

            // check if bullet reached room walls
            if(nextX == 0 || nextX >= xMax || nextY == 0 || nextY == yMax)
            {
                Destroy();
                return;
            }

            // update how much the bullet did travel
            oldX = x; oldY = y;
            x = nextX; y = nextY;
            travelledDistance++;
        }

        virtual void Draw(){

            Foe::Draw();

            // new position next frame
            nextY = y + incY; 
            nextX = x + incX;
        }

            
        
        Bullet(bool damage_foe, int inc_x, int inc_y, int _range, int _y, int _x, GameObjectList *game_objects) : Foe{ _y,  _x, CHAR_BULLET, SPEED_FASTER, 1, 0, 0, game_objects} 
        {
            range = _range;
            incX = inc_x;
            incY = inc_y;
            damageFoe = damage_foe;
            nextX = x; nextY = y;

            // detect bullet hit direction
            if(inc_x>0 && inc_y==0)
                hitDirection = 'l';
            else if(inc_x < 0 && inc_y==0)
                hitDirection = 'r';
            else if(inc_y > 0 && inc_x==0)
                hitDirection = 'u';
            else if(inc_y < 0 && inc_x==0)
                hitDirection = 'd';
            else hitDirection = 'n';
        }

        // this is used because if entity moves a step forward to the bullet it gets no damage because never lands on bullet spot        
        bool EntityPassedThroughBullet(Entity* entity){

            // check if player new direction is equal to the bullet hit direction (passed through bullet)
            return entity->direction == hitDirection;
        }

    private:
        char hitDirection; // if player is coming from right, is hit by bullet coming from left etc.
        int range;
        int incX, incY;
        int nextX, nextY;
        int travelledDistance = 0;
        bool damageFoe = false;

};