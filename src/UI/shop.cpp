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
#include "../Entities/fruit.cpp"
#include "message.hpp"
using namespace std;

shop::shop(GameObjectList *game_items) : itemselector("SHOP", true, game_items)
{

    // WEAPONS
    weapons.push_back(Weapon("Arma forte 1", 10, 6, 30, 30, 1000, "Molto forte"));
    weapons.push_back(Weapon("Arma forte 2", 12, 7, 20, 30, 1500, "Più forte della 1"));
    weapons.push_back(Weapon("Arma forte 3", 15, 8, 20, 25, 2000, "Più forte della 2"));
    weapons.push_back(Weapon("Arma forte 4", 20, 9, 20, 20, 2500, "Più forte della 3"));
    weapons.push_back(Weapon("Arma forte 5", 25, 10, 15, 19, 3000, "Più forte della 4"));

    // REMOVE WEAPONS THAT USER ALREADY HAVE
    for (int i = 0; i < weapons.size(); i++) 
    {
        for (int j = 0; j < gameItems->player->weapons.size(); j++) 
        {
            // player already have that weapon, no need to display in shop
            if(weapons[i].Name == gameItems->player->weapons[j].Name)
                weapons.erase(weapons.begin() + i);
        }
    }

    // HEALING STUFF
    food.push_back(Apple(gameItems));
    food.push_back(Banana(gameItems));

    // PUT ALL TOGETHER
    copy(weapons.begin(), weapons.end(), back_inserter(shopItems)); // copy weapons in shopitems
    copy(food.begin(), food.end(), back_inserter(shopItems)); // copy food in shopitems
    
}

// override item selected
void shop::itemSelected(int index)
{
    // check if can buy
    if (gameItems->gameStats->points < shopItems[index].Price)
    {
        // cannot buy
        string msg = ("Non hai abbastanza punti per comprare " + shopItems[index].Name);
        message test = message("ATTENZIONE!", msg, true);
        return;
    }

    // detect if weapon or healing
    int weaponLastIndex = static_cast<int>(weapons.size()) - 1;
    int foodLastIndex = static_cast<int>(food.size()) - 1;
    
    // user selected a weapon
    if (index <= weaponLastIndex)
    {
        // add weapon to player's weapons
        gameItems->player->weapons.push_back(weapons[index]);

        // equip weapon
        gameItems->player->setWeapon(&gameItems->player->weapons.back());
    }
    // user selected food
    else
    {
        // check if already max life
        if(gameItems->gameStats->maxed_life()){

            // cannot buy
            string msg = ("La tua vita e' gia' al massimo");
            message test = message("ATTENZIONE!", msg, true);
            return;
        }

        int foodIndex = index-weaponLastIndex-1;

        // add life to user
        gameItems->gameStats->add_life(food[foodIndex].HealingAmount);
    }

     // subtract points
    gameItems->gameStats->add_points(-(shopItems[index].Price));

    // remove from shop if weapon
    if(index <= weaponLastIndex){
        weapons.erase(weapons.begin() + index);
        shopItems.erase(shopItems.begin() + index);
    }
}
