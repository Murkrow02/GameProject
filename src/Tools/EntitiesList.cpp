#include "EntitiesList.hpp"
#include "../Engine/gameobject.hpp"
#include <iostream>

EntitiesList::EntitiesList(){
    head = NULL; // init head as null
}

void EntitiesList::insert(GameObject *item){

    // create new list item
    Node *newNode = new Node;
    newNode->data = item;
    newNode->next = head;

    // set new head
    head = newNode;
}

void EntitiesList::remove(GameObject *item){

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
                //delete(current);
            }
            // element is not head, update prev element pointer to next of current
            else{
                prev->next = current->next;
                //delete(current);
            }

            break; // no need to go further
        }

        // next one
        prev = current;
        current = current->next;
    }

}

void EntitiesList::doFrames(){


    Node* current = head;

    // scan through all objects until current item is null
    while(current != NULL){

        // update frame of current object
        current->data->DoFrame();

        // next one
        current = current->next;
    }
}

void EntitiesList::draw(){


    Node* current = head;

    // scan through all objects until current item is null
    while(current != NULL){

        // draw current object
        current->data->Draw();

        // next one
        current = current->next;
    }
}

void EntitiesList::copy_list(EntitiesList* toCopy){

    Node* current = toCopy->head;

    // Assume the list contains at least 1 student.
    head = new Node;
    head->data = current->data;
    head->next = NULL;

    // Keep track of first element of the copy.
    Node* head2 = head;

    // 1st element already copied.
    current = current->next;

    while (current != NULL) {
       // Allocate the next node and advance copy to the element being copied.
       head = head->next = new Node;

       // Copy the node contents; don't share references to students.
       head->data = current->data;

       // No next element (yet).
       head->next = NULL;

       // Advance 'current' to the next element
       current = current->next;
    }

    head = head2;

    // Return pointer to first (not last) element.
}



Entity* EntitiesList::findEntityAtPos(int x, int y, GameObject* excluded){

    Node* current = head;

    // scan through all objects
    while(current != NULL){

        // item is found
        if(current->data->x == x && current->data->y == y && current->data != excluded)
        {
            // check that is entity type
            try{
                Entity *result = (Entity *)current->data;
                return result; // no need to go further
            }
            catch(int e)
            {
                continue; // failed to cast, no entity
            }
            
            break; 
        }

        // next one
        current = current->next;
    }

    // if reached this point then no match occourred
    return NULL;
}