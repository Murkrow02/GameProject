#ifndef STATS_H
#define STATS_H

using namespace std;

class Stats {

    private:

        //Params
        int life, points, room;
        
        //Stats window coordinates
        int win_x, win_y;

        //Refresh stats window with updated params
        void update_stats();

    public:
        WINDOW* stats_window;
        Stats (int x, int y);
        void lost_life();
        void gained_life();
        void set_life();
        void add_points();
        
};



#endif