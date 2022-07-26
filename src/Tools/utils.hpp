#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "ncurses.h"

using namespace std;

enum custom_keys: unsigned int { Enter = 10 }; //Save custom keys here for easier access

extern WINDOW* game_window; //Save game window for easier access from other classes

const int room_width = 80; 
const int room_height = 40;

//Simply print something to the screen with ncurses
void log(string msg);

//Stops the program until desidered key is pressed, if key param is not entered, any key is accepted
void wait_key(int key = -1);

//Show error message to user and close application (TODO, better GUI)
void fatal_error(string message);

//Configure NCurses and guide user to resize terminal window
void initial_setup();

#endif