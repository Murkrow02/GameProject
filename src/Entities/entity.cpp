#include <iostream>
#include <ncurses.h>
#include "entity.hpp"
#include "../Tools/list.hpp"

using namespace std;

Entity::Entity(int _y, int _x, WINDOW * game_win, char display_char,  int _life, GameObjectList *_gameItems, Stats *game_stats)
{
    // set attributes
    y = _y;
    x = _x;
    roomId = 0;
    gameWin = game_win;
    displayChar = display_char;
    life = _life;
    gameItems = _gameItems;
    gameStats = game_stats;
    getmaxyx(gameWin, yMax, xMax);
}

void Entity::Draw()
{
    mvwaddch(gameWin, y, x, displayChar);
}

void Entity::DoFrame(){

}

void Entity::Destroy()
{
    mvwaddch(gameWin, y, x, ' ');
    gameItems->remove(this);
}

void Entity::Damage(){

    life--;
    if(life<=0){

        // rip
        Destroy();
    }
      
 }

char Entity::checkCollision(int next_y, int next_x){
    return mvwinch(gameWin, next_y, next_x);
}

void Entity::mvdown(){
    
    int nextY = y+1;
    char nextSpot = checkCollision(nextY, x);

    // can move
    if(nextSpot == ' ')
    {
        mvwaddch(gameWin, y, x, ' ');
        y = nextY;
    }
        
}
void Entity::mvup(){

    int nextY = y-1;
    char nextSpot = checkCollision(nextY, x);

    // can move
    if(nextSpot == ' ')
    {
        mvwaddch(gameWin, y, x, ' ');
        y = nextY;
    }
}
void Entity::mvleft(){

    int nextX = x-1;
    char nextSpot = checkCollision(y, nextX);

    // can move
    if(nextSpot == ' ')
    {
        mvwaddch(gameWin, y, x, ' ');
        x = nextX;
    }
}
void Entity::mvright(){

    int nextX = x+1;
    char nextSpot = checkCollision(y, nextX);

    // can move
    if(nextSpot == ' ')
    {
        mvwaddch(gameWin, y, x, ' ');
        x = nextX;
    }
}