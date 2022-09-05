#include "ncurses.h"
#include "stats.hpp"
#include <string> 
#include "../Engine/gameobject.hpp"

Stats::Stats(int x, int y, bool _infiniteLife){

    //Create window for informations
    stats_window = newwin(20, 20, y, x);

    //Set configuration attributes
    life = LIFE_PLAYER;
    infiniteLife = _infiniteLife;
    points = 0;
    win_x = x;
    win_y = y;

    //Print stats to screen
    update_stats();

}

void Stats::lost_life(){

    if(infiniteLife)
        return;

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

void Stats::add_life(int amount){

    //Check if reached maximum life
    if(life+amount > LIFE_PLAYER)
        life = LIFE_PLAYER; // maximum life
    else
        life += amount;

    update_stats();
}

bool Stats::maxed_life(){
    return life >= LIFE_PLAYER;
}


void Stats::add_points(int amount){
    points+=amount;
    update_stats();
}

void Stats::reset_ammo(){
    ammo = maxAmmo;
    update_stats();
}

void Stats::lost_ammo(){
    if(ammo > 0)
        ammo--;
    update_stats();
}

void Stats::add_ammo(){
    if(ammo < maxAmmo)
        ammo++;
    update_stats();
}

void Stats::set_max_ammo(int max){
    maxAmmo = max;
}

void Stats::set_weapon_name(string name){
    weapon_name = name;
    update_stats();
}

void Stats::reloading(bool status){
    isReloading = status;
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

    //WEAPON
    if(!weapon_name.empty()){

        mvwprintw(stats_window,3,0, weapon_name.c_str());
        
        // show ammo
        if(!isReloading){
            wattron(stats_window,A_BOLD);
            mvwprintw(stats_window, 4, 0, "AMMO:");
            wattron(stats_window, A_BOLD);
            wattron(stats_window, COLOR_PAIR(3));
            for (int i = 0; i < ammo; i++)
            {
                wprintw(stats_window, "X");
            }
            wattroff(stats_window, COLOR_PAIR(3));
        }else{
            // show reloading
            wattron(stats_window,COLOR_PAIR(1));
            mvwprintw(stats_window, 4, 0, "RELOADING");
            wattroff(stats_window,COLOR_PAIR(1));
        }
        
    }
   

    //Update on screen
    wrefresh(stats_window);
}