#include <stdio.h>
#include <ncurses.h>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "headers/room.h"
#include "headers/utility.h"

const int room_width = 80;
const int room_height = 40;

using namespace std;


//Stops the program until desidered key is pressed, if key param is not entered, any key is accepted
void wait_key(int key = -1){
    int entered = -1;
    do{
        entered = getch();
    }while(key != entered && key != -1);
}

void init_game(int window_h, int window_w){

    //Clear the screen
    clear();

    //Center the box
    int window_x = (window_w-room_width)/2;
    int window_y = (window_h-room_height)/2;
    
 // player setup
    WINDOW * player_window;
    player_window = newwin(room_height, room_width, window_y, window_x);
    mvwaddch(player_window, room_width / 2 + window_x, window_y / 2 + room_height, 'c');
    refresh();
    box(player_window,0,0);
    wrefresh(player_window);
}

void initial_setup(WINDOW* win){

    //Show initial message
    log("Ridimensiona la seguente schermata a tuo piacimento, poi premi qualsiasi tasto per continuare!");
    wait_key();

    //Get window dimentions
    int window_h,window_w;
    getmaxyx(win,window_h,window_w);

    //Detect if window is too small
    if(window_w < room_width || window_h < room_height)
    {
        clear();
        log("La finestra corrente è troppo piccola per il gioco, ridimensionala e premi un tasto prima di continuare!");
        wait_key();
        clear();
        initial_setup(win); //Restart configuration
        return;
    }

    //Start drawing game
    init_game(window_h,window_w);
   

    getch();
}

int main(){


    WINDOW* win = initscr();
    noecho(); // doesn't echo user input on screen
    keypad(stdscr,TRUE); // allows keypad input
    curs_set(0); // disables cursor

    initial_setup(win);
    endwin();
    return 0;
}