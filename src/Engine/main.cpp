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
#include "../Tools/utils.hpp"
#include "gameobject.cpp"
#include <list>

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

    // player setup
    Player player((room_height / 2), (room_width / 2), game_window); // player creation

    // dummy spawn
    Dummy dummy((room_height / 2) + 10, (room_width / 2)- 10, game_window, &player);

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

    // populate initial game objects
    ////////TODO: converti in lista di puntatori come richiesto nel PDF
    std::list<GameObject*>  gameObjects; 
    gameObjects.push_back( &player );
    gameObjects.push_back( &dummy );

    // do not wait for getch() (otherwhise the following loop will stop)
    nodelay(stdscr, TRUE);

    // main loop
    while (true){

        // https://cplusplus.com/forum/general/65250/

        // debug purposes
        debugInfo(player, map);

        // player next move
        player.getmv(map);

        // move and animate objects:
        for(auto i = gameObjects.begin(); i != gameObjects.end(); ++i)
        {
            (*i)->DoFrame();  // update the objects
        }

        // loop again to draw everything
        for(auto i = gameObjects.begin(); i != gameObjects.end(); ++i)
        {
            (*i)->Draw();
        }

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