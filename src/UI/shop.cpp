#include "shop.hpp"
#include "itemselector.hpp"
#include <chrono>
#include <thread>
#include <string>
#include <ncurses.h>
#include <vector>
#include "../Entities/weapon.cpp"
#include "../Tools/ShopItem.hpp"
#include "../Tools/GameObjectList.hpp"
#include "message.hpp"
using namespace std;

shop::shop(GameObjectList *game_items) : itemselector("SHOP", true, game_items)
{

    // WEAPONS TODO: check if already bought
    weapons.push_back(Weapon("Arma forte", 10, 10, 5, 10, 0, "Molto forte"));
    weapons.push_back(Weapon("Arma forte 2", 20, 10, 2, 1, 300, "Moltissimo forte"));
    weapons.push_back(Weapon("Arma forte 3", 20, 10, 2, 1, 300, "Moltissimo forte"));
    weapons.push_back(Weapon("Arma forte 4", 20, 10, 2, 1, 100, "Moltissimo forte"));
    weapons.push_back(Weapon("Arma forte 5", 20, 10, 2, 1, 300, "Moltissimo forte"));

    // HEALING STUFF

    // PUT ALL TOGETHER
    shopItems.push_back(weapons[0]);
    shopItems.push_back(weapons[1]);
    shopItems.push_back(weapons[2]);
    shopItems.push_back(weapons[3]);
    shopItems.push_back(weapons[4]);
}

// override item selected
void shop::itemSelected(int index)
{

    // detect if weapon or healing
    int weaponLastIndex = static_cast<int>(weapons.size()) - 1;
    int foodLastIndex = static_cast<int>(food.size()) - 1;

    if (index <= weaponLastIndex)
    {

        // check if can buy
        if (gameItems->gameStats->points < weapons[index].Price)
        {
            // cannot buy
            string msg = ("Non hai abbastanza punti per comprare " + weapons[index].Name);
            message test = message("ATTENZIONE!", msg, true);
            return;
        }
        else
        {
            // can buy
            gameItems->gameStats->add_points(-(weapons[index].Price)); // subtract points

            // add weapon to player's weapons
            gameItems->player->weapons.push_back(weapons[index]);

            // equip weapon
            gameItems->player->setWeapon(&gameItems->player->weapons.back());

            // remove from shop
            weapons.erase(weapons.begin() + index);
            shopItems.erase(shopItems.begin() + index);
        }
    }
    else
    {
        // select food
    }
}
