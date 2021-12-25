#include <string>
#include <ncurses.h>

using namespace std;

void log(string msg){
    printw(msg.data());
    refresh();
}

void wait_key(int key = -1){
    int entered = -1;
    do{
        entered = getch();
    }while(key != entered && key != -1);
}
