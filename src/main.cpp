#include <stdio.h>
#include <ncurses.h>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "headers/room.h"
#include "headers/utils.h"

using namespace std;


void init_game(int window_h, int window_w){

    //Clear the screen
    clear();

    //Center the box
    int window_x = (window_w-room_width)/2;
    int window_y = (window_h-room_height)/2;
    
    //Player setup
    WINDOW * player_window;
    player_window = newwin(room_height, room_width, window_y, window_x);
    mvwaddch(player_window, room_width / 2 + window_x, window_y / 2 + room_height, 'c');
    refresh();
    box(player_window,0,0);
    wrefresh(player_window);
}



WINDOW* initial_setup(){

    //Configure Ncurses
    WINDOW* win = initscr();
    noecho(); // doesn't echo user input on screen
    keypad(stdscr,TRUE); // allows keypad input
    curs_set(0); // disables cursor

    //Detect if window is too small and return screen dimensions if accepted size
    pair<int,int> dimensions = check_win_size();

    //Start drawing game
    init_game(dimensions.first,dimensions.second);
   
    return win;
}

int main(){

    




    //Configure Ncurses and init game window
    WINDOW* win = initial_setup();

    wait_key(KEY_ENTER); //Prevent program from closing

    endwin();
    return 0;
}