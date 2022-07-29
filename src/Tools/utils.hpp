#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "ncurses.h"
#include "../UI/stats.hpp"
using namespace std;

enum custom_keys: unsigned int { Enter = 10 }; //Save custom keys here for easier access

 //Save game stuff for easier access from other classes
extern WINDOW* game_window;

//Simply print something to the screen with ncurses
void log(string msg);

//Stops the program until desidered key is pressed, if key param is not entered, any key is accepted
void wait_key(int key = -1);

//Show error message to user and close application (TODO, better GUI)
void fatal_error(string message);

//Configure NCurses and guide user to resize terminal window
void initial_setup(int room_width, int room_height, int *room_x, int *room_y);

#endif