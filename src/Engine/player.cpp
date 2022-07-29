#include <iostream>
#include <ncurses.h>
#include "player.h"

using namespace std;


Player::Player(int _y, int _x, WINDOW * player_win){
    y = _y;
    x = _x;
    roomId = 0;
    playerWin = player_win;
    getmaxyx(playerWin, yMax, xMax);
    
}

void Player::checkCollision(int nextX, int nextY, Map map){

    Room cRoom = map.rooms[roomId];
    pair<int, int> roomCords = cRoom.coords;
    printw("\n %c", cRoom.room[nextY][nextX]);
    if (cRoom.room[nextY][nextX] == '*'){
        printw("\nTrue");
        // left
        if (x <= 1) {
            roomId = map.floor[roomCords.first][roomCords.second - 1];
        }
        // right
        if (x >= xMax - 2){
            roomId = map.floor[roomCords.first][roomCords.second + 1];
        }
        // up
        if (y <= 1){
            roomId = map.floor[roomCords.first - 1][roomCords.second];
        }
        // down
        if (y >= yMax-2){
            roomId = map.floor[roomCords.first + 1][roomCords.second];
        }


        
        mvwaddch(playerWin, y, x, ' ');
        x = 40;
        y = 20;
        map.createRoom(roomId, playerWin);
        
        
    }
    else printw("\nFalse");

}

void Player::getmv(int c, Map map){

    c = getch();
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