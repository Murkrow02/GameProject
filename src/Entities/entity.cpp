#include <iostream>
#include <ncurses.h>
#include "entity.hpp"
#include "../Tools/GameObjectList.hpp"

using namespace std;

Entity::Entity(int _y, int _x, char display_char,  int _life, GameObjectList *_gameItems)
{
    // set attributes
    y = _y;
    x = _x;
    roomId = 0;
    displayChar = display_char;
    life = _life;
    gameItems = _gameItems;
    getmaxyx(gameItems->gameWindow, yMax, xMax);
}

void Entity::Draw()
{
    mvwaddch(gameItems->gameWindow, y, x, displayChar);
}

void Entity::DoFrame(){

}

void Entity::Destroy()
{
    mvwaddch(gameItems->gameWindow, y, x, ' ');
    gameItems->remove(this);
}

void Entity::Damage(){
    life--;
}

char Entity::checkCollision(int next_y, int next_x){
    return mvwinch(gameItems->gameWindow, next_y, next_x);
}

void Entity::mvdown(){
    
    int nextY = y+1;
    char nextSpot = checkCollision(nextY, x);

    // can move
    if(nextSpot == ' ')
    {
        mvwaddch(gameItems->gameWindow, y, x, ' ');
        y = nextY;
    }
        
}
void Entity::mvup(){

    int nextY = y-1;
    char nextSpot = checkCollision(nextY, x);

    // can move
    if(nextSpot == ' ')
    {
        mvwaddch(gameItems->gameWindow, y, x, ' ');
        y = nextY;
    }
}
void Entity::mvleft(){

    int nextX = x-1;
    char nextSpot = checkCollision(y, nextX);

    // can move
    if(nextSpot == ' ')
    {
        mvwaddch(gameItems->gameWindow, y, x, ' ');
        x = nextX;
    }
}
void Entity::mvright(){

    int nextX = x+1;
    char nextSpot = checkCollision(y, nextX);

    // can move
    if(nextSpot == ' ')
    {
        mvwaddch(gameItems->gameWindow, y, x, ' ');
        x = nextX;
    }
}