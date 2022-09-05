#pragma once
#include <string>
#include "../Tools/ShopItem.hpp"
#include "../Entities/artifact.hpp"
#include "../Tools/GameObjectList.hpp"
using namespace std;

class Food : public ShopItem, public Artifact
{

public:

    int HealingAmount = 0;

    Food(int healing_amount, string Name, int Price, string Description, char display_char, GameObjectList* game_items = NULL, int x = 0, int y = 0)  : Artifact(y,x, display_char, game_items)
    {
        this->Name = Name; // weapon name
        this->HealingAmount = healing_amount; // how much time to wait between 2 shots (in frames)
        this->Price = Price; // price at shop (in points)
        this->Description = Description; // description in shop
    }

protected:

    // override interacted
    void user_interacted()
    {
        // add life and destroy element only if player has not full life
        if(!gameItems->gameStats->maxed_life()){

            // add life
            gameItems->gameStats->add_life(HealingAmount);

            // remove object from play
            mvwaddch(gameItems->gameWindow, y, x, ' ');
            gameItems->remove(this);

            string msg = "Hai guadagnato " + to_string(HealingAmount) + " punti vita!";
            message recovered_life = message("", msg);
            recovered_life.wait_close.wait();
        }
        
    }
};