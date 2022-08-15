#pragma once
#include "../Entities/player.hpp"
#include "../Engine/minimap.h"


class GameObject;
class GameObjectList{

    private:
        struct Node {
            GameObject* data;
            Node * next;
        };

        Node * head; // head is null by default
        
    
    public:

        // save game stuff for easier access
        Player* player; 
        Stats* gameStats;
        WINDOW* gameWindow;
        Map* gameMap;
        Minimap* gameMinimap;

        void insert(GameObject* item); // add new item
        void remove (GameObject* item); // remove item
        void doFrames(); // update all objects positions etc
        void draw(); // draw everything

        Entity* findEntityAtPos(int x, int y, GameObject* excluded = NULL); // find if there is an entity at desired position
        GameObjectList();
};