#include "message.hpp";
#include <chrono>
#include <thread>
#include "string.h"

/*
    TODO
    - metti velocità ai dialoghi
    - metti che quando ci sta spazio si ferma un attimo

*/

message::message(char title[], char text[]):dialog(title){


    strcpy(this->text, text);

    //Calculate how much lines of height to use
    int max_line_len = this->w-(2*padding);
    int msg_len = strlen(text);
   
    //Start showing message char by char
    int current_row_len = 0;
    int current_row_selected = 0;
    char current_line_txt[max_line_len+1];
    std::string lines[20];
    for (size_t i = 0; i < msg_len; i++)
    { 
        //Char position exceeded maximum row size
        if(current_row_len >= max_line_len){

            //Update dialog size and position (+2 otherwise is not centered)
            h++;
            dialog::draw();

            //Insert previous lines
            current_line_txt[current_row_len] = '\0';
            lines[current_row_selected] = current_line_txt;
            for (int j = 0; j < current_row_selected+1; j++)
            {
                char tmp_line_text[max_line_len+1];
                strcpy(tmp_line_text, lines[j].c_str());
                mvwprintw(dialog_window, j+2, padding, tmp_line_text);
            }
            
            //Reset current line content
            strcpy(current_line_txt,"");
            current_row_selected++;
            current_row_len = 0;
        }
    
        //Update text content in window
        mvwaddch(dialog_window, current_row_selected+2, current_row_len+padding , text[i]);
        wrefresh(dialog_window);

        //Copy current char in current line string
        current_line_txt[current_row_len] = text[i];
            
        //Wait until next char add
        std::this_thread::sleep_for(std::chrono::milliseconds(speed));

        //Increment row position
        current_row_len++;
    }

    //Async function to create and destroy alert MOVE DOWN
    wait_close = std::async(std::launch::async, [this,text]
    { 
        //Wait for user to press escape key
        dialog::show_close_message();
        wait_key(close_key);
        Destroy();
    });
   
}