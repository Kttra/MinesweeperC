#ifndef VALIDINPUT_H
	#define VALIDINPUT_H

    #include <stdbool.h>
    #include "boardCopy.h"

    bool validMove(Board board, Board cpy);
    void validArgs(int argc, char* argv[]);

#endif
