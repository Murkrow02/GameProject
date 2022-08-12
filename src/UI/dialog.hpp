#ifndef DIALOG_H
#define DIALOG_H

#include <future>
#include "../Tools/utils.hpp"
#include "ncurses.h"
#include "panel.h"

using namespace std;

class dialog {

    protected:

        //Set "q" as default key to close dialog
        int close_key = 113;

        //First and main line of the dialog
        char title[50];

        //Padding from game window borders
        int padding = 10;

    protected: 

        //Dialog size and position
        int y,x,h=5,w;

        WINDOW* dialog_window;
        PANEL* dialog_panel;

        //Draw title and boxes
        void draw();

        //Show "press x to close" message
        void show_close_message();

    public:

        dialog(char title[]);

        //Wait for current dialog close
        std::future<void> wait_close;

        //Custom close_key
        void set_close_key(int new_key);

        //Destroy
        void Destroy();

};

#endif