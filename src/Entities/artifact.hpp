#pragma once
#include <ncurses.h>
#include <stdlib.h>
#include "../Engine/map.hpp"
#include "../UI/stats.hpp"
#include "../Engine/gameobject.hpp"
#include "../Tools/GameObjectList.hpp"

class Artifact : public GameObject
{
    public:
        Artifact(int _y, int _x, char display_char, GameObjectList *_gameItems);

    protected:

        // update entity status
        virtual void DoFrame();
        virtual void Draw();

        //game stats
        int life;
        GameObjectList *gameItems;

        virtual void user_interacted() = 0;
};