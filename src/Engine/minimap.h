#pragma once
#include <vector>
#include <utility>
#include "room.h"
#include "map.h"

using namespace std;

class Minimap{
    public:
        // function
        Minimap(int _roomW, int _roomH, int _posX, int _posY);
        void drawRoom(int startX, int startY, int character);
        void drawMinimap(Map map);
        void highRoom(int id, Map map);
        void createRoom(int room_id, WINDOW * playerwindow);
        // variables

    private:
        int posX, posY, roomW, roomH; // position of the minimap and dimension of each room in the minimap
        
};