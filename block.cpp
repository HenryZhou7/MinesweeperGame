//
//  block.cpp
//  Minesweeper
//
//  Created by Henry Zhou on 2016-08-04.
//  Copyright © 2016 Henry Zhou. All rights reserved.
//

#include "block.hpp"

Block::Block(){
    isMine = false;
    mineCount = 0;
    digged = false;
    setFlag = false;
}



/*
 * Print the block based on the state of the game
 */
void Block::printBlock(){
    
    if (setFlag == true && digged == false)
        cout << "x";
    
    if (digged == true){
        do{
            if (isMine == true){//There is a mine
                cout << "O";
            }
            else{
                if (mineCount == 0)
                    cout << "." ;
                else
                    cout << mineCount;
            }
            
        }while(false);
    }
    if (digged == false){       //Haven't digged, remain blank
        cout << " ";
    }
    
}