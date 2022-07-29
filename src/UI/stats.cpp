#include "ncurses.h"
#include "stats.hpp"
#include <string> 

//Configuration
int start_life = 5;
int max_life = 5;

stats::stats(int x, int y){

    //Create window for informations
    stats_window = newwin(20, 20, y, x);

    //Set configuration attributes
    life = start_life;
    points = 0;
    win_x = x;
    win_y = y;

    //Print stats to screen
    update_stats();

}

void stats::lost_life(){

    if(life == 0){
        //GAMEOVER
    }
    else
        life--;

    update_stats();
}

void stats::gained_life(){

    //Check if reached maximum life
    if(life < max_life)
        life++;

    update_stats();
}

void stats::update_stats(){

    //Clear old stats
    wclear(stats_window);

    //LIFE
    attron(A_BOLD);
    mvwprintw(stats_window, 0, 0, "LIFE:");
    attroff(A_BOLD);

    for (int i = 0; i < life; i++)
    {
        wprintw(stats_window, "X"); //heart emoji is not working idk
    }

    //POINTS
    attron(A_BOLD);
    mvwprintw(stats_window,1,0,"POINTS:");
    attroff(A_BOLD);
    wprintw(stats_window, std::to_string(points).c_str());

    //Update on screen
    wrefresh(stats_window);
}