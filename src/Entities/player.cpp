#include <iostream>
#include <ncurses.h>
#include "player.hpp"
#include "entity.hpp"

using namespace std;

Player::Player(int _y, int _x, WINDOW * player_win, Stats *game_stats, Map* _map) : Entity{ _y,  _x, player_win, PLAYER_CHAR} 
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

  void Player::damage(){

    // check if is invincible
    if(invincibilityLeft == 0)
    {
      // set player as invincible for a short period of time
      invincibilityLeft = INVINCIBILITY_DURATION;

      // update stats
      gameStats->lost_life();
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


    switch(c) {
    case KEY_UP:
        checkCollision(x, y-1);
        mvup();
        break;
    case KEY_DOWN:
        checkCollision(x, y+1);
        mvdown();
        break;
    case KEY_LEFT:
        checkCollision(x-1, y);
        mvleft();
        break;
    case KEY_RIGHT:
        checkCollision(x+1, y);
        mvright();
        break;
    default:
        break;
    }
}