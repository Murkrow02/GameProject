#include "dialog.hpp"
#include "ncurses.h"
#include "panel.h"
#include "../Tools/utils.hpp"
#include <string>
#include <future>

using namespace std;

dialog::dialog(string title){

    this->title = title;

    //Draw alert
    draw();
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
    int title_len = title.length();
    int start_text_title = w/2-(title_len/2);
    mvwprintw(dialog_window, 0, start_text_title, title.c_str());
    
    //Update text content
    wrefresh(dialog_window);  
}

void dialog::set_close_key(int new_key){
        close_key = new_key;
}

void dialog::show_close_message(){

    //Insert bottom text to close
    string bottom_msg = "Premi q per chiudere questa schermata";
    int bottom_msg_len = bottom_msg.length();
    int start_text_bottom_msg = w/2-(bottom_msg_len/2);
    mvwprintw(dialog_window, h-1, start_text_bottom_msg, bottom_msg.c_str());
    wrefresh(dialog_window);  
}

void dialog::Destroy(){
    del_panel(dialog_panel);
}
