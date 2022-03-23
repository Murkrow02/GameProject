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

    //Async function to create and destroy alert
    wait_close = std::async(std::launch::async, [this,text]
    { 
        
        //Calculate how much lines of height to use
        int max_line_len = this->w-(2*padding);
        int msg_len = strlen(text);

        int current_row_len = 0;
        int current_row_selected = 2;
        char current_line_txt[max_line_len];
        char** lines; //!!!
        for (size_t i = 0; i < msg_len; i++)
        {
            //Char position exceeded maximum row size
            if(current_row_len >= max_line_len){
                current_row_selected++;
                current_row_len = 0;

                //Update dialog size and position
                h=h+1;
                dialog::draw();

                //Insert previous lines !!!!
            }
        
            //Update text content in window
            mvwaddch(dialog_window, current_row_selected, current_row_len+padding , text[i]);
            wrefresh(dialog_window);

            //Copy current char in current line string
            current_line_txt[current_row_len] = text[i];
                
            //Wait until next char add
            std::this_thread::sleep_for(std::chrono::milliseconds(30));

            //Increment row position
            current_row_len++;
        }

        //Wait for user to press escape key
        dialog::wait_close.wait();

    });

}

/*message::show(){


       
}*/