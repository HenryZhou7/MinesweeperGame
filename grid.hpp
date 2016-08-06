//
//  grid.hpp
//  Minesweeper
//
//  Created by Henry Zhou on 2016-08-04.
//  Copyright © 2016 Henry Zhou. All rights reserved.
//


/*
 * This is the class for the grid
 * It has the data memeber which is a 2D vector of blocks
 * Aside from that all of which are methods for manipulation 
 * on the grid throughout the game
 *
 */


#ifndef grid_hpp
#define grid_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "block.hpp"

using namespace std;

class Grid{

private:
    vector< vector<Block> > gameSpace;

public:
    Grid();
    
    //In-Game actions' function
    void print_grid();
    bool action_dig(int, int);          //User digs on the indexed block
    void dig_expand(int, int);          //When the block has no mine around it
    void action_flag(int, int, int);     //User flags on the block
    
    
    //Important game status
    bool win_condition();
    void gameStart();
    void findAllMineCount();
    void gameLose();
    
};

#endif /* grid_hpp */
