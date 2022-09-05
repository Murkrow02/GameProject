#include <iostream>
#include <ncurses.h>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "minimap.hpp"

using namespace std;


Minimap::Minimap(int _roomW, int _roomH, int _posX, int _posY){
    // HUD Position
    posX = _posX;
    posY = _posY;
    // Dimension of each room 
    roomW = _roomW;
    roomH = _roomH;
}

void Minimap::drawRoom(int startX, int startY, int character){

    WINDOW * tempRoom = newwin(roomH, roomW, (startY - (roomH / 2)), (startX - (roomW / 2)));
    refresh();
    wborder(tempRoom, character, character, character, character, character, character, character,character); // uses wborder instead of box in order to draw a box of '*' for the highlighted room
    wrefresh(tempRoom);    
}

void Minimap::highRoom(int id, Map map){

    pair<int, int> coords = map.getCoords(id);

    int x = coords.second;
    int y = coords.first;

    // calls drawRoom and passes * as the character to use
    drawRoom((posX + ((x - 4) * roomW)), (posY + ((y - 4) * roomH)), 42); 
}

void Minimap::drawMinimap(GameObjectList *gameObjects, int highId){
    
    // central room
    drawRoom(posX, posY, 0); 

    // adjacent rooms 
    drawRoom(posX, posY - roomH, 0); // top
    drawRoom(posX, posY + roomH, 0); // bottom
    drawRoom(posX - roomW, posY, 0); // left
    drawRoom(posX + roomW, posY, 0); // right

    // draws randomly generated rooms
    for (int i = 4; i < 10; i++){

        pair<int, int> coords = gameObjects->gameMap->getCoords(i);
        int x = coords.second;
        int y = coords.first;

        drawRoom((posX + ((x - 4) * roomW)), (posY + ((y - 4) * roomH)), 0);
    }

    // highlights room
    highRoom(highId, *(gameObjects->gameMap));
    
}
