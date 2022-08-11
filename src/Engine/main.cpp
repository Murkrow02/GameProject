#include <iostream>
#include <thread>
#include <chrono>
#include <ncurses.h>
#include "../Entities/player.hpp"
#include "../Entities/dummy.cpp"
#include "map.h"
#include "minimap.h"
#include "../UI/stats.hpp"
#include "../UI/message.hpp"
#include "../UI/shop.hpp"
#include "../Tools/utils.hpp"
#include "gameobject.cpp"
#include "../Tools/list.hpp"

using namespace std;

void debugInfo(Player player, Map map){
    move(0, 0);
    clrtoeol();
    //printw("%d", player.x);
    //printw("  %d", player.y);
    //printw("\nroomID : %d", player.roomId);
    //printw("\n%c", map.rooms[player.roomId].room[player.y][player.x]);
}

int main(){

    // SETUP
    int room_width = 80, room_height = 40, room_x, room_y;

    // ncurses set up, terminal resizing and window creation at center
    initial_setup(room_width, room_height, &room_x, &room_y);

    // main list of all gameobjects
    GameObjectList gameObjects = GameObjectList();

    // stats setup
    int x_stat = room_x + room_width + 2;
    int y_stat = room_y + 1;
    Stats game_stats(x_stat, y_stat);
    
    // map - minimap setup
    Map map; 
    Minimap minimap(4, 2,(room_width - 20), 5);
    vector<vector<int>> floor = map.generateMap(game_window);
    minimap.drawMinimap(map);
    map.createRoom(0, game_window);

    // player setup
    Player player((room_height / 2), (room_width / 2), game_window, &map, &gameObjects, &game_stats); // player creation

    // dummy spawn
    Dummy dummy(1,1, game_window, &gameObjects, &game_stats);

    wrefresh(game_window);

    // populate initial game objects
    gameObjects.player = &player;
    gameObjects.insert( &dummy );

    // do not wait for getch() (otherwhise the following loop will stop)
    nodelay(stdscr, TRUE);

    shop a = shop();
    //a.wait_close.wait();

    // welcome message
    message test = message("BENVENUTO!","Puoi muoverti usando i tasti WASD e sparare usando le frecce");
    test.wait_close.wait();


    // main loop
    while (true){

        // https://cplusplus.com/forum/general/65250/

        // debug purposes
        debugInfo(player, map);

        // player next move
        player.getmv();

        // move and animate objects:
        gameObjects.doFrames();

        // loop again to draw everything
        gameObjects.draw();

        // refresh game window
        wrefresh(game_window);

        ///////////TODO: ENHANCE THIS BECAUSE IS NOT ALWAYS 16 MS AS DRAWING CAN TAKE LONGER
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
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