#include <iostream>
#include <ncurses.h>
#include "player.hpp"
#include "entity.hpp"

using namespace std;

Player::Player(int _y, int _x, WINDOW * player_win) : Entity{ _y,  _x, player_win, 'c'} // 'c' is the char being displayed
{
}

void Player::getmv(int c, Map map){

    switch(c) {
    case KEY_UP:
        checkCollision(x, y-1, map);
        mvup();
        break;
    case KEY_DOWN:
        checkCollision(x, y+1, map);
        mvdown();
        break;
    case KEY_LEFT:
        checkCollision(x-1, y, map);
        mvleft();
        break;
    case KEY_RIGHT:
        checkCollision(x+1, y, map);
        mvright();
        break;
    default:
        break;
    }
}