#include <iostream>
#include <ncurses.h>
#include "entity.hpp"

using namespace std;

Entity::Entity(int _y, int _x, WINDOW * game_win, char display_char)
{
    // set attributes
    y = _y;
    x = _x;
    roomId = 0;
    gameWin = game_win;
    displayChar = display_char;
    getmaxyx(gameWin, yMax, xMax);

    // spawn entity
    showEntity();
}

void Entity::checkCollision(int nextX, int nextY, Map map){

    Room cRoom = map.rooms[roomId];

    //mvwprintw(gameWin, 0,0, std::to_string(map.rooms.size()).c_str());

    pair<int, int> roomCords = cRoom.coords;
    //printw("\n %c", cRoom.room[nextY][nextX]);

    
    // player entered next room
    if (mvwinch(gameWin, nextY, nextX) == '*'){

        // clear player old position
        mvwaddch(gameWin, y, x, ' ');

        // left
        if (x <= 1) {
            roomId = map.floor[roomCords.first][roomCords.second - 1];
            
            // spawn right
            x = xMax-2;
            y = yMax/2;
        }
        // right
        else if (x >= xMax - 2){
            roomId = map.floor[roomCords.first][roomCords.second + 1];

            // spawn left
            x = 2;
            y = yMax/2;
        }
        // up
        else if (y <= 1){
            roomId = map.floor[roomCords.first - 1][roomCords.second];

            // spawn down
            x = xMax/2;
            y = yMax-2;
        }
        // down
        else if (y >= yMax-2){
            roomId = map.floor[roomCords.first + 1][roomCords.second];

            // spawn up
            x = xMax/2;
            y = 2;
        } 

        // create new room ONLY IF PLAYER,NOT ENTITY
        map.createRoom(roomId, gameWin);
        
        
    }
    else{

    }
}

void Entity::showEntity(){
    mvwaddch(gameWin, y, x, displayChar);
}

void Entity::mvdown(){
    mvwaddch(gameWin, y, x, ' ');
    y++;
    if (y > yMax-2)
        y = yMax-2;
    showEntity();
}
void Entity::mvup(){
    mvwaddch(gameWin, y, x, ' ');
    y--;
    if (y < 1)
        y = 1;
    showEntity();
}
void Entity::mvleft(){
    mvwaddch(gameWin, y, x, ' ');
    x--;
    if (x < 1)
        x = 1;
    showEntity();
}
void Entity::mvright(){
    mvwaddch(gameWin, y, x, ' ');
    x++;
    if (x > xMax - 2)
        x = xMax - 2;
    showEntity();
}