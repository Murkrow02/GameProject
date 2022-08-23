#include <iostream>
#include <string>
#include <ncurses.h>
#include "room.h"
#include "gameobject.hpp"
#include "../Entities/dummy.cpp"
#include "../Entities/fruit.cpp"
#include "../Entities/vendor.cpp"
#include "../Tools/GameObjectNode.hpp"
#include "../libraries/json.hpp"
#include <fstream>

using namespace std;
using json = nlohmann::json;

Room::Room(int _id, string _roomType, pair<int, int> _coords, int _roomW, int _roomH, GameObjectList* game_objects){

    id = _id;
    roomType = _roomType;
    coords = _coords;
    roomW = _roomW;
    roomH = _roomH;
    gameObjects = game_objects;

    //Create filename
    string fileName = "Layouts/";
    fileName += std::to_string(id);
    fileName += ".json";

    //Create entities and objects by reading from json
    try{
        std::ifstream f(fileName);
        json data = json::parse(f);

        for (int i = 0; i < data.size(); i++)
        {
            if (data[i]["type"] == "foe")
                roomObjects.insert(new Dummy(int(data[i]["posY"]), int(data[i]["posX"]), gameObjects));
            else if(data[i]["type"] == "apple")
                 roomObjects.insert(new Apple(int(data[i]["posY"]), int(data[i]["posX"]), game_objects));
            else if(data[i]["type"] == "shop")
                roomObjects.insert(new Vendor(int(data[i]["posY"]), int(data[i]["posX"]), game_objects));
        }

    }catch(const std::exception& e){
        //MISSING JSON FOR LEVELS
    }
   
}


void Room::freeze_room(){

    //Remove previous entities from local list
    roomObjects.reset();

    //Populate room objects with gameobjects from main
    Node* current = gameObjects->head;
    while(current != NULL){
        
        if(current->data != NULL)
            roomObjects.insert(current->data);
        current = current->next;
    }
    
}

void Room::generate_room(vector<vector<int>> floor){
    generate_doors(floor);
    generate_entities();
}


void Room::generate_entities(){

    //Remove previous entities from game window
    gameObjects->reset();
    wclear(gameObjects->gameWindow);

    //Populate game objects with room objects
    Node* current = roomObjects.head;
    while(current != NULL){

        if(current->data != NULL)
            gameObjects->insert(current->data);
        current = current->next;
    }
    
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

void Room::draw_room(){
    box(gameObjects->gameWindow,0,0);
    draw_doors(gameObjects->gameWindow);
    wrefresh(gameObjects->gameWindow);
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