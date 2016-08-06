//
//  grid.cpp
//  Minesweeper
//
//  Created by Henry Zhou on 2016-08-04.
//  Copyright © 2016 Henry Zhou. All rights reserved.
//

#include "grid.hpp"



/*
 * Constructor for the class
 */
Grid::Grid(){
    for (int i = 0; i < 9; i++){
        vector<Block> temp_array;
        for (int j = 0; j < 9; j++){
            Block temp_block;
            temp_array.push_back(temp_block);
        }
        gameSpace.push_back(temp_array);
    }
}



/*
 * Print the grid, along with the index for the ease of reading
 */
void Grid::print_grid(){
    
    for (int i = 0; i < 10; i++)
        cout << i;
    cout << endl;
    
    for (int i = 1; i <= 9; i++){
        cout << i;
        for (int j = 0; j < gameSpace[i - 1].size(); j++)
            gameSpace[i - 1][j].printBlock();
        cout << endl;
    }
}



/*
 * Everytime finish digging a mine-free block
 * Check to see if all the empty blocks have been dug up
 * Returns true if the player wins
 *         false otherwise
 */
bool Grid::win_condition(){
    
    //For each block if it is empty and it is either digged or flagged
    bool win = true;
    
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            Block temp = gameSpace[i][j];
            if (temp.testMine() == false){      //The block is empty
                if (temp.haveDug() == false)
                    win = false;
            }
        }
    }
    
    return win;
}



/*
 * Initialize the game by setting 11 mines in the grid randomly
 * There might be mines exist in the same block, but I don't 
 * think it will affect the overall gaming experience
 * The number of mines affect the difficult level
 */
void Grid::gameStart(){
    for (int i = 0; i < 12; i++){
        int randomA = rand() % 9;
        int randomB = rand() % 9;
        gameSpace[randomA][randomB].setMine();
    }
}



/*
 * The user enter the index of the block where it will dig
 * gameSpace[x - 1][y - 1] (because 0-indexed / 1-indexed)
 * Return false if there is a mine
 *        true otherwise
 */
bool Grid::action_dig(int x, int y){
    if (x < 0 || x > 8 || y < 0 || y > 8)           //The input is out of bound
        return false;
    Block* digging_block = &gameSpace[x - 1][y - 1];
    if (digging_block->testMine() == true)
        return false;
    else{
        digging_block->dig();
        return true;
    }
}



/*
 * Expand on the digging area if there is no mine around the
 * block
 * Expand on the block gameSpace[x][y] in 8 directions
 */
void Grid::dig_expand(int x, int y){
    if (!(x >= 0 && x <= 8 && y >= 0 && y <= 8))                        //Out of bounds
        return;
    //gameSpace[x][y].dig();
    if (gameSpace[x][y].testMine() || gameSpace[x][y].haveDug())        //Terminate condition. Dugged before / It is a mine
        return;
    if (gameSpace[x][y].getMineCount() != 0){                           //Find the boundaries
        gameSpace[x][y].dig();
        return;
    }
    else{
        gameSpace[x][y].dig();
        dig_expand(x - 1, y - 1);           //upper left
        dig_expand(x, y - 1);               //left
        dig_expand(x + 1, y - 1);           //lower left
        dig_expand(x - 1, y);               //up
        dig_expand(x + 1, y);               //low
        dig_expand(x - 1, y + 1);           //upper right
        dig_expand(x, y + 1);               //right
        dig_expand(x + 1, y + 1);           //lower right
    }
}



/*
 * The user enter the index of the block where it will flag
 * gameSpace[x - 1][y - 1]
 * The last parameter is a dummy variable for prompting the 
 * information
 */
void Grid::action_flag(int x, int y, int dummy){
    Block* flag_block = &gameSpace[x - 1][y - 1];
    flag_block->suspectMine();
}



/*
 * The situation when hit a mine.
 * Traverse all the blocks and change the ones with the mine
 * to be digged up
 * The losing situation is determined by the action_dig() func
 */
void Grid::gameLose(){
    
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            Block* temp_block = &gameSpace[i][j];
            if (temp_block->testMine())
                temp_block->dig();
        }
    }
    
}



/*
 * After setting all the mines at the start of the game
 * Run this function to find how many blocks with mines are around
 * it
 */
void Grid::findAllMineCount(){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            //For each direction, accumulate on the counter
            int count = 0;
            
            //Find the total count
            if (i >= 1 && j >= 1)
                if (gameSpace[i - 1][j - 1].testMine())
                    count++;
            if (j >= 1)
                if (gameSpace[i][j - 1].testMine())
                    count++;
            if (i <= 7 && j >= 1)
                if (gameSpace[i + 1][j - 1].testMine())
                    count++;
            if (i <= 7)
                if (gameSpace[i + 1][j].testMine())
                    count++;
            if (i <= 7 && j <= 7)
                if (gameSpace[i + 1][j + 1].testMine())
                    count++;
            if (j <= 7)
                if (gameSpace[i][j + 1].testMine())
                    count++;
            if (i >= 1 && j <= 7)
                if (gameSpace[i - 1][j + 1].testMine())
                    count++;
            if (i >= 1)
                if (gameSpace[i - 1][j].testMine())
                    count++;
            
            //Assign the count to its value
            gameSpace[i][j].setMineNum(count);
            
        }
    }
}











