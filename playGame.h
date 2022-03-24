#ifndef PLAYGAME_H
	#define PLAYGAME_H

    #include <stdbool.h>
    #include "boardCopy.h"

    Board getMove(Board board, Board cpy);
    int playMove(Board board, Board cpy);
    void revealTiles(Board board, Board cpy, int row, int col);
    void revealTile(Board board, Board cpy, int row, int col);
    void placeMines(Board cpy, Board board);
    void calcBoard(Board cpy);
    void hitMine(Board cpy);
    int unmark(Board board, Board cpy, bool unMark);

#endif
