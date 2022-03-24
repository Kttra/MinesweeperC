#include <stdlib.h>
#include <stdio.h>
#include "boardCopy.h"

//Generate the background board
char** getBoard(Board orig){
	char** board;
	int i, j;

	//cpy.theBoard = orig.theBoard;
	board = (char**) malloc(orig.numRows * sizeof(char*));

	for(i = 0; i < orig.numRows; ++i){
		board[i] = (char*) malloc(orig.numCols * sizeof(char));
		for(j = 0; j < orig.numCols; ++j){
			board[i][j] = '#';
		}
	}

	return board;
}

int** createArray(Board board){
    int** array;
    int i;

    array = (int**) malloc(board.numMines * sizeof(int*));

    for(i = 0; i < board.numMines; ++i){
		array[i] = (int*) malloc(2 * sizeof(int));
	}

    return array;
}

//Prints the board
void printBoard(Board board){
	int i, j;

	for(i = board.numRows - 1; i >= 0; i--){
        printf("%d ", i);
		for(j = 0; j < board.numCols; ++j){
			printf("%c ", board.theBoard[i][j]);
		}
		printf("\n");
	}

	printf("  ");
	for(j = 0; j < board.numCols; ++j){
        printf("%d ", j);
	}

	printf("\n");
}

//Prints the full board
void printResult(Board cpy){
	int i, j;

	for(i = cpy.numRows - 2; i >= 1; i--){
        printf("%d ", i - 1);
		for(j = 1; j < cpy.numCols - 1; ++j){
			printf("%c ", cpy.theBoard[i][j]);
		}
		printf("\n");
	}

	printf("  ");
	for(j = 0; j < cpy.numCols - 2; ++j){
        printf("%d ", j);
	}

	printf("\n");
}

//Copies the board (this is the board we'll output to the user)
Board boardCpy(Board orig){
	Board cpy;
	int i, j;

	cpy.numRows = (orig.numRows) + 2;
	cpy.numCols = (orig.numCols) + 2;
	cpy.numMines = orig.numMines;
	//cpy.theBoard = orig.theBoard;
	cpy.theBoard = (char**)malloc(cpy.numRows *sizeof(char*));

	for(i = 0; i < cpy.numRows; ++i){
		cpy.theBoard[i] = (char*)malloc(cpy.numCols *sizeof(char));
		for(j = 0; j < cpy.numCols; ++j){
			cpy.theBoard[i][j] = '#';
		}
	}

	return cpy;
}
