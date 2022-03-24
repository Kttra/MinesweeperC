#ifndef BOARDCOPY_H
	#define BOARDCOPY_H

    #include <stdbool.h>

    typedef struct Board_Struct{
        char** theBoard;
        int numRows;
        int numCols;
        int numMines;
        int** mines;
        int xMove;
        int yMove;
    }Board;

    int** createArray(Board board);
    char** getBoard(Board orig);
    void printBoard(Board board);
    bool setSpot(Board* board, int row, int col, char value);
    void printResult(Board cpy);
    Board boardCpy(Board orig);

#endif
