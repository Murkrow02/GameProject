#include "dialog.hpp"
#include "ncurses.h"
#include "panel.h"
#include "Tools/utils.hpp"
#include <string.h>


dialog::dialog(char title[]){
    strcpy(this->title, title);
}


void dialog::show(){


    int lines = 10, cols = 40, y = 2, x = 4, i;
    WINDOW* a = newwin(lines, cols, y, x);
    box(a, 0, 0);

    new_panel(a);

    update_panels();
    doupdate();
}
