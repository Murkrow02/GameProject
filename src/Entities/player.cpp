#include <iostream>
#include <ncurses.h>
#include "player.hpp"
#include "entity.hpp"
#include "../Tools/list.hpp"
#include "../Entities/bullet.cpp"

using namespace std;

Player::Player(int _y, int _x, WINDOW * player_win, Map* _map, GameObjectList *game_objects, Stats *game_stats) : Entity{ _y,  _x, player_win, CHAR_PLAYER, LIFE_PLAYER , game_objects, game_stats} 
{
  gameStats = game_stats;
  map = _map;
  Draw();
}
  

  void Player::DoFrame()
  {
    // check if has to lower
    if(invincibilityLeft > 0){
        invincibilityLeft--;
    }
  }

  void Player::Damage(){

    //check if is invincible
    if(invincibilityLeft == 0)
    {
      // set player as invincible for a short period of time
      invincibilityLeft = INVINCIBILITY_DURATION;

      // update stats
      gameStats->lost_life();

      // run default damage function
      Entity::Damage();

      // check game over
      if(life <= 0)
        /// TODO: change
        exit(1); 
        
    }

  }


  // override draw function
  void Player::Draw(){

    // blink by hiding player each x frames
    if(invincibilityLeft > 0){
      int skipFrames = 2; //higher value = slower blink speed

      if(invincibilityLeft%skipFrames == 0)
        mvwaddch(gameWin, y, x, displayChar); //blink on
      else
        mvwaddch(gameWin, y, x, ' '); //blink off
    }else{

      // no invincibility, draw normally
      mvwaddch(gameWin, y, x, displayChar);
    }
  }
  char Player::checkCollision(int nextY, int nextX)
  {
    Room cRoom = map->rooms[roomId];

    pair<int, int> roomCords = cRoom.coords;

    char collidedChar = mvwinch(gameWin, nextY, nextX);
    if (collidedChar == '*'){
    // clear player old position
    mvwaddch(gameWin, y, x, ' ');

    // left
    if (x <= 1)
    {
      roomId = map->floor[roomCords.first][roomCords.second - 1];

      // spawn right
      x = xMax - 2;
      y = yMax / 2;
    }
    // right
    else if (x >= xMax - 2)
    {
      roomId = map->floor[roomCords.first][roomCords.second + 1];

      // spawn left
      x = 2;
      y = yMax / 2;
    }
    // up
    else if (y <= 1)
    {
      roomId = map->floor[roomCords.first - 1][roomCords.second];

      // spawn down
      x = xMax / 2;
      y = yMax - 2;
    }
    // down
    else if (y >= yMax - 2)
    {
      roomId = map->floor[roomCords.first + 1][roomCords.second];

      // spawn up
      x = xMax / 2;
      y = 2;
    }

    // create new room
    map->createRoom(roomId, gameWin);
    }
    
    return collidedChar;
  }

void Player::getmv()
{

    // read user input
    int c = getch();

    Bullet* bullet = new Bullet(true, 0, -1, 10, y-1, x, gameWin, gameItems, gameStats);
        
    
    switch(c) {

      // shoot
      case KEY_UP:
       gameItems->insert(bullet);
        break;
      // case KEY_DOWN:
      //   break;
      // case KEY_LEFT:
      //   break;
      // case KEY_RIGHT:
      //   break;

      // movement
      case 119: //W
        checkCollision(x, y-1);
        mvup();
        break;
      case 97: //A
        checkCollision(x-1, y);
        mvleft();
        break;
      case 115: //S
        checkCollision(x, y+1);
        mvdown();
        break;
      case 100: //D
        checkCollision(x+1, y);
        mvright();
        break;
      
      default:
          break;
    }
}