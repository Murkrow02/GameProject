#include <iostream>
#include <string>
#include <ncurses.h>
#include "room.h"
#include "gameobject.hpp"
#include "../Entities/dummy.cpp"
#include "../Entities/crossShooter.cpp"
#include "../Entities/xShooter.cpp"
#include "../Entities/xCrossShooter.cpp"
#include "../Entities/smartShooter.cpp"
#include "../Entities/fruit.cpp"
#include "../Entities/vendor.cpp"
#include "../Entities/key.cpp"
#include "../Entities/ladder.cpp"
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
    cleared = false;
    

    //Create filename
    // Random stuff, to be changed
    string jsonName = "Empty";
    
    if (id == 0)
    {
        jsonName = "FirstRoom";
    }
    else if (id == 9)
        jsonName = "Shop";
    else if (id % 3 == 0 && id >= 3)
        jsonName = "4Enemies";
    else if (id == 5)
        jsonName = "Key";
    else
        jsonName = "2Enemies";
        
    string fileName = "../Layouts/" + jsonName + ".json";
    
    //fileName += to_string(id);
    //fileName += ".json";

    //Create entities and objects by reading from json                  

    ifstream f(fileName);
    json data = json::parse(f);

    for (int i = 0; i < data.size(); i++)
    {
        if (data[i]["type"] == "foe")
            roomObjects.insert(new Dummy(int(data[i]["posY"]), int(data[i]["posX"]), gameObjects));
        else if (data[i]["type"] == "crossShooter")
            roomObjects.insert(new CrossShooter (int(data[i]["posY"]), int(data[i]["posX"]), gameObjects));
        else if (data[i]["type"] == "xShooter")
            roomObjects.insert(new xShooter (int(data[i]["posY"]), int(data[i]["posX"]), gameObjects));
        else if (data[i]["type"] == "xCrossShooter")
            roomObjects.insert(new xCrossShooter (int(data[i]["posY"]), int(data[i]["posX"]), gameObjects));
        else if (data[i]["type"] == "smartShooter")
            roomObjects.insert(new smartShooter (int(data[i]["posY"]), int(data[i]["posX"]), gameObjects));
        else if(data[i]["type"] == "apple")
            roomObjects.insert(new Apple(int(data[i]["posY"]), int(data[i]["posX"]), gameObjects));
        else if(data[i]["type"] == "shop")
            roomObjects.insert(new Vendor(int(data[i]["posY"]), int(data[i]["posX"]), gameObjects));
        else if(data[i]["type"] == "key")
            roomObjects.insert(new Key(int(data[i]["posY"]), int(data[i]["posX"]), CHAR_KEY, gameObjects));
        else if(data[i]["type"] == "ladder")
            roomObjects.insert(new Ladder(int(data[i]["posY"]), int(data[i]["posX"]), CHAR_LADDER, gameObjects));
    }

    
    
    /*catch(const std::exception& e){
        roomObjects.insert(new Dummy(1, 1, gameObjects));
    }
    */
   
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
    if (roomObjects.numberOfEnemies(gameObjects) == 0 && !cleared){
        gameObjects->roomsToClear--;
        cleared = true;
    }
    
}

void Room::generate_room(vector<vector<int>> floor){
    generate_doors(floor);
    generate_entities();
}


void Room::generate_entities(){

    //Remove previous entities from game window
    wclear(gameObjects->gameWindow);
    gameObjects->reset();
    

    //Populate game objects with room objects
    Node* current = roomObjects.head; 
    while(current != NULL){
        if(current->data != NULL)
            gameObjects->insert(current->data);
        current = current->next;
    }
    
}

