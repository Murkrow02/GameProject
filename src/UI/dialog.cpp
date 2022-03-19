#include "dialog.hpp"
#include "ncurses.h"
#include "panel.h"
#include "../Tools/utils.hpp"
#include <string.h>
#include <future>

using namespace std;

dialog::dialog(char title[], int custom_key, int custom_y, int custom_x){

    strcpy(this->title, title);

    //Set dialog size and coordinates
    if(custom_y == -1){ //Center in middle of game box

        //Game box dimensions
        int gy, gx, gh, gw;
        getmaxyx(game_window,gh,gw);
        getbegyx(game_window,gy,gx);

        //Update dimensions based on padding
        w = gw-padding;
        x = gx+(padding/2);

        //Center alert in box
        y = gy+(gh/2)-(h/2);

    }else { //Custom position
        y = custom_y;
        x = custom_x;
        w = room_width;
    }

    

    //Async function to create and destroy alert
    show = std::async(std::launch::async, [this,title, custom_key]
    { 
  
    //Create window and put it inside a panel
    WINDOW* dialog_win = newwin(h,w,y,x);
    box(dialog_win, 0, 0);
    PANEL* dialog_panel = new_panel(dialog_win);
    update_panels();
    doupdate();

    //Insert title
    int title_len = strlen(title);
    int start_text_title = w/2-(title_len/2);
    mvwprintw(dialog_win, 0, start_text_title, title);

    //Insert bottom text to close
    char bottom_msg[] = "Premi q per chiudere questa schermata";
    int bottom_msg_len = strlen(bottom_msg);
    int start_text_bottom_msg = w/2-(bottom_msg_len/2);
    mvwprintw(dialog_win, h-1, start_text_bottom_msg, bottom_msg);
    
    //Update text content
    wrefresh(dialog_win);

    //Wait for dismissal
    wait_key(custom_key);
    del_panel(dialog_panel);
    
    
    });

}
