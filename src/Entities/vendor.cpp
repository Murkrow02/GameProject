#pragma once
#include "artifact.hpp"
#include "../Engine/gameobject.hpp"
#include "../Tools/GameObjectList.hpp"
#include "../UI/shop.hpp"
class Vendor : public Artifact
{

public:
    Vendor(int _y, int _x, GameObjectList *game_objects) : Artifact(_y, _x, CHAR_SHOP, game_objects)
    {
    }

protected:

    // override interacted
    void user_interacted()
    {
        shop shop_win = shop(gameItems);
        shop_win.show();
    }
};