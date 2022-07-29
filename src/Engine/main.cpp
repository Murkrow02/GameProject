#include <iostream>
#include <thread>
#include <chrono>
#include <ncurses.h>
#include "player.h"
#include "map.h"
#include "minimap.h"

using namespace std;

void debugInfo(Player player, Map map){
    move(0, 0);
    clrtoeol();
    printw("%d", player.x);
    printw("  %d", player.y);
    printw("\nroomID : %d", player.roomId);
    printw("\n%c", map.rooms[player.roomId].room[player.y][player.x]);
}

int main(){

    // basic setup
    initscr();
    noecho(); // doesn't echo user input on screen
    keypad(stdscr,TRUE); // allows keypad input
    curs_set(0); // disables cursor
    int width,height;
    getmaxyx(stdscr, height, width);


    // SETUP
    int windowW = 80, windowH = 40, windowX = 4, windowY = 10;
    WINDOW * player_window;
    player_window = newwin(windowH, windowW, windowY, windowX);


   


    // player setup
    mvwaddch(player_window, windowW / 2 + windowX, windowY / 2 + windowH, 'c');
    refresh();
    box(player_window,0,0);
    wrefresh(player_window);
    Player player((windowH / 2), (windowW / 2), player_window); // player creation

    // map - minimap setup
    Map map; 
    Minimap minimap(4, 2,(width - 20), 5);
    vector<vector<int>> floor = map.generateMap(player_window);
    minimap.drawMinimap(map);
    map.createRoom(0, player_window);

    wrefresh(player_window);
    
    
    // main loop
    while (true){
        debugInfo(player, map);
        int c = getch();
        player.getmv(c, map);
        wrefresh(player_window);
    }

	getch(); // waits user input
	endwin();	

    
    return 0;
}