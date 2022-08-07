#include "list.hpp"
#include "../Engine/gameobject.cpp"
#include <iostream>

GameObjectList::GameObjectList(){
    head = NULL; // init head as null
}

void GameObjectList::insert(GameObject *item){

    // create new list item
    Node *newNode = new Node;
    newNode->data = item;
    newNode->next = head;

    // set new head
    head = newNode;
}

void GameObjectList::remove(GameObject *item){

    Node* current = head;
    Node* prev = NULL;

    // scan through all objects until item is found
    while(current != NULL){

        // item is found
        if(current->data == item)
        {
            // element is head, need to update new pointer
            if(current == head)
            {
                head = current->next;
                delete(current);
            }
            // element is not head, update prev element pointer to next of current
            else{
                prev->next = current->next;
                delete(current);
            }

            break; // no need to go further
        }

        // next one
        prev = current;
        current = current->next;
    }

}

void GameObjectList::doFrames(){

    //player first
    player->DoFrame();

    Node* current = head;

    // scan through all objects until current item is null
    while(current != NULL){

        // update frame of current object
        current->data->DoFrame();

        // next one
        current = current->next;
    }
}

void GameObjectList::draw(){

    //player first
    player->Draw();

    Node* current = head;

    // scan through all objects until current item is null
    while(current != NULL){

        // draw current object
        current->data->Draw();

        // next one
        current = current->next;
    }
}