#include "entity.hpp"
#include "player.hpp"

class Foe : public Entity
{

  private:

    int FrameSkipped = 0;
    int Speed;

  protected:
    
    bool CanUpdateFrame(){

      // foe can move only if FrameSkipped == 0
      if(FrameSkipped == 0){
        FrameSkipped++;
        return true;
      }
      else if(FrameSkipped >= Speed)
        FrameSkipped = 0; // reset, reached speed value
      else
        FrameSkipped++;
      
      // FrameSkipped != 0, foe cannot move
      return false;
    }


  public:

    Foe(int _y, int _x, WINDOW *game_win, Player *player, char display_char, int speed) : Entity{_y, _x, game_win, display_char}
    {
      Speed = speed;
    }

      

      void Dispose(){

      }
};