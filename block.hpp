//
//  block.hpp
//  Minesweeper
//
//  Created by Henry Zhou on 2016-08-04.
//  Copyright © 2016 Henry Zhou. All rights reserved.
//

/*
 * The class for the block for the grid
 * Each block has the property which is consistent throughout the game
 *                          If there is a mine in the block
 *                          How many mines are around the block
 *                the status that keeps updating through game-playing
 *                          Was the block dugged before
 *                          Was the block flagged before
 *
 */


#ifndef block_hpp
#define block_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Block{
    
private:
    
    //Basic property generated at the start of the game
    bool isMine;
    int mineCount;
    
    //Properties that needs to be modified during the game
    bool digged;
    bool setFlag;
    
public:
    Block();
    
    //Functions used to set the initial state
    void setMine() {isMine = true;}
    void setMineNum(int _num) {mineCount = _num;}
    
    //Functions needed while playing
    int getMineCount() {return mineCount;}          //Return mineCount
    bool testMine() {return isMine;}                //Return if there is a mine
    bool haveDug() {return digged;}                 //Return if it has been dug
    bool flagged() {return setFlag;}                //Return if it has been flagged
    void dig() {digged = true; setFlag = false;}
    void suspectMine() {setFlag = true;}
    
    void printBlock();
    
    
};

#endif /* block_hpp */
