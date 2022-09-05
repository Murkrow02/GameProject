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

    // returns (if present) a reference to entity placed at point (x,y)
    Entity* findEntityAtPos(int x, int y, GameObject *excluded);

    // add a new gameobject to list
    void insert(GameObject *item);

    // removes gameobject from list
    void remove(GameObject *item);

    // clears the list
    void reset();

    // returns the total number of enemies in list
    int numberOfEnemies(GameObjectList *gameObjects);

    GameObjectNode();

};