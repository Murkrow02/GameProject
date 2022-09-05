#pragma once
#include "artifact.hpp"
#include "../Engine/gameobject.hpp"
#include "../Tools/GameObjectList.hpp"
#include "../UI/shop.hpp"
#include "../Tools/ShopItem.hpp"

class Apple : public Food
{

public:

    Apple(GameObjectList *game_objects = NULL, int _y = 0, int _x = 0) : Food(1, "Mela", 25, "Ripristina un punto vita", CHAR_APPLE, game_objects, _x, _y)
    {
    }
};