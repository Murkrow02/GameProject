#include <iostream>
#include <string>
#include <ncurses.h>
#include "headers/room.h"

using namespace std;

Room::Room(int _id, string _roomtype, pair<int, int> _room_coords, int _room_w, int _room_h){
    id = _id;
    roomtype = _roomtype;
    room_coords = _room_coords;
    room_w = _room_w;
    room_h = _room_h;
}

void Room::generate_room(vector<vector<int>> floor){
    generate_doors(floor);
}

void Room::generate_doors(vector<vector<int>> floor){
    
    if (floor[room_coords.first-1][room_coords.second] != 0){ // top
        room[0][room_w/2 - 1] = '*';
        room[0][room_w/2] = '*';
    }
    if (floor[room_coords.first+1][room_coords.second] != 0){ // bottom
        room[room_h - 1][room_w/2 - 1] = '*';
        room[room_h - 1][room_w/2] = '*';
    }
    if (floor[room_coords.first][room_coords.second-1] != 0){ // left
        room[room_h/2 - 1][0] = '*';
        room[room_h/2][0] = '*';
    }
    if (floor[room_coords.first][room_coords.second+1] != 0){ // right
        room[room_h/2 - 1][room_w - 1] = '*';
        room[room_h/2][room_w - 1] = '*';
    }
}

void Room::draw_room(WINDOW * playerwindow){
    draw_doors(playerwindow);
}

void Room::draw_doors(WINDOW * playerwindow){

    // draws door based on their position in the two dimensional array
    if (room[0][room_w/2] == '*'){ // top
        for (int i = (room_w/2) - 1; i < (room_w/2) + 1; i++){
            mvwaddch(playerwindow, 0, i, '*');
        }
    }
    if (room[room_h - 1][room_w/2] == '*'){ // bottom
        for (int i = (room_w/2) - 1; i < (room_w/2) + 1; i++){
            mvwaddch(playerwindow, room_h - 1, i, '*');
        }
    }
    if (room[room_h / 2][0] == '*'){ // left
        for (int i = (room_h/2) - 1; i < (room_h/2) + 1; i++){
            mvwaddch(playerwindow, i, 0, '*');
        }
    }
    if (room[room_h / 2][room_w - 1] == '*'){ //right
        for (int i = (room_h/2) - 1; i < (room_h/2) + 1; i++){
            mvwaddch(playerwindow, i, room_w - 1, '*');
        }
    }



}