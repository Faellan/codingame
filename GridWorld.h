#pragma once //<ck:del>

#include "World.h"

#include "game_constants.h"

#define is_inside_grid(x,y) (x>=0 && y>= 0 && x<GRID_WIDTH && y<GRID_HEIGHT)

class GridWorld : World {
public:
    GridWorld();

};


