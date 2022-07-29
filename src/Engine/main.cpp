#include <iostream>
#include <thread>
#include <chrono>
#include <ncurses.h>
#include "player.h"
#include "map.h"
#include "minimap.h"
#include "../UI/stats.hpp"
#include "../UI/message.hpp"
#include "../Tools/utils.hpp"

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

    // SETUP
    int room_width = 80, room_height = 40, room_x, room_y;

    // ncurses set up, terminal resizing and window creation at center
    initial_setup(room_width, room_height, &room_x, &room_y);

    // player setup
    box(game_window,0,0);
    Player player((room_height / 2), (room_width / 2), game_window); // player creation

    // map - minimap setup
    Map map; 
    Minimap minimap(4, 2,(room_width - 20), 5);
    vector<vector<int>> floor = map.generateMap(game_window);
    minimap.drawMinimap(map);
    map.createRoom(0, game_window);

    // stats setup
    int x_stat = room_x + room_width + 2;
    int y_stat = room_y + 1;
    stats game_stats(x_stat, y_stat);

    wrefresh(game_window);

    // main loop
    while (true){
        debugInfo(player, map);
        int c = getch();
        player.getmv(c, map);
        wrefresh(game_window);
    }

	getch(); // waits user input
	endwin();	

    
    return 0;
}


   

/*
    // TEST messaggi
    message test = message("titolo", "messaggio);
    test.wait_close.wait();

    //Test by saving mock data
    save.savefile["funge"] = true;
    save.save_changes();

    //Retreive mock data
    bool funge = save.savefile["funge"];

    printw("%d",funge);
*/