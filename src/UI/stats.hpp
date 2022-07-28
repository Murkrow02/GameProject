#ifndef STATS_H
#define STATS_H

using namespace std;

class stats {

    private:

        //Params
        int life, points, room;
        
        //Stats window coordinates
        int win_x, win_y;

        void update_stats();

    public:
        WINDOW* stats_window;
        stats* init_stats(int x, int y);
        void lost_life();
        void gained_life();
        void set_life();
        void add_points();
        
};



#endif