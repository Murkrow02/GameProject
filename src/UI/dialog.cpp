#include "dialog.hpp"
#include "ncurses.h"
#include "panel.h"
#include "../Tools/utils.hpp"
#include <string.h>
#include <future>

using namespace std;

dialog::dialog(char title[]){

    strcpy(this->title, title);

    //Draw alert
    draw();

    //This functions awaits until the desidered key is pressed
    wait_close = std::async(std::launch::async, [this,title]
    {
        //Wait for dismissal
        wait_key(close_key);
        del_panel(dialog_panel);
    });
}

void dialog::draw(){

    //Game box dimensions
    int gy, gx, gh, gw;
    getmaxyx(game_window,gh,gw);
    getbegyx(game_window,gy,gx);

    //Update dimensions based on padding
    w = gw-padding;
    x = gx+(padding/2);

    //Center alert in box
    y = gy+(gh/2)-(h/2);

    //Create window and put it inside a panel
    dialog_window = newwin(h,w,y,x);
    box(dialog_window, 0, 0);
    dialog_panel = new_panel(dialog_window);
    update_panels();
    doupdate();

    //Insert title
    int title_len = strlen(title);
    int start_text_title = w/2-(title_len/2);
    mvwprintw(dialog_window, 0, start_text_title, title);

    //Insert bottom text to close
    char bottom_msg[] = "Premi q per chiudere questa schermata";
    int bottom_msg_len = strlen(bottom_msg);
    int start_text_bottom_msg = w/2-(bottom_msg_len/2);
    mvwprintw(dialog_window, h-1, start_text_bottom_msg, bottom_msg);
    
    //Update text content
    wrefresh(dialog_window);  
}

void dialog::set_close_key(int new_key){
        close_key = new_key;
}
