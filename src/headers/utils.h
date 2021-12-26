#include <string>
using namespace std;

#define KEY_ENTER 10

enum custom_keys: unsigned int {  }; //Save custom keys here for easier access

const int room_width = 80; 
const int room_height = 40;

//Simply print something to the screen with ncurses
void log(string msg);

//Stops the program until desidered key is pressed, if key param is not entered, any key is accepted
void wait_key(int key = -1);

//Check if current window has valid size and returns dimensions if yes, otherwise guide user to find valid size
pair<int,int> check_win_size();

//Show error message to user and close application (TODO, better GUI)
void fatal_error(string message);