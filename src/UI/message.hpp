#include "dialog.hpp"


class message : public dialog {

    protected:

        //The message shown to the user
        char text[800]; 

        //How much space to leave from borders
        int padding = 3;

        //Ms delay between chars
        int speed = 25;

    public:

        message(char title[], char message[]);

};