void Room::generate_doors(vector<vector<int>> floor){
    char temp;
    if (floor[coords.first-1][coords.second] != -1){ // top
        if (floor[coords.first-1][coords.second] == 9)
            temp = CHAR_DOOR_SHOP;
        else
            temp = CHAR_DOOR_OPEN;
        room[0][roomW/2 - 1] = temp;
        room[0][roomW/2] = temp;
    }
    if (floor[coords.first+1][coords.second] != -1){ // bottom
        if (floor[coords.first+1][coords.second] == 9)
            temp = CHAR_DOOR_SHOP;
        else
            temp = CHAR_DOOR_OPEN;
        room[roomH - 1][roomW/2 - 1] = temp;
        room[roomH - 1][roomW/2] = temp;
    }
    if (floor[coords.first][coords.second-1] != -1){ // left
        if (floor[coords.first][coords.second-1] == 9)
            temp = CHAR_DOOR_SHOP;
        else
            temp = CHAR_DOOR_OPEN;
        room[roomH/2 - 1][0] = temp;
        room[roomH/2][0] = temp;
    }
    if (floor[coords.first][coords.second+1] != -1){ // right
        if (floor[coords.first][coords.second+1] == 9)
            temp = CHAR_DOOR_SHOP;
        else
            temp = CHAR_DOOR_OPEN;
        room[roomH/2 - 1][roomW - 1] = temp;
        room[roomH/2][roomW - 1] = temp;
    }
}

void Room::draw_room(){
    box(gameObjects->gameWindow,0,0);
    draw_doors(gameObjects->gameWindow);
    wrefresh(gameObjects->gameWindow);
}

void Room::draw_doors(WINDOW * playerwindow){

    char doorCharVertical, doorCharHorizontal;
    if (gameObjects->numberOfEnemies(gameObjects) == 0){
        doorCharVertical = CHAR_DOOR_OPEN;
        doorCharHorizontal = CHAR_DOOR_OPEN;
    }
    else{
        doorCharVertical = CHAR_DOOR_CLOSED_VERTICAL;
        doorCharHorizontal = CHAR_DOOR_CLOSED_HORIZONTAL;
    }

    // draws door based on their position in the two dimensional array
    if (room[0][roomW/2] == CHAR_DOOR_OPEN){ // top
        for (int i = (roomW/2) - 1; i < (roomW/2) + 1; i++){
            mvwaddch(playerwindow, 0, i, doorCharHorizontal);
        }
    }
    if (room[roomH - 1][roomW/2] == CHAR_DOOR_OPEN){ // bottom
        for (int i = (roomW/2) - 1; i < (roomW/2) + 1; i++){
            mvwaddch(playerwindow, roomH - 1, i, doorCharHorizontal);
        }
    }
    if (room[roomH / 2][0] == CHAR_DOOR_OPEN){ // left
        for (int i = (roomH/2) - 1; i < (roomH/2) + 1; i++){
            mvwaddch(playerwindow, i, 0, doorCharVertical);
        }
    }
    if (room[roomH / 2][roomW - 1] == CHAR_DOOR_OPEN){ //right
        for (int i = (roomH/2) - 1; i < (roomH/2) + 1; i++){
            mvwaddch(playerwindow, i, roomW - 1, doorCharVertical);
        }
    }

    if (room[0][roomW/2] == CHAR_DOOR_SHOP){ // top
        for (int i = (roomW/2) - 1; i < (roomW/2) + 1; i++){
            mvwaddch(playerwindow, 0, i, CHAR_DOOR_SHOP);
        }
    }
    if (room[roomH - 1][roomW/2] == CHAR_DOOR_SHOP){ // bottom
        for (int i = (roomW/2) - 1; i < (roomW/2) + 1; i++){
            mvwaddch(playerwindow, roomH - 1, i, CHAR_DOOR_SHOP);
        }
    }
    if (room[roomH / 2][0] == CHAR_DOOR_SHOP){ // left
        for (int i = (roomH/2) - 1; i < (roomH/2) + 1; i++){
            mvwaddch(playerwindow, i, 0, CHAR_DOOR_SHOP);
        }
    }
    if (room[roomH / 2][roomW - 1] == CHAR_DOOR_SHOP){ //right
        for (int i = (roomH/2) - 1; i < (roomH/2) + 1; i++){
            mvwaddch(playerwindow, i, roomW - 1, CHAR_DOOR_SHOP);
        }
    }




}