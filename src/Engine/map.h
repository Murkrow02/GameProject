#pragma once
#include <vector>
#include <utility>
#include "room.h"

using namespace std;

class Map{
    public:
        // functions
        Map();
        vector<vector<int>> generateMap(WINDOW * playerwindows);
        void createRoom(int room_id, WINDOW * playerwindow);
        pair<int, int> getCoords(int room_id); // simplifies getting coords of a room

        // variables
        vector<vector<int>> floor; // stores two dimensional vector with rooms
        vector<Room> rooms;

    private:
        //Stats *gameStats;
        //GameObjectList *gameObjects;
        
};