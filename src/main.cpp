#include <stdio.h>
#include <ncurses.h>
#include <string>
#include <fstream>
#include <iostream>
#include <future>
#include "room.hpp"
#include "Tools/utils.hpp"
#include "UI/message.hpp"
#include "UI/dialog.hpp"
#include "Tools/savedata.hpp"
#include "panel.h"
#include "Entities/entity.hpp"
#include "Entities/player.hpp"

using namespace std;

int main()
{

    // Configure Ncurses and init game_window
    initial_setup();

    // Retreitve savedata
    savedata save;

    int ch;
    Position start_pos = {10, 20};

    initscr();
    noecho();
    curs_set(0);

    Entity* player = create_player(start_pos);
    mvaddch(player->pos.y, player->pos.x, player->ch);

    while (ch = getch())
    {
        if (ch == 'q')
        {
            break;
        }

        move_player(ch, player);
        clear();
        mvaddch(player->pos.y, player->pos.x, player->ch);
    }

    endwin();

    return 0;

    // TEST
    mvwprintw(game_window, 1, 1, "Premi invio per mostrare un popup");
    wrefresh(game_window);
    wait_key(custom_keys::Enter);
    char msg[] = "ildioghane";
    message test = message(msg, "il dio ghane il dio ghane il dio ghane il dio ghane il dio ghane il dio ghane il dio ghane il dio ghane il dio ghane il dio ghane il dio ghane il dio ghane il dio ghane il dio ghane il dio ghane il dio ghane il dio ghane ");
    test.wait_close.wait();

    getch();
    endwin();
    return 0;
}

/*
    //Test by saving mock data
    save.savefile["funge"] = true;
    save.save_changes();

    //Retreive mock data
    bool funge = save.savefile["funge"];

    printw("%d",funge);
*/