#include <string>
#include <ncurses.h>
#include "headers/utils.hpp"
#include <iostream>

using namespace std;

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

pair<int,int> check_win_size(){

    pair<int,int> dimensions;

    //Get window dimentions
    getmaxyx(stdscr,dimensions.first,dimensions.second);

    //Check if too small
    if(dimensions.first < room_height || dimensions.second < room_width)
        {
            clear(); //Clear current screen

            //Calculate how much the user has to widen term size
            string height_left = to_string(room_height-dimensions.first);
            string width_left = to_string(room_width-dimensions.second);
            string message = "La finestra corrente è troppo piccola per il gioco, ancora " + height_left + " y e " + width_left + " x"; 
            //TODO non mostrare se valore negativo
        
            log(message); //Print message to the screen

            wait_key(KEY_RESIZE); //Wait until next resize

            check_win_size(); //Restart check
        }

    //Return screen dimensions
    return dimensions;
}

void fatal_error(string message){

    //End ncurses
    endwin();

    cout << message;

    exit(0);
}
