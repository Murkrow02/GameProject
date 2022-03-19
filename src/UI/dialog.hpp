#ifndef DIALOG_H
#define DIALOG_H

#include <future>
#include "../Tools/utils.hpp"


using namespace std;

class dialog {

protected: 

    //First and main line of the dialog
    char title[50];

    //Dialog size and position
    int y,x,h=10,w;

    //Padding from game window borders
    int padding = 10;

public:

    dialog(char title[], int custom_key = 113, int custom_y = -1, int custom_x = -1); //By default the dialog is centered based on the game box position

    //Show current dialog
    std::future<void> show;

};

#endif