#include "shop.hpp";
#include <chrono>
#include <thread>
#include "string.h"
#include <ncurses.h>

shop::shop():dialog("SHOP"){



        WINDOW *w = dialog_window;
        char list[5][7] = {"One", "Two", "Three", "Four", "Five"};
        char item[7];
        int ch, i = 0, width = 7;

        // now print all the menu items and highlight the first one
        for (i = 0; i < 5; i++)
        {
            if (i == 0)
                wattron(w, A_STANDOUT); // highlights the first item.
            else
                wattroff(w, A_STANDOUT);
            sprintf(item, "%-7s", list[i]);
            mvwprintw(w, i + 1, 2, "%s", item);
        }
        wrefresh(w); // update the terminal screen
        i = 0;

        nodelay(stdscr, FALSE);
        // get the input
        while (ch = getch() != 'q')
        {
            // right pad with spaces to make the items appear with even width.
            sprintf(item, "%-7s", list[i]);
            mvwprintw(w, i + 1, 2, "%s", item);

            // use a variable to increment or decrement the value based on the input.
            switch (ch)
            {
            case KEY_UP:
                i--;
                i = (i < 0) ? 4 : i;
                break;
            case KEY_DOWN:
                i++;
                i = (i > 4) ? 0 : i;
                break;
            }

            // now highlight the next item in the list.
            wattron(w, A_STANDOUT);
            sprintf(item, "%-7s", list[i]);
            mvwprintw(w, i + 1, 2, "%s", item);
            wattroff(w, A_STANDOUT);
        }
        delwin(w);
}

