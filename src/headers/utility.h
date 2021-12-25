#include <string>
using namespace std;

//Simply print something to the screen with ncurses
void log(string msg);

//Stops the program until desidered key is pressed, if key param is not entered, any key is accepted
void wait_key(int key = -1);