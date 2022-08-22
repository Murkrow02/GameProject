#pragma once
#include <string>
#include <vector>
#include <utility>
#include <ncurses.h>
#include <fstream>
#include "../libraries/json.hpp"



using json = nlohmann::json;

using namespace std;


class GameObjectList;
class EntitiesList;
class Room{
    public:
        Room(int _id, string _roomType, pair<int, int> coords, int roomW, int roomH);
        pair<int,int> coords;
        void draw_room(WINDOW * playerwindow); // calls every draw function
        void generate_room(vector<vector<int>> floor, GameObjectList *gameObjects); // generates room (doors, items, enemies...) and saves it into a two dimensional array
        char room[40][80] {'a'};
        int id;

    private:
        
        string roomType;
        int roomW, roomH;
        EntitiesList* entities;
        
        void draw_doors(WINDOW * playerwindow);
        void generate_doors(vector<vector<int>> floor); 
        void spawn_entities(GameObjectList *gameObjects);
        
};