#pragma once
#include <vector>
#include <utility>
#include "room.hpp"

using namespace std;

class GameObjectList;
class Map{
    public:
        // functions
        Map();
        void generateMap(WINDOW * playerwindows, GameObjectList* game_objects);
        void createRoom(int room_id);
        void freezeRoom(int room_id);
        pair<int, int> getCoords(int room_id); // simplifies getting coords of a room

        // variables
        vector<vector<int>> floor; // stores two dimensional vector with rooms
        vector<Room> rooms;

    private:
        
};