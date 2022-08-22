#include <iostream>
#include <string>
#include <ncurses.h>
#include "room.h"
#include "gameobject.hpp"
#include "../Entities/dummy.cpp"

using namespace std;

Room::Room(int _id, string _roomType, pair<int, int> _coords, int _roomW, int _roomH){
    id = _id;
    roomType = _roomType;
    coords = _coords;
    roomW = _roomW;
    roomH = _roomH;
}

void Room::generate_room(vector<vector<int>> floor, GameObjectList *gameObjects){
    generate_doors(floor);
    spawn_entities(gameObjects);
}

void Room::generate_doors(vector<vector<int>> floor){
    
    if (floor[coords.first-1][coords.second] != -1){ // top
        room[0][roomW/2 - 1] = CHAR_DOOR;
        room[0][roomW/2] = CHAR_DOOR;
    }
    if (floor[coords.first+1][coords.second] != -1){ // bottom
        room[roomH - 1][roomW/2 - 1] = CHAR_DOOR;
        room[roomH - 1][roomW/2] = CHAR_DOOR;
    }
    if (floor[coords.first][coords.second-1] != -1){ // left
        room[roomH/2 - 1][0] = CHAR_DOOR;
        room[roomH/2][0] = CHAR_DOOR;
    }
    if (floor[coords.first][coords.second+1] != -1){ // right
        room[roomH/2 - 1][roomW - 1] = CHAR_DOOR;
        room[roomH/2][roomW - 1] = CHAR_DOOR;
    }
}

void Room::draw_room(WINDOW * playerwindow){
    box(playerwindow,0,0);
    draw_doors(playerwindow);
    wrefresh(playerwindow);
}

void Room::draw_doors(WINDOW * playerwindow){

    // draws door based on their position in the two dimensional array
    if (room[0][roomW/2] == CHAR_DOOR){ // top
        for (int i = (roomW/2) - 1; i < (roomW/2) + 1; i++){
            mvwaddch(playerwindow, 0, i, CHAR_DOOR);
        }
    }
    if (room[roomH - 1][roomW/2] == CHAR_DOOR){ // bottom
        for (int i = (roomW/2) - 1; i < (roomW/2) + 1; i++){
            mvwaddch(playerwindow, roomH - 1, i, CHAR_DOOR);
        }
    }
    if (room[roomH / 2][0] == CHAR_DOOR){ // left
        for (int i = (roomH/2) - 1; i < (roomH/2) + 1; i++){
            mvwaddch(playerwindow, i, 0, CHAR_DOOR);
        }
    }
    if (room[roomH / 2][roomW - 1] == CHAR_DOOR){ //right
        for (int i = (roomH/2) - 1; i < (roomH/2) + 1; i++){
            mvwaddch(playerwindow, i, roomW - 1, CHAR_DOOR);
        }
    }

}


void Room::spawn_entities(GameObjectList *gameObjects){
    /*
    vector<Dummy> dummies;
    ifstream f("Layouts/layout1.json");
    json data = json::parse(f);
    for(int i = 0; i < data.size(); i++){
        if (data[i]["type"] == "foe"){
            printw("%d%d", int(data[i]["posY"]), int(data[i]["posX"]));
            dummies.push_back(Dummy(int(data[i]["posY"]), int(data[i]["posX"]), gameObjects));
        }   
    }
    for (int i = 0; i < dummies.size(); i++){
        entities->insert( &dummies[i] );
    }
    */
    Dummy *temp = new Dummy(1,1, gameObjects);
    entities->insert(temp);
    gameObjects->entities->copy_list(entities);   
    
     

}