#include <stdio.h>
#include <ncurses.h>
#include <string>
#include <fstream>
#include <iostream>
#include <future>
#include "room.hpp"
#include "Tools/utils.hpp"
#include "UI/dialog.hpp"
#include "Tools/savedata.hpp"
#include "panel.h"

using namespace std;


void initial_setup(){

    //Ncurses setup
    initscr();
    noecho(); // doesn't echo user input on screen
    keypad(stdscr,TRUE); // allows keypad input
    curs_set(0); // disables cursor

    //Check if terminal size is acceptable, guide the user to correct if not
    pair<int,int> dimensions;
    int offset = 5; //some padding
    int ended_resizing = 0;
    do{
        
        //Get current dimensions
        getmaxyx(stdscr,dimensions.first,dimensions.second);

        if(dimensions.first < room_height + offset || dimensions.second < room_width + offset){ //Terminal size not acceptable

            //Calculate how much the user has to widen terminal size
            int height_left = room_height-dimensions.first+offset;
            int width_left = room_width-dimensions.second+offset;

            //Help user resizing the window
            char message[300] = "La finestra corrente è troppo piccola per il gioco, allarga ancora ";
            if(height_left > 0)
                    sprintf(message + strlen(message), "%d in altezza e",height_left);
                if(width_left > 0)
                    sprintf(message + strlen(message), " %d in larghezza",width_left);
                else
                    message[strlen(message)-1] = ' ';

            //Print message to screen and wait for next resizement
            mvwprintw(stdscr,0,0, message);
            wait_key(KEY_RESIZE);
        }else {

            //Correct terminal size
            mvwprintw(stdscr,0,0, "La finestra è della dimensione giusta, premi Invio per avviare il gioco!");
            int entered_char = getch();
            if(entered_char == custom_keys::Enter)
                ended_resizing = 1;
        }

        clear();
    }
    while(ended_resizing != 1);
    

    //Center the box
    int window_y = (dimensions.first-room_height)/2;
    int window_x = (dimensions.second-room_width)/2;

    //Window setup
    WINDOW* start_window = newwin(room_height, room_width, window_y, window_x);
    
    //mvwaddch(player_window, room_width / 2 + window_x, window_y / 2 + room_height, 'c');
    refresh();
    box(start_window,0,0);
    wrefresh(start_window);

    //Add window as a panel to use stacked windows
    new_panel(start_window);
    update_panels();
    doupdate();

    //Save created window
    game_window = start_window;
}


int main(){

    //Configure Ncurses and init game window
    initial_setup();

    //Retreitve savedata
    savedata save;

    //TEST
    mvwprintw(game_window,0,0, "Premi invio per mostrare un popup");
    wrefresh(game_window);
    wait_key(custom_keys::Enter); 
    char msg[] = "ildioghane";
    dialog test = dialog(msg);
    test.show.wait();

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