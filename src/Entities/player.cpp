#include "entity.hpp"
#include "player.hpp"

Entity* create_player(Position start_pos)
{
  Entity* newPlayer;

  newPlayer->pos.y = start_pos.y;
  newPlayer->pos.x = start_pos.x;
  newPlayer->ch = '@';

  return newPlayer;
}

void move_player(int input, Entity* player)
{
  switch(input)
  {
    //move up
    case 'w':
      player->pos.y--;
      break;
    //move down
    case 's':
      player->pos.y++;
      break;
    //move left
    case 'a':
      player->pos.x--;
      break;
    //move right
    case 'd':
      player->pos.x++;
      break;
    default:
      break;
  }
}