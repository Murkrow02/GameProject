#include "entity.hpp"
#include "player.hpp"
#include "../Tools/list.hpp"

class Foe : public Entity
{

  private:

    int FrameSkipped = 0;
    int Speed;
    GameObjectList* gameItems;

  protected:
    
    bool CanMove(){

      // foe can move only if FrameSkipped == 0 (speed purposes)
      if(FrameSkipped == 0){
        FrameSkipped++;

      // check if landed on player
      if(x == gameItems->player->x && y == gameItems->player->y)
      {
        // player lost life because touched foe
        gameItems->player->damage();

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

    Foe(int _y, int _x, WINDOW *game_win, char display_char, int speed, GameObjectList* game_items) : Entity{_y, _x, game_win, display_char}
    {
      Speed = speed;
      gameItems = game_items;
    }

    //override draw
    virtual void Draw()
    {
      // red color
      wattron(gameWin,COLOR_PAIR(1));
      mvwaddch(gameWin, y, x, displayChar);
      wattroff(gameWin,COLOR_PAIR(1));
    }

    void Dispose(){
      gameItems->remove(this);
      Entity::Destroy();
    }
};