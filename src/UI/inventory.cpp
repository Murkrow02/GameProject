#include "inventory.hpp"
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

inventory::inventory(GameObjectList *game_items) : itemselector("Equipaggia arma", false, game_items)
{
    // insert all player weapons into list to display
    copy(game_items->player->weapons.begin(), game_items->player->weapons.end(), back_inserter(shopItems));
}

// override item selected
void inventory::itemSelected(int index)
{
    gameItems->player->setWeapon(&gameItems->player->weapons[index]);
}
