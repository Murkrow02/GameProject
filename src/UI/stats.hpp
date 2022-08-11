#ifndef STATS_H
#define STATS_H
#include <string> 

using namespace std;

class Stats {

    private:

        //Params
        int life, points, maxAmmo , room;
        string weapon_name;
        
        //Stats window coordinates
        int win_x, win_y;

        //Refresh stats window with updated params
        void update_stats();

    public:
        WINDOW* stats_window;
        Stats (int x, int y);

        // life 
        void lost_life();
        void gained_life();
        void set_life();

        // points
        void add_points(int amount);

        // weapon
        void set_weapon_name(string name);
        void reset_ammo();
        void lost_ammo();
        void set_max_ammo(int max);
        int ammo;
};



#endif