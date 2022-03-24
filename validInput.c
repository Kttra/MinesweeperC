#include <stdio.h>
#include <stdlib.h>
#include "validInput.h"
#include "boardCopy.h"

//Checks to see if the user's selection can be made
bool validMove(Board board, Board cpy){

    if(board.yMove > board.numRows - 1){
        return false;
    }
    else if(board.xMove > board.numCols - 1){
        return false;
    }
    else if(board.xMove < 0 || board.yMove < 0){
        return false;
    }
    else if(board.theBoard[board.yMove][board.xMove] == '?'){
        return true;
    }
    else if(board.theBoard[board.yMove][board.xMove] == '!'){
        return true;
    }
    else if(board.theBoard[board.yMove][board.xMove] == '#'){
        return true;
    }
    else{
        printf("This tile is already revealed.\n");
        return false;
    }

    return true;
}


//Checks to see if we have received the right number of arguments from the user
void validArgs(int argc, char* argv[]){
    if(argc <= 3){
        printf("Not enough arguments. Usage: \n");
        printf("./mine_sweeper.out num_rows num_cols num_mines [seed])");
        exit(0);
    }

    else if(argc > 5){
        printf("Too many arguments. Usage: \n");
        printf("./mine_sweeper.out num_rows num_cols num_mines [seed])");
        exit(0);
    }
}
