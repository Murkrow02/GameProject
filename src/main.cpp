#include <stdio.h>
#include <ncurses.h>
#include <string>
#include <fstream>
#include <iostream>
#include "room.hpp"
#include "Tools/utils.hpp"
#include "Tools/savedata.hpp"
#include "panel.h"
#include "UI/dialog.hpp"

using namespace std;

WINDOW* game_window;

WINDOW* initial_setup(){

    //Configure Ncurses
    WINDOW* win = initscr();
    noecho(); // doesn't echo user input on screen
    keypad(stdscr,TRUE); // allows keypad input
    curs_set(0); // disables cursor

    //Detect if window is too small and return screen dimensions if accepted size
    pair<int,int> dimensions = check_win_size(); //Shows the user an hint to resize window correctly

    //PRIMA DI INIZIARE A DISEGNARE IL GIOCO PRINTA UN MESSAGGIO CHE DICE TUTTO PRONTO, PREMI INVIO PER INIZIARE
   // dialog initial_message("Attenzione!");
   // initial_message.show();

    //Center the game box
    clear();
    int window_x = (dimensions.second-room_width)/2;
    int window_y = (dimensions.first-room_height)/2;
    
    //Create game window
    WINDOW * player_window;
    player_window = newwin(room_height, room_width, window_y, window_x);
    //mvwaddch(player_window, room_width / 2 + window_x, window_y / 2 + room_height, 'c');
    box(player_window,0,0);
    wrefresh(player_window);

    //Add window as a panel to use stacked windows
    new_panel(player_window);
    update_panels();
    doupdate();

    return win;
}


int main(){

    //Configure Ncurses and init game window
    game_window = initial_setup();

    //Retreitve savedata
    savedata save;

    wait_key(custom_keys::Enter); //Prevent program from closing
    endwin();
    return 0;
}

/*
    //Test by saving mock data
    save.savefile["funge"] = true;
    save.save_changes();

    //Retreive mock data
    bool funge = save.savefile["funge"];

    printw("%d",funge);
*/