#pragma once
#include <string>

class Weapon
{

public:
    std::string Name;
    int Range, Ammo, ReloadTime, FireRate, Price;
    Weapon(std::string Name, int Range, int Ammo, int ReloadTime, int FireRate, int Price)
    {
        this->Name = Name; // weapon name
        this->Range = Range; // how far the bullet can go (in pixels)
        this->Ammo = Ammo; // maximum number of ammo charger can hold
        this->ReloadTime = ReloadTime; // how much time for each bullet to be reloaded (in frames)
        this->FireRate = FireRate; // how much time to wait between 2 shots (in frames)
        this->Price = Price; // price at shop (in points)
    }
};