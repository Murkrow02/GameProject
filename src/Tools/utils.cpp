#include <string>
#include <ncurses.h>
#include "utils.hpp"
#include <iostream>
#include <cstring>

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
    int offset = 5; //some padding
    if(dimensions.first < room_height + offset || dimensions.second < room_width + offset)
        {
            //Clear current screen
            clear(); 

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
        
            //Print message to the screen
            log(message); 

            //Wait until next resize
            wait_key(KEY_RESIZE);

            //Restart check 
            check_win_size(); 
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
