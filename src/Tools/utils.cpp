#include <string>
#include <ncurses.h>
#include "utils.hpp"
#include <iostream>
#include <cstring>
#include "../UI/dialog.hpp"
#include "../UI/stats.hpp"

using namespace std;

//Save stuff for easy access on other classes
WINDOW* game_window; stats* game_stats;

void log(string msg){
    printw(msg.data());
    refresh();
}

void wait_key(int key){
    int entered = -1;
    do{
        entered = getch();
    }while(key != entered && key != -1);
}

void fatal_error(string message){

    //End ncurses
    endwin();

    cout << message;

    exit(0);
}

void initial_setup(){

    //Ncurses setup
    initscr();
    noecho(); // doesn't echo user input on screen
    keypad(stdscr,TRUE); // allows keypad input
    curs_set(0); // disables cursor

    //Check if terminal size is acceptable, guide the user to correct if not
    pair<int,int> dimensions;
    //some padding
    int offset_x = 35; 
    int offset_y = 5;
    int ended_resizing = 0;
    do{
        
        //Get current dimensions
        getmaxyx(stdscr,dimensions.first,dimensions.second);

        if(dimensions.first < room_height + offset_y || dimensions.second < room_width + offset_x){ //Terminal size not acceptable

            //Calculate how much the user has to widen terminal size
            int height_left = room_height-dimensions.first+offset_y;
            int width_left = room_width-dimensions.second+offset_x;

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
    game_window = newwin(room_height, room_width, window_y, window_x);
    
    //mvwaddch(player_window, room_width / 2 + window_x, window_y / 2 + room_height, 'c');
    refresh();
    box(game_window,0,0);
    wrefresh(game_window);

    //Add window as a panel to use stacked windows
    new_panel(game_window);
    update_panels();
    doupdate();

    //Init stat screen
    int x_stat = window_x + room_width + 2;
    int y_stat = window_y + 1;
    stats new_stats;
    game_stats = new_stats.init_stats(x_stat,y_stat); 

}


