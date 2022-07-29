#include <iostream>
#include <ncurses.h>
#include "player.h"

using namespace std;


Player::Player(int _y, int _x, WINDOW * player_win){

    // set attributes
    y = _y;
    x = _x;
    roomId = 0;
    playerWin = player_win;
    getmaxyx(playerWin, yMax, xMax);

    // spawn player
    mvwaddch(player_win, y, x, 'c');
    
}

void Player::checkCollision(int nextX, int nextY, Map map){

    Room cRoom = map.rooms[roomId];
    pair<int, int> roomCords = cRoom.coords;
    printw("\n %c", cRoom.room[nextY][nextX]);

    // player entered next room
    if (cRoom.room[nextY][nextX] == '*'){

        printw("\nTrue");

        // clear player old position
        mvwaddch(playerWin, y, x, ' ');

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

        // create new room
        map.createRoom(roomId, playerWin);
        
        
    }
    else printw("\nFalse");

}

void Player::getmv(int c, Map map){

    switch(c) {
    case KEY_UP:
        checkCollision(x, y-1, map);
        mvwaddch(playerWin, y, x, ' ');
        mvup();
        break;
    case KEY_DOWN:
        checkCollision(x, y+1, map);
        mvwaddch(playerWin, y, x, ' ');
        mvdown();
        break;
    case KEY_LEFT:
        checkCollision(x-1, y, map);
        mvwaddch(playerWin, y, x, ' ');
        mvleft();
        break;
    case KEY_RIGHT:
        checkCollision(x+1, y, map);
        mvwaddch(playerWin, y, x, ' ');
        mvright();
        break;
    default:
        break;
    }
    showPlayer();
}

void Player::mvdown(){
    y++;
    if (y > yMax-2)
        y = yMax-2;
}
void Player::mvup(){
    y--;
    if (y < 1)
        y = 1;
}
void Player::mvleft(){
    x--;
    if (x < 1)
        x = 1;
}
void Player::mvright(){
    x++;
    if (x > xMax - 2)
        x = xMax - 2;
    
}
void Player::showPlayer(){
    mvwaddch(playerWin, y, x, 'c');
}