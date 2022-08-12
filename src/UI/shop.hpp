#pragma once
#include "dialog.hpp"
#include "itemselector.hpp"
#include "../Tools/ShopItem.hpp"
#include "../Entities/weapon.cpp"
#include <vector>
#include "../Entities/food.cpp"

class shop : public itemselector {

    private:
        vector<Weapon> weapons;
        vector<Food> food;

    protected:
       void itemSelected(int index);

    public:
        shop();
};