#include "itemselector.hpp"
#include <chrono>
#include <thread>
#include <string> 
#include <ncurses.h>
#include <vector>
#include "../Tools/ShopItem.hpp"
#include "../Tools/GameObjectList.hpp"

using namespace std;

itemselector::itemselector(char title[], bool show_price, GameObjectList *game_items) : dialog(title){

    showPrice = show_price;
    gameItems = game_items;
}

int padding = 2;
int spacing = 2;
int pointsLen = 5;
int nameLen = 15;

void itemselector::printItem(int index){

    // setup
    int pointsStartPoint, nameStartPoint, descStartPoint;
    pointsStartPoint = padding;
    if (showPrice)
        nameStartPoint = pointsStartPoint + pointsLen + spacing;
    else
        nameStartPoint = padding;
    descStartPoint = nameStartPoint + nameLen + spacing;

    // POINTS PRICE
    if(showPrice){
        wattron(dialog_window, COLOR_PAIR(2));
        mvwprintw(dialog_window, index + 1, pointsStartPoint, to_string(shopItems[index].Price).c_str());
        wattroff(dialog_window, COLOR_PAIR(2));
    }

    // ITEM NAME 
    mvwprintw(dialog_window, index + 1, nameStartPoint , shopItems[index].Name.c_str());

    // ITEM DESC 
    mvwprintw(dialog_window, index + 1, descStartPoint , shopItems[index].Description.c_str());

}

void itemselector::show(){

    wclear(dialog_window);

    // resize window based on items count
    itemsCount = static_cast<int>(shopItems.size());
    dialog::h = itemsCount + 2; // boh
    dialog::draw();

    // no elements, no need to show shop
    if(itemsCount < 1)
    {
        Destroy();
        return;
    }

    // Print all elements
    for (int i = 0; i < itemsCount; i++)
    {
        // highlights the first item if first render
        if (i == 0)
            wattron(dialog_window, A_STANDOUT);
        else
            wattroff(dialog_window, A_STANDOUT);

        // insert item in menu
        printItem(i);
        wattroff(dialog_window, A_STANDOUT);
    }

    // update the terminal screen
    wrefresh(dialog_window);
    // enable keypad input for the window.
    keypad(dialog_window, TRUE);
    // hide the default screen cursor.
    curs_set(0);

    dialog::show_close_message();

    // get the input
    int index = 0;
    int ch = 0;

    while (ch != 'q' && ch != custom_keys::Enter)
    {
        // get input from user
        ch = wgetch(dialog_window);

        // right pad with spaces to make the items appear with even width.
        printItem(index);

        // use a variable to increment or decrement the value based on the input.
        switch (ch)
        {
        case KEY_UP:
            index--;
            index = (index < 0) ? itemsCount-1 : index;
            break;
        case KEY_DOWN:
            index++;
            index = (index > itemsCount-1) ? 0 : index;
            break;

        case custom_keys::Enter:
            itemSelected(index);
            break;
        }
       
        // now highlight the next item in the list.
        wattron(dialog_window, A_STANDOUT);
        printItem(index);
        wattroff(dialog_window, A_STANDOUT);
    }


    // exit
    if(ch == 'q')
        Destroy();
    else if (ch == custom_keys::Enter)
        show(); // repeat
}

