#pragma once
#include "dialog.hpp"
#include "../Tools/ShopItem.hpp"
#include "../Entities/weapon.cpp"
#include <vector>

class itemselector : public dialog {

    private:
        bool showPrice;

    protected:
        vector<ShopItem> shopItems;
        void printItem(int index);
        //virtual void itemSelected(int index);

    public:
        void show();
        itemselector(char title[], bool show_price);
};