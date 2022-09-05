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

class Banana : public Food
{

public:

    Banana(GameObjectList *game_objects = NULL, int _y = 0, int _x = 0) : Food(3, "Banana", 50, "Ripristina 3 punti vita", CHAR_BANANA, game_objects, _x, _y)
    {
    }
};