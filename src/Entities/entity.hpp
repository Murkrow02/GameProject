#ifndef ENTITY_H
#define ENTITY_H

#include <ncurses.h>
#include <stdlib.h>

typedef struct
{
  int y;
  int x;
} Position;

typedef struct
{
  Position pos; //determined by x,y
  char ch; //the character identifying the entity
} Entity;

#endif