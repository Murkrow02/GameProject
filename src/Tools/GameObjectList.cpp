#include "GameObjectList.hpp"
#include "../Engine/gameobject.hpp"
#include <iostream>

GameObjectList::GameObjectList(){
    head = NULL; // init head as null
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
