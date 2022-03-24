#include <stdlib.h>
#include <stdio.h>
#include "boardCopy.h"
#include "playGame.h"
#include "validInput.h"

//Asks the user what move they would like to make
int playMove(Board board, Board cpy){
    int move;

    printf("Enter Action\n0. Reveal\n1. Question\n2. Mark\n3. Cancel\n");
    printf("Action: ");
    scanf(" %d", &move);

    switch(move) {
        case 0: //Reveals the tile
            revealTile(board, cpy, board.yMove + 1, board.xMove + 1);
            return board.numMines;
            break;
        case 1: //User sets tile as possible mine
            board.theBoard[board.yMove][board.xMove] = '?';
            return board.numMines;
            break;
        case 2: //User marks tile as mine
            board.theBoard[board.yMove][board.xMove] = '!';
            return board.numMines - 1;
            break;
        case 3: //User canceled their move
            board = getMove(board, cpy);
            return playMove(board, cpy);
            break;
        default:
            board = getMove(board, cpy);
            return playMove(board, cpy);
            break;
    }
}

void revealTile(Board board, Board cpy, int row, int col){
/*  Analyzes the 8 tiles around the selected tile where the tile is 0
    7   4   8
    5   0   6
    1   2   3
*/

    switch(cpy.theBoard[row][col]){
        case '*':
            hitMine(cpy);
        case '1':
            board.theBoard[row - 1][col - 1] = '1';
            break;
        case '2':
            board.theBoard[row - 1][col - 1] = '2';
            break;
        case '3':
            board.theBoard[row - 1][col - 1] = '3';
            break;
        case '0':
            board.theBoard[row - 1][col - 1] = '0';    //Set tile to 0

            revealTiles(board, cpy, row - 1, col - 1); //Checks tile 1
            revealTiles(board, cpy, row - 1, col);     //Checks tile 2
            revealTiles(board, cpy, row - 1, col + 1); //Checks tile 3
            revealTiles(board, cpy, row + 1, col);     //Checks tile 4

            revealTiles(board, cpy, row, col - 1);     //Checks tile 5
            revealTiles(board, cpy, row, col + 1);     //Checks tile 6
            revealTiles(board, cpy, row + 1, col - 1); //Checks tile 7
            revealTiles(board, cpy, row + 1, col + 1); //Checks tile 8
            break;
    }
}

void revealTiles(Board board, Board cpy, int row, int col){
    //printf("Row:%d\nCol:%d\n", row, col);

    if (row < 1 || row > board.numRows){
        return;
    }
    if (col < 1 || col > board.numCols){
        return;
    }
    //If the tile is revealed/flagged/
    if(board.theBoard[row - 1][col - 1] != '#'){
        return;
    }
    else if (cpy.theBoard[row][col] == '#'){
       return;
    }

    else if(cpy.theBoard[row][col] == '*'){
        return;
    }
    else if(cpy.theBoard[row][col] == '1'){
        board.theBoard[row - 1][col - 1] = '1';
    }
    else if(cpy.theBoard[row][col] == '2'){
        board.theBoard[row - 1][col - 1] = '2';
    }
    else if(cpy.theBoard[row][col] == '3'){
        board.theBoard[row - 1][col - 1] = '3';
    }
    else if(cpy.theBoard[row][col] == '0'){
        board.theBoard[row - 1][col - 1] = '0';
        revealTile(board, cpy, row, col);
    }
    else{
        return;
    }

}

/*
Board checkSides(Board board, Board cpy){
    //Board boardCpy = board;

    if(cpy.theBoard[board.yMove + 1][board.xMove] != '#' && cpy.theBoard[board.yMove + 1][board.xMove] != '*'){
        //board.theBoard[board.yMove][board.xMove - 1] = '1';
        //boardCpy.xMove = board.xMove - 1;
        board.xMove = board.xMove - 1;
        revealTile(board, cpy);
        //revealTile over here instead?
        //return boardCpy;
    }
    if(cpy.theBoard[board.yMove][board.xMove] != '#' && cpy.theBoard[board.yMove][board.xMove] != '*'){
        board.xMove = board.xMove - 1;
        board.yMove = board.yMove - 1;
        revealTile(board, cpy);
    }
    if(cpy.theBoard[board.yMove][board.xMove + 1] != '#' && cpy.theBoard[board.yMove][board.xMove + 1] != '*'){
        board.yMove = board.yMove - 1;
        revealTile(board, cpy);
    }
    if(cpy.theBoard[board.yMove][board.xMove + 2] != '#' && cpy.theBoard[board.yMove][board.xMove + 2] != '*'){
        board.xMove = board.xMove + 1;
        board.yMove = board.yMove - 1;
        revealTile(board, cpy);
    }
    if(cpy.theBoard[board.yMove + 1][board.xMove + 2] != '#' && cpy.theBoard[board.yMove + 1][board.xMove + 2] != '*'){
        board.xMove = board.xMove + 1;
        revealTile(board, cpy);
    }


    //else if()

}
*/

