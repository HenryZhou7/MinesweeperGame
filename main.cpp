//
//  main.cpp
//  Minesweeper
//
//  Created by Henry Zhou on 2016-08-04.
//  Copyright © 2016 Henry Zhou. All rights reserved.
//
//
//
//
//  A simplified version of the game minesweeper
//  There is no UI for the fastest implementation
//

#include <iostream>
#include <ctime>
#include <vector>
#include "grid.hpp"

using namespace std;

void print_instruction(){
    cout << "Welcome to Minesweeper!" << endl;
    cout << "To dig, enter the index of the block (row col). " << endl;
    cout << "For example, to dig row 1, col 1, enter: 1 1" << endl;
    cout << "To flag, enter number 0 before enter the index of the block." << endl;
    cout << "For example, to flag row 1 col 1, enter: 0 1 1" << endl;
    cout << "Have Fun~!" << endl;
}

int main(int argc, const char * argv[]) {
    
    srand((unsigned int)time(NULL));
    
    //Initialize the game
    Grid game;
    game.gameStart();
    game.findAllMineCount();
    print_instruction();
    game.print_grid();
    bool win = true;
    
    //The loop, prompting the user for input until 1. Hit a mine 2. No more valid moves
    while(game.win_condition() != true && win){
        
        cout << "Please enter the index of the block you to dig: ";
        
        int first_input;
        cin >> first_input;
        
        //If the first input is a 0, then go into the mode of flagging a block
        if (first_input == 0){
            int x, y;
            cin >> x >> y;
            game.action_flag(x, y, 'a');
        }
        else{   //Otherwise, get the second input and get into the mode of digging
            
            int second_input;
            cin >> second_input;
            game.dig_expand(first_input - 1, second_input - 1);
            win = game.action_dig(first_input, second_input);
        }
        
        //Clear the screen before printing again
        system("clear");
        print_instruction();
        cout << "Here is the current state of the grid:\n\n";
        game.print_grid();
    }
    
    //Gameover status
    if (win){
        cout << "You solved it!" << endl;
        
    }
    else{
        //If the player lose the game, then find all the mines (hidden or not)
        //And re-print the grid
        system("Clear");
        cout << "Boom! Boom! Boom!" << endl;
        cout << "You lose!" << endl;
        game.gameLose();
        game.print_grid();
    }
    
    cout << "Thank you for playing!" << endl;
    return 0;
}
