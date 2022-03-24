#include <stdio.h>
#include <stdlib.h>
#include "boardCopy.h"
#include "playGame.h"

//Checks if the game is over
int gameOver(Board board, Board cpy){
    int i, j;
    int count = 0;
    int mineCount = 0, posMines = 0;
    int total = 0;

    for(i = 0; i < board.numRows; i++){
        for(j = 0; j < board.numCols; j++){
            if(board.theBoard[i][j] == '#'){
                count++;
            }
            else if(board.theBoard[i][j] == '!'){
                mineCount++;
            }
            else if(board.theBoard[i][j] == '?'){
                posMines++;
            }
        }
    }

    total = count + mineCount + posMines;

    if(total == cpy.numMines){
        if(mineCount == cpy.numMines){
            printResult(cpy);
            printf("You Won!!");
            exit(0);
        }
    }
    bool unMark;
    if(count == 0 && mineCount > cpy.numMines){
        //UnMark/Cancel
        //printBoard(board);
        //printf("Enter Action\n0. UnMark\n1. Cancel\n");
        unMark = true;
        board.numMines = unmark(board, cpy, unMark);
    }
    else if(count == 0){
        //printf("Enter Action\n0. UnQuestion\n1. Cancel\n");
        unMark = false;
        board. numMines = unmark(board, cpy, unMark);
    }

    return board.numMines;
    //Ends program return true;
}
