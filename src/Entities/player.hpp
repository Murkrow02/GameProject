#ifndef PLAYER_H
#define PLAYER_H

#include "entity.hpp"

//Returns the player entity placed at desired position
Entity* create_player(Position start_pos);

//Move player to new position based ok key press
void move_player(int input, Entity* player);

#endif