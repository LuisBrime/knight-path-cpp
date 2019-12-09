//
//  Knight.hpp
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


#include <stdio.h>
#include <list>
using namespace std;

class Knight {
public:
    
    Knight();
    ~Knight();
    
    void startTour(int initialRow, int initialCol, int* board, int size);
    int* checkMoves(int row, int col, int* board, int size);
    int countMoves(int row, int col, int* board, int size);
};
