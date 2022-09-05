#ifndef STATS_H
#define STATS_H
#include <string> 

using namespace std;

class Stats {

    private:

        //Params
        int maxAmmo , room;
        bool isReloading;
        string weapon_name;
        
        //Stats window coordinates
        int win_x, win_y;

        //Refresh stats window with updated params
        

    public:
        WINDOW* stats_window;
        Stats (int x, int y);

        // life 
        int life;
        void lost_life();
        void gained_life();
        void add_life(int amount);
        bool maxed_life();

        // points
        void add_points(int amount);
        int points;

        // weapon
        void set_weapon_name(string name);
        void reset_ammo();
        void lost_ammo();
        void add_ammo();
        void set_max_ammo(int max);
        void reloading(bool status);
        int ammo;

        // window
        void update_stats();

};



#endif