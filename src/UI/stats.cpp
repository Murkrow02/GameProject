#include "ncurses.h"
#include "stats.hpp"
#include <string> 
#include "../Engine/gameobject.cpp"


Stats::Stats(int x, int y){

    //Create window for informations
    stats_window = newwin(20, 20, y, x);

    //Set configuration attributes
    life = LIFE_PLAYER;
    points = 0;
    win_x = x;
    win_y = y;

    //Print stats to screen
    update_stats();

}

void Stats::lost_life(){

    if(life == 0){
        //GAMEOVER
    }
    else
        life--;

    update_stats();
}

void Stats::gained_life(){

    //Check if reached maximum life
    if(life < LIFE_PLAYER)
        life++;

    update_stats();
}

void Stats::update_stats(){

    //Clear old stats
    wclear(stats_window);

    //LIFE
    wattron(stats_window,A_BOLD);
    mvwprintw(stats_window, 0, 0, "LIFE:");
    wattroff(stats_window,A_BOLD);
    
    wattron(stats_window,COLOR_PAIR(1));
    for (int i = 0; i < life; i++)
    {
        wprintw(stats_window, "X"); //heart emoji is not working idk
    }
    wattroff(stats_window,COLOR_PAIR(1));

    //POINTS
    wattron(stats_window,A_BOLD);
    mvwprintw(stats_window,1,0,"POINTS:");
    wattron(stats_window,A_BOLD);
    wattron(stats_window,COLOR_PAIR(2));
    wprintw(stats_window, std::to_string(points).c_str());
    wattroff(stats_window,COLOR_PAIR(2));

    //Update on screen
    wrefresh(stats_window);
}