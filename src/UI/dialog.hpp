#ifndef DIALOG_H
#define DIALOG_H

class dialog {

protected: 

    //First and main line of the dialog
    char title[50];

    


public:

    dialog(char title[]);

    //Show current dialog
    void show();
};

#endif