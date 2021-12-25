#include <string>
#include <vector>
#include <utility>


using namespace std;

class Room{
    public:
        Room(int _id, string _roomtype, pair<int, int> room_coords, int room_w, int room_h);
        pair<int,int> room_coords;
        void draw_room(WINDOW * playerwindow); // calls every draw function
        void generate_room(vector<vector<int>> floor); // generates room (doors, items, enemies...) and saves it into a two dimensional array

    private:
        int id;
        string roomtype;
        int room_w, room_h;
        
        void draw_doors(WINDOW * playerwindow);
        void generate_doors(vector<vector<int>> floor);
        char room[40][80];
};