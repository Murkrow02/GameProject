#include "entity.hpp"
#include "player.hpp"
#include "../Tools/GameObjectList.hpp"
#include "../Tools/utils.hpp"
#include <stdlib.h> 

class Foe : public Entity
{

  private:

    int FrameSkipped = 0;
    int Speed;
    int DamageBlinkLeft = 0;
    int PointsValue;
    int ViewRange = 0;

  protected:
    
    bool CanMove(bool ignorePlayer = false){

      // foe can move only if FrameSkipped == 0 (speed purposes)
      if(FrameSkipped == 0){
        FrameSkipped++;

      // check if landed on player
      if(!ignorePlayer && is_in_range(x,y, gameItems->player->x, gameItems->player->y, 2))
      {
        // player lost life because touched foe
        gameItems->player->Damage();

        // cannot move on player
        return false;
      }

        return true;
      }
      else if(FrameSkipped >= Speed)
        FrameSkipped = 0; // reset, reached speed value
      else
        FrameSkipped++;
        
      // foe cannot move
      return false;
    }


  public:

    Foe(int _y, int _x, char display_char, int speed, int life, int points_value, int view_range, GameObjectList* game_items) : Entity{_y, _x, display_char, life, game_items}
    {
      Speed = speed;
      PointsValue = points_value;
      ViewRange = view_range;
    }

    // override damage
    void Damage() 
    {
        // set player as invincible for a short period of time
        DamageBlinkLeft = DURATION_BLINK_ANIMATION;

        // minus life
        Entity::Damage();

        // check if dead
        if (life <= 0)
        {
          // add points to user
          gameItems->gameStats->add_points(PointsValue);

          // rip
          Destroy();
        }
    }

    void MoveRandom(){
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

    // foe movement
    virtual void DoFrame()
    {
      // used to detect if can update frame
      if (!Foe::CanMove())
        return;

      // check distance from player
      if(distance_two_points(x, y, gameItems->player->x, gameItems->player->y) > ViewRange)
      {
        // can't see player :(
        MoveRandom();
      }else{

        // player in range :0

        // find distance foe to player in x and y axis
        int dX = abs(gameItems->player->x - x);
        int dY = abs(gameItems->player->y - y);

        // need to walk on x axis
        if(dX > dY){
          if (gameItems->player->x > x)
          {
            mvright();
            return;
          }
          else
          {
            mvleft();
            return;
          }
        }
        else // need to walk on y axis
        {
          if (gameItems->player->y > y)
          {
            mvdown();
            return;
          }
          else
          {
            mvup();
            return;
          }
        }
        
        
        

      }
    }

    //override draw
    virtual void Draw()
    {

      // blink by hiding entity each x frames
      int skipFrames = 2; // higher value = slower blink speed
      if (DamageBlinkLeft > 0 && DamageBlinkLeft % skipFrames != 0)
      {
        mvwaddch(gameItems->gameWindow, y, x, ' '); // blink off
      }
      else
      {
        // red color
        wattron(gameItems->gameWindow, COLOR_PAIR(1));
        mvwaddch(gameItems->gameWindow, y, x, displayChar);
        wattroff(gameItems->gameWindow, COLOR_PAIR(1));
      }

      if(DamageBlinkLeft > 0)
        DamageBlinkLeft--;
      
    }


};