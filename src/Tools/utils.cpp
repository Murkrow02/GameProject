#include <string>
#include <ncurses.h>
#include "utils.hpp"
#include <iostream>
#include <cstring>
#include "../UI/dialog.hpp"

using namespace std;

WINDOW* game_window;

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
