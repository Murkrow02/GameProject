#pragma once
#include "../Entities/entity.hpp"

class GameObject;

class GameObjectNode{

protected:
    struct Node
    {
        GameObject *data;
        Node *next;
    };

    Node *head; // head is null by default


public:

    Entity* findEntityAtPos(int x, int y, GameObject *excluded);
    void insert(GameObject *item);
    void remove(GameObject *item);
    void reset();

};