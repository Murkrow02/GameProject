#pragma once
#include "../Entities/player.hpp"
#include "../Engine/minimap.h"
#include "GameObjectNode.hpp"

class Minimap;
class GameObject;
class GameObjectList : public GameObjectNode{
         
    public:

        // save game stuff for easier access
        Player* player; 
        Stats* gameStats;
        WINDOW* gameWindow;
        Map* gameMap;
        Minimap* gameMinimap;
        bool key;
        double difficultyLevel;
        int roomsToClear;

        void doFrames(); // update all objects positions etc
        void draw(); // draw everything
        void reset();

        GameObjectList();
};