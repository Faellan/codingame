#pragma once //<ck:del>


#include "../../../config/game_constants.h"

#define is_inside_grid(x,y) (x>=0 && y>= 0 && x<GRID_WIDTH && y<GRID_HEIGHT)


template<typename PlayerDecisionType, int nb_players>
class GridWorld {
public:
    GridWorld(){};

};


