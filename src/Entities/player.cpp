#include <iostream>
#include <ncurses.h>
#include "player.hpp"
#include "entity.hpp"
#include "../Tools/GameObjectList.hpp"
#include "../Entities/bullet.cpp"
#include "weapon.cpp"
#include "../UI/inventory.hpp"
#include "../UI/message.hpp"

using namespace std;

Player::Player(int _y, int _x, GameObjectList *game_objects) : Entity{ _y,  _x, CHAR_PLAYER, LIFE_PLAYER , game_objects} 
{

  // set default weapon
  Weapon testWeapon("NOOB WEAPON", 10, 4, 60, 30, 0);
  weapons.push_back(testWeapon);
  setWeapon(&weapons.back());

  Draw();
}
  
  void Player::setWeapon(Weapon *_weapon){
    
    weapon = _weapon;

    // update stats
    gameItems->gameStats->set_max_ammo(weapon->Ammo);
    gameItems->gameStats->reset_ammo();
    gameItems->gameStats->set_weapon_name(weapon->Name);
  }

  void Player::DoFrame()
  {
    // check if has to lower
    if (invincibilityLeft > 0) // invincibility
      invincibilityLeft--;

    // reloading ammo
    if (reload_delay > 1) 
      reload_delay--;
    else if(reload_delay == 1) // not 0 otherwhise is always falling in next condition causing glitches
    {
      // finished reloading
      gameItems->gameStats->reloading(false); 
      reload_delay = 0;
    }
      
    // delay between bullets
    if (next_bullet_delay > 0) 
      next_bullet_delay--;
  }

  void Player::Damage()
  {

    // check if is invincible
    if (invincibilityLeft == 0)
    {
      // set player as invincible for a short period of time
      invincibilityLeft = DURATION_INVINCIBILITY;

      // update stats
      gameItems->gameStats->lost_life();

      // run default damage function
      Entity::Damage();

      // check game over
      if (life <= 0)
      {
        // Show game over message
        gameOverMessage = new message("GAME OVER","Sei morto :(");
        gameOverMessage->wait_close.wait();

        // Close game
        initscr();
        refresh();
        endwin();
        exit(0);
      }
    }
  }

  // override draw function
  int stopBlinkRedAtFrame = 0;
  int skipFrames = 10; //higher value = slower blink speed
  void Player::Draw(){

    // blink by hiding player each x frames
    if(invincibilityLeft > 0){


      if(invincibilityLeft >= stopBlinkRedAtFrame)
      {
        //Draw player red color
        wattron(gameItems->gameWindow, COLOR_PAIR(1));
        mvwaddch(gameItems->gameWindow, y, x, displayChar);
        wattroff(gameItems->gameWindow, COLOR_PAIR(1));
      }
      else
      {
        mvwaddch(gameItems->gameWindow, y, x, displayChar);
        if(stopBlinkRedAtFrame-skipFrames > invincibilityLeft){
          stopBlinkRedAtFrame = invincibilityLeft-skipFrames;
        }
      }
    }else{

      // no invincibility, draw normally
      stopBlinkRedAtFrame = DURATION_INVINCIBILITY-skipFrames;
      mvwaddch(gameItems->gameWindow, y, x, displayChar);
    }
  }
  
  char Player::checkCollision(int nextY, int nextX)
  {
    //Check last char collided by player
    char collidedChar = mvwinch(gameItems->gameWindow, nextY, nextX);

    //Check if entered new room
    if (collidedChar == '*' && gameItems->numberOfEnemies(gameItems) == 0){

      //Get current room
      Room cRoom = gameItems->gameMap->rooms[roomId];
      pair<int, int> roomCords = cRoom.coords;

      //Save current room state
      gameItems->gameMap->freezeRoom(roomId);

      // clear player old position
      mvwaddch(gameItems->gameWindow, y, x, ' ');

      // left
      if (x <= 1)
      {
        roomId = gameItems->gameMap->floor[roomCords.first][roomCords.second - 1];

        // spawn right
        x = xMax - 2;
        y = yMax / 2;
      }
      // right
      else if (x >= xMax - 2)
      {
        roomId = gameItems->gameMap->floor[roomCords.first][roomCords.second + 1];

        // spawn left
        x = 2;
        y = yMax / 2;
      }
      // up
      else if (y <= 1)
      {
        roomId = gameItems->gameMap->floor[roomCords.first - 1][roomCords.second];

        // spawn down
        x = xMax / 2;
        y = yMax - 2;
      }
      // down
      else if (y >= yMax - 2)
      {
        roomId = gameItems->gameMap->floor[roomCords.first + 1][roomCords.second];

        // spawn up
        x = xMax / 2;
        y = 2;
      }

      // create new room
      gameItems->gameMap->createRoom(roomId);
      gameItems->gameMinimap->drawMinimap(gameItems, roomId);
    }

    else if (collidedChar == 'o'){

      //Player does not have a key
      if(gameItems->key == false)
      {
        message cannotEnter = message("ATTENZIONE!","Hai bisogno di una chiave per accedere a questa stanza");
        cannotEnter.wait_close.wait();
        return collidedChar;
      }
      else if (gameItems->numberOfEnemies(gameItems) == 0){

      //Player can access Shop

      //Get current room
        Room cRoom = gameItems->gameMap->rooms[roomId];
        pair<int, int> roomCords = cRoom.coords;

        //Save current room state
        gameItems->gameMap->freezeRoom(roomId);

        // clear player old position
        mvwaddch(gameItems->gameWindow, y, x, ' ');

        // left
        if (x <= 1)
        {
          roomId = gameItems->gameMap->floor[roomCords.first][roomCords.second - 1];

          // spawn right
          x = xMax - 2;
          y = yMax / 2;
        }
        // right
        else if (x >= xMax - 2)
        {
          roomId = gameItems->gameMap->floor[roomCords.first][roomCords.second + 1];

          // spawn left
          x = 2;
          y = yMax / 2;
        }
        // up
        else if (y <= 1)
        {
          roomId = gameItems->gameMap->floor[roomCords.first - 1][roomCords.second];

          // spawn down
          x = xMax / 2;
          y = yMax - 2;
        }
        // down
        else if (y >= yMax - 2)
        {
          roomId = gameItems->gameMap->floor[roomCords.first + 1][roomCords.second];

          // spawn up
          x = xMax / 2;
          y = 2;
        }

        // create new room
        gameItems->gameMap->createRoom(roomId);
        gameItems->gameMinimap->drawMinimap(gameItems, roomId);
      }
    }
    
    return collidedChar;
  }

