#pragma once
#include "dialog.hpp"
#include "itemselector.hpp"
#include "../Tools/ShopItem.hpp"
#include "../Entities/weapon.cpp"
#include <vector>
#include "../Entities/food.cpp"
#include "../Tools/GameObjectList.hpp"

class inventory : public itemselector {

    private:
        vector<Weapon> weapons;

    protected:
       void itemSelected(int index);

    public:
        inventory(GameObjectList* game_items);
};