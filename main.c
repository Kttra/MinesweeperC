/*  This program sets up the game minesweeper
    for the user to play. The arguments expected
    to be entered are the number of rows, columns,
    mines, and the seed number in this order.

    Created by Kttra
*/

#include <stdio.h>
#include <stdlib.h>
#include "boardCopy.h"
#include "playGame.h"
#include "validInput.h"
#include "winCond.h"

void playGame(Board board, Board cpy);

int main(int argc, char* argv[]){
    Board board;
    Board cpy;

    validArgs(argc, argv);

    board.numRows = atoi(argv[1]);
    board.numCols = atoi(argv[2]);
    board.numMines = atoi(argv[3]);
    board.xMove = 0;
    board.yMove = 0;

    //Get the random seed
    srand(atoi(argv[4]));

    board.theBoard = getBoard(board);
    cpy = boardCpy(board);

    board.mines = createArray(board);
    placeMines(cpy, board);

    calcBoard(cpy);
    printBoard(board);
    //printBoard(cpy); //Print out the copy to compare, debugging reasons

    playGame(board, cpy);

    return 0;
}

//Start the game
void playGame(Board board, Board cpy){

    do{
        board = getMove(board, cpy);
        board.numMines = playMove(board, cpy);
        board.numMines = gameOver(board, cpy);
        printf("There are %d mines left\n", board.numMines);
        printBoard(board);
        board.numMines = gameOver(board, cpy);
    }while(true);
}
