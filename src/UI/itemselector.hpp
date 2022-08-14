#pragma once
#include "dialog.hpp"
#include "../Tools/ShopItem.hpp"
#include "../Entities/weapon.cpp"
#include <vector>
#include "../Tools/GameObjectList.hpp"

class itemselector : public dialog {

    private:
        bool showPrice;
        int itemsCount;

    protected:
        vector<ShopItem> shopItems;
        void printItem(int index);
        virtual void itemSelected(int index) = 0;
        GameObjectList* gameItems;

    public:
        void show();
        itemselector(char title[], bool show_price,GameObjectList* gameItems);
};