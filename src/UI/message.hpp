#pragma once
#include "dialog.hpp"


class message : public dialog {

    protected:

        //The message shown to the user
        char text[800]; 

        //How much space to leave from borders
        int padding = 3;

        //Ms delay between chars
        int speed = 30;

    public:

        message(char title[], char message[]);

        //Wait for current dialog close
        std::future<void> wait_close;

};