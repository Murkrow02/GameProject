#pragma once
#include "../Entities/player.hpp"
#include "../Entities/entity.hpp"


class Minimap;
class GameObject;
class EntitiesList{

    private:
        struct Node {
            GameObject* data;
            Node * next;
        };

        
    
    public:

        Node * head;
        void insert(GameObject* item); // add new item
        void remove (GameObject* item); // remove item
        void doFrames(); // update all objects positions etc
        void draw(); // draw everything
        void copy_list(EntitiesList* toCopy);            

        Entity* findEntityAtPos(int x, int y, GameObject* excluded = NULL); // find if there is an entity at desired position
        EntitiesList();
};