void Player::Shoot(int dirX, int dirY, int spawnX, int spawnY){

  if (gameItems->gameStats->ammo == 0){
    gameItems->gameStats->reloading(true);
    reload_delay = weapon->ReloadTime;
    gameItems->gameStats->reset_ammo();
  }

  else if(gameItems->gameStats->ammo > 0 && reload_delay == 0 && next_bullet_delay == 0){

    // spawn bullet
    Bullet *bullet = new Bullet(true, dirX, dirY, weapon->Range, spawnY, spawnX, gameItems, 2);
    gameItems->insert(bullet);

    // remove bullet from stats
    gameItems->gameStats->lost_ammo();
    next_bullet_delay = weapon->FireRate;
  }
}

void Player::Reload(){

  //return if already full
  if(weapon->Ammo == gameItems->gameStats->ammo)
    return;

  gameItems->gameStats->reloading(true);
  reload_delay = weapon->ReloadTime;
  gameItems->gameStats->reset_ammo();

}

void Player::showInventory()
{
  inventory inv = inventory(gameItems);
  inv.show();
}

void Player::getmv()
{

    // read user input
    keyPressed = getch();
    
    switch(keyPressed) {

      // shoot
      case KEY_UP:
        Shoot(0,-1, x, y-1);
        break;
      case KEY_DOWN:
        Shoot(0, 1, x, y+1);
        break;
      case KEY_LEFT:
        Shoot(-1, 0, x-1, y);
        break;
      case KEY_RIGHT:
        Shoot(1, 0, x+1, y);
        break;

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
      
      // reload
      case 114: //R
       Reload();
       break;

      // inventory
      case 109: //M
        showInventory();
        break;

      default:
          break;
    }
}