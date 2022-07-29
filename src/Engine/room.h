#pragma once
#include <string>
#include <vector>
#include <utility>


using namespace std;

class Room{
    public:
        Room(int _id, string _roomType, pair<int, int> coords, int roomW, int roomH);
        pair<int,int> coords;
        void draw_room(WINDOW * playerwindow); // calls every draw function
        void generate_room(vector<vector<int>> floor); // generates room (doors, items, enemies...) and saves it into a two dimensional array
        char room[40][80] {'a'};
        int id;

    private:
        
        string roomType;
        int roomW, roomH;
        
        void draw_doors(WINDOW * playerwindow);
        void generate_doors(vector<vector<int>> floor);
        
};