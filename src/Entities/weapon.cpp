#pragma once
#include <string>

class Weapon
{

public:
    std::string Name;
    int Range, Ammo, ReloadTime, FireRate, Price;
    Weapon(std::string Name, int Range, int Ammo, int ReloadTime, int FireRate, int Price)
    {
        this->Name = Name;
        this->Range = Range;
        this->Ammo = Ammo;
        this->ReloadTime = ReloadTime;
        this->FireRate = FireRate;
        this->Price = Price;
    }
};