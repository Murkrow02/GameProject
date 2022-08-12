#include "shop.hpp"
#include "itemselector.hpp"
#include <chrono>
#include <thread>
#include <string> 
#include <ncurses.h>
#include <vector>
#include "../Entities/weapon.cpp"
#include "../Tools/ShopItem.hpp"

using namespace std;

shop::shop() : itemselector("SHOP", true){

    // WEAPONS TODO: check if already bought
    weapons.push_back(Weapon("Arma forte", 10, 10, 5, 10, 200, "Molto forte"));
    weapons.push_back(Weapon("Arma forte 2", 20, 10, 2, 1, 300, "Moltissimo forte"));

    // HEALING STUFF

    // PUT ALL TOGETHER
    shopItems.push_back(weapons[0]);
    shopItems.push_back(weapons[1]);
    shopItems.push_back(weapons[1]);
    shopItems.push_back(weapons[1]);
    shopItems.push_back(weapons[1]);
    shopItems.push_back(weapons[1]);
    shopItems.push_back(weapons[1]);
    shopItems.push_back(weapons[1]);
}

// override item selected
void shop::itemSelected(int index){

    // detect if weapon or healing
    int weaponLastIndex = static_cast<int>(weapons.size()) -1;
    int foodLastIndex = static_cast<int>(food.size()) -1;

    if(index <= weaponLastIndex){
        // select weapon

        // remove from shop
        weapons.erase(weapons.begin() + index);
    }else{
        // select food
    }

}


