#pragma once
#include "dialog.hpp"
#include <string>

class message : public dialog {

    protected:

        //The message shown to the user
        string text; 

        //How much space to leave from borders
        int padding = 3;

        //Ms delay between chars
        int speed = 22;

    public:

        message(string title, string message, bool autoClose = false);

        //Wait for current dialog close
        std::future<void> wait_close;

};