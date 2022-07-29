#pragma once
#include "map.h"

using namespace std;

class Player{
    public:
        Player(int _y, int _x, WINDOW * player_win);
        void mvup();
        void mvdown();
        void mvleft();
        void mvright();
        void getmv(int c, Map map);
        void showPlayer();
        void checkCollision(int x, int y, Map map);

        int roomId;
        int x,y;
    private:
        int xMax,yMax; // player position and player's window size
        WINDOW * playerWin;
        
        
};