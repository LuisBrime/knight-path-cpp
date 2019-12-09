//
//  Knight.cpp
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

#include "Knight.hpp"

void printBoard(int* board, int size) {
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

Knight::Knight() {
}

Knight::~Knight() {
}

void Knight::startTour(int initialRow, int initialCol, int *board, int size) {
    int row = initialRow;
    int col = initialCol;
    int i = 1;
    
    while (i <= size * size) {
        board[(row * size) + col] = i;
        
        int* pM = checkMoves(row, col, board, size);
        int min = size + 1;
        int minP = row * size + col;
        for (int j = 0; j < 8; j++) {
            if (pM[j] != -1) {
                int count = countMoves((int) pM[j] / size, pM[j] % size, board, size);
                if (count < min) {
                    min = count;
                    minP = pM[j];
                }
            }
        }
        
        row = (int) minP / size;
        col = minP % size;
        i++;
    }
    
    printBoard(board, size);
}

int* Knight::checkMoves(int row, int col, int* board, int size) {
    int* moves = new int[8];
    
    // 1
    if (board[(row-1)*size + (col+2)] == 0 && row - 1 >= 0 && col + 2 < size) {
        moves[0] = ((row-1) * size) + (col + 2);
    } else {
        moves[0] = -1;
    }
    
    // 2
    if (board[(row-2)*size + (col+1)] == 0 && row - 2 >= 0 && col + 1 < size) {
        moves[1] = ((row-2) * size) + (col + 1);
    } else {
        moves[1] = -1;
    }
    
    // 3
    if (board[(row-2)*size + (col-1)] == 0 && row - 2 >= 0 && col - 1 >= 0) {
        moves[2] = ((row-2) * size) + (col - 1);
    } else {
        moves[2] = -1;
    }
    
    // 4
    if (board[(row-1)*size + (col-2)] == 0 && row - 1 >= 0 && col - 2 >= 0) {
        moves[3] = ((row-1) * size) + (col - 2);
    } else {
        moves[3] = -1;
    }
    
    // 5
    if (board[(row+1)*size + (col-2)] == 0 && row + 1 < size && col - 2 >= 0) {
        moves[4] = ((row+1) * size) + (col - 2);
    } else {
        moves[4] = -1;
    }

    // 6
    if (board[(row+2)*size + (col-1)] == 0 && row + 2 < size && col - 1 >= 0) {
        moves[5] = ((row+2) * size) + (col - 1);
    } else {
        moves[5] = -1;
    }
    
    // 7
    if (board[(row+2)*size + (col+1)] == 0 && row + 2 < size && col + 1 < size) {
        moves[6] = ((row+2) * size) + (col + 1);
    } else {
        moves[6] = -1;
    }
    
    // 8
    if (board[(row+1)*size + (col+2)] == 0 && row + 1 < size && col + 2 < size) {
        moves[7] = ((row+1) * size) + (col + 2);
    } else {
        moves[7] = -1;
    }
    
    return moves;
}

// board[x*n + y]
int Knight::countMoves(int row, int col, int* board, int size) {
    int count = 0;
    
    // 1
    if (board[(row-1)*size + (col+2)] == 0 && row - 1 >= 0 && col + 2 < size) {
        count++;
    }
    
    // 2
    if (board[(row-2)*size + (col+1)] == 0 && row - 2 >= 0 && col + 1 < size) {
        count++;
    }
    
    // 3
    if (board[(row-2)*size + (col-1)] == 0 && row - 2 >= 0 && col - 1 >= 0) {
        count++;
    }
    
    // 4
    if (board[(row-1)*size + (col-2)] == 0 && row - 1 >= 0 && col - 2 >= 0) {
        count++;
    }
    
    // 5
    if (board[(row+1)*size + (col-2)] == 0 && row + 1 < size && col - 2 >= 0) {
        count++;
    }
    
    // 6
    if (board[(row+2)*size + (col-1)] == 0 && row + 2 < size && col - 1 >= 0) {
        count++;
    }
    
    // 7
    if (board[(row+2)*size + (col+1)] == 0 && row + 2 < size && col + 1 < size) {
        count++;
    }
    
    // 8
    if (board[(row+1)*size + (col+2)] == 0 && row + 1 < size && col + 2 < size) {
        count++;
    }
    
    return count;
}
