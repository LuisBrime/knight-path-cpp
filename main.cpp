
//  main.cpp
//  KnightPath
//
//  Created by Luis Eduardo Brime Gomez on 8/29/19.
//  Copyright © 2019 Luis Eduardo Brime Gomez. All rights reserved.
//

// Luis Eduardo Brime Gómez A01334886

/*
 
 Problem:
 Knight's tour is a problem that given a NxN chess board and a knight piece somewhere on the board,
 the knight should visit each and every square of the board only once.
 
 */

/*
 
 Environment:
 - Fully observable: The whole environment (the chess board) is known by the agent at all times.
 - Deterministic: The next move of the piece and the state of the problem depends fully on the last state
 and the last action made by the piece.
 - Sequential: The decision and movement made by the pice affects all future decisions.
 - Static: The chess board does not change.
 - Discrete: Time is measured by the moves that the piece makes.
 - Known: The outcomes for all movements are given.
 
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Knight.hpp"

void printB(int* board, int size) {
    int actualRow = 0;
    for (int i = 0; i < size*size; i++) {
        if ((int) i / size != actualRow) {
            printf("\n");
            actualRow = (int) i / size;
        }
        printf("%d\t", board[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Knight* knightPath = new Knight();
    
    int size = 8;
    int* board = new int[size*size];
    for (int i = 0; i < size*size; i++) {
        board[i] = 0;
    }
    
    srand((int)time(0));
    int row = rand() % 8;
    int col = rand() % 8;
    
    printf("row %d col %d\n", row, col);
    
    knightPath->startTour(row, col, board, size);
    
    return 0;
}
