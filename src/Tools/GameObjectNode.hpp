#pragma once
#include "../Entities/entity.hpp"

class GameObject;
struct Node
{
    GameObject *data;
    Node *next;
};
class GameObjectNode{   

public:
    Node *head; // head is null by default

    Entity* findEntityAtPos(int x, int y, GameObject *excluded);
    void insert(GameObject *item);
    void remove(GameObject *item);
    void reset();
    GameObjectNode();

};