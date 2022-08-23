#pragma once
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <memory>
#include <ncurses.h>
#include"../Engine/gameobject.hpp"
#include "../Tools/GameObjectNode.hpp"

using namespace std;


class Room{
    public:
        Room(int _id, string _roomType, pair<int, int> coords, int roomW, int roomH, GameObjectList* game_objects);
        pair<int,int> coords;
        void draw_room(); // calls every draw function
        void generate_room(vector<vector<int>> floor); // generates room (doors, items, enemies...) and saves it into a two dimensional array
        void freeze_room(vector<vector<int>> floor); // save room objects state copying from main list all stuff
        char room[40][80] {'a'};
        int id;

    private:
        
        string roomType;
        int roomW, roomH;
        GameObjectList* gameObjects;
        GameObjectNode roomObjects;
        
        void draw_doors(WINDOW * playerwindow);
        void generate_doors(vector<vector<int>> floor);
        void generate_entities();
        
};