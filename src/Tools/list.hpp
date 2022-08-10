#pragma once
#include "../Engine/gameobject.cpp"
#include "../Entities/player.hpp"

class GameObjectList{

    private:
        struct Node {
            GameObject* data;
            Node * next;
        };

        Node * head; // head is null by default
        
    
    public:
        Player * player; // save player object for easier access
        void insert(GameObject* item); // add new item
        void remove (GameObject* item); // remove item
        void doFrames(); // update all objects positions etc
        void draw(); // draw everything
        Entity* findEntityAtPos(int x, int y, GameObject* excluded = NULL); // find if there is an entity at desired position
        GameObjectList();
};