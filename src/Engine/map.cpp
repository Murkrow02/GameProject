#include <iostream>
#include <ncurses.h>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "map.h"
#include "../Tools/GameObjectList.hpp"

using namespace std;


Map::Map(){
    vector<vector<int>> floorTemp(9, vector<int> (9, -1));
    floor = floorTemp;
}

pair<int, int> Map::getCoords(int roomId){
    return(rooms[roomId].coords);
}

vector<vector<int>> Map::generateMap(WINDOW * playerwindow, GameObjectList* game_objects){

    int width,height;
    getmaxyx(playerwindow, height, width);

    // creates default cross

    // center
    floor[4][4] = 0;
    rooms.push_back(Room(0, "default", pair<int, int>(4,4), width, height, game_objects));

    // right
    floor[4][5] = 1;
    rooms.push_back(Room(1, "default", pair<int, int>(4,5), width, height, game_objects));

    // left
    floor[4][3] = 2;
    rooms.push_back(Room(2, "default", pair<int, int>(4,3), width, height, game_objects));

    // bottom 
    floor[5][4] = 3;
    rooms.push_back(Room(3, "default", pair<int, int>(5,4), width, height, game_objects));

    // top
    floor[3][4] = 4;
    rooms.push_back(Room(4, "default", pair<int, int>(3,4), width, height, game_objects));

    


    srand((unsigned) time(0));
    int nRooms = 5, x, options = 0;
    vector<pair<int, int>> possibleCoords;

    while(nRooms < 10){
        
        // resets variables
        options = 0;
        possibleCoords.clear();

        // picks random room to build from
        x = (rand()%nRooms) + 2;

        // puts every possible spot's coordinates to create a room in a vector 
        for(int i = 0; i < 9; i++){
            for (int t = 0; t < 9; t++){
                if (floor[i][t] == x){
                    if (floor[i-1][t] == -1){ //top
                        options++;
                        possibleCoords.push_back(pair<int, int>(i-1, t));
                    }
                        
                    if (floor[i+1][t] == -1){ //bottom
                        options++;
                        possibleCoords.push_back(pair<int, int>(i+1, t));
                    }
                    if (floor[i][t+1] == -1){ //right
                        options++;
                        possibleCoords.push_back(pair<int, int>(i, t+1));
                    }
                    if (floor[i][t-1] == -1){ //left
                        options++;
                        possibleCoords.push_back(pair<int, int>(i, t-1));
                    }
                }
            }
        }
        // picks one of the available spot and creates the room
        if (options != 0){
            x = (rand()%options) + 1;
            x--;
            // updates two-dimensional array with new room
            floor[possibleCoords[x].first][possibleCoords[x].second] = nRooms;
            // updates room coordinates with new room
            rooms.push_back(Room(nRooms, "default", possibleCoords[x], width, height, game_objects));
            nRooms++; 
            }
        }
    return floor;        
    
}

void Map::createRoom(int roomId){
    rooms[roomId].generate_room(floor);
    rooms[roomId].draw_room();
}

void Map::freezeRoom(int roomId){
    rooms[roomId].freeze_room();
}