Board getMove(Board board, Board cpy){
    int x, y;
    Board boardCpy = board;

    do{
        printf("Enter row a row between 0-%d and a column between 0-%d: ", board.numRows - 1, board.numCols - 1);
        scanf("%d %d", &y, &x);
        board.xMove = x;
        board.yMove = y;
    }while(!validMove(board, cpy));

        boardCpy.xMove = board.xMove;
        boardCpy.yMove = board.yMove;

    return boardCpy;
}

void placeMines(Board cpy, Board board){
    int xCoord;// = rand()% board.numRows;
    int yCoord;// = rand()% board.numCols;
    int i;

    //printf("xCoord: %d\n", xCoord);
    //printf("yCoord: %d\n", yCoord);

    for(i = 0; i < cpy.numMines; i++){
        xCoord = rand() % board.numRows;
        yCoord = rand() % board.numCols;

        //Repeats the assigning of the mines if there is already a mine there
        if(cpy.theBoard[xCoord + 1][yCoord + 1] == '#'){
            cpy.theBoard[xCoord + 1][yCoord + 1] = '*';
            board.mines[i][0] = xCoord;
            board.mines[i][1] = yCoord;
            //printf("Placing mine at %d, %d\n", xCoord, yCoord); //Tells us where the mines are placed at the start for debugging reasons
        }
        else{
            i--;
        }
    }

    //Outputs the number of mines left on the board that haven't been identified
    if(board.numMines == 1){
        printf("There is %d mine left\n", board.numMines);
    }
    else{
        printf("There are %d mines left\n", board.numMines);
    }
}

int unmark(Board board, Board cpy, bool unMark){
    int move;

    board = getMove(board, cpy);

    if(unMark){
        printf("Enter Action\n0. UnMark\n1. Cancel\n");
        board.numMines = board.numMines + 1;
        //printf("Testing: %d\n", board.numMines);
    }
    else if(!unMark){
        printf("Enter Action\n0. UnQuestion\n1. Cancel\n");
    }

    printf("Action: ");
    scanf(" %d", &move);
    //printf("\n"); //If you want a gap between the moves

    if(move == 0){
        board.theBoard[board.yMove][board.xMove] = '#';
        //printBoard(board);
    }

    return board.numMines;
}

//If user hits a mine, they lose
void hitMine(Board cpy){
    printResult(cpy);
    printf("You Lost :(");
    exit(0);
}

void calcBoard(Board cpy){
    int i, j, numMines;

    for(i = 1; i < cpy.numRows - 1; i++){
        for(j = 1; j < cpy.numCols - 1; j++){
            numMines = 0;

            //If the location is a mine, it goes and checks the next point
            if(cpy.theBoard[i][j] == '*'){
                continue;
            }

            //Counts the number of mines surrounding the point on the board
            if(cpy.theBoard[i][j - 1] == '*'){
                numMines++;
            }
            if(cpy.theBoard[i - 1][j - 1] == '*'){
                numMines++;
            }
            if(cpy.theBoard[i - 1][j] == '*'){
                numMines++;
            }
            if(cpy.theBoard[i - 1][j + 1] == '*'){
                numMines++;
            }
            if(cpy.theBoard[i][j + 1] == '*'){
                numMines++;
            }
            if(cpy.theBoard[i + 1][j + 1] == '*'){
                numMines++;
            }
            if(cpy.theBoard[i + 1][j] == '*'){
                numMines++;
            }
            if(cpy.theBoard[i + 1][j - 1] == '*'){
                numMines++;
            }

            //Places the number of mines around the location to that point
            cpy.theBoard[i][j] = numMines + '0';

        }
    }
}
