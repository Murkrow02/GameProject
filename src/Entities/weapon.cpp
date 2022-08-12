#pragma once
#include <string>
#include "../Tools/ShopItem.hpp"

using namespace std;

class Weapon : public ShopItem
{

public:

    int Range, Ammo, ReloadTime, FireRate;
    Weapon(string Name, int Range, int Ammo, int ReloadTime, int FireRate, int Price, string Description = "")
    {
        this->Name = Name; // weapon name
        this->Range = Range; // how far the bullet can go (in pixels)
        this->Ammo = Ammo; // maximum number of ammo charger can hold
        this->ReloadTime = ReloadTime; // how much time for each bullet to be reloaded (in frames)
        this->FireRate = FireRate; // how much time to wait between 2 shots (in frames)
        this->Price = Price; // price at shop (in points)
        this->Description = Description; // description in shop
    }
};