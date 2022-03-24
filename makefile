mine_sweeper.out: boardCopy.o main.o playGame.o validInput.o winCond.o
	gcc -g -Wall -Werror -o mine_sweeper.out boardCopy.o main.o playGame.o validInput.o winCond.o

main.o: main.c boardCopy.h winCond.h
	gcc -g -Wall -Werror -c -o main.o main.c

boardCopy.o: boardCopy.c boardCopy.h
	gcc -g -Wall -Werror -c -o boardCopy.o boardCopy.c

playGame.o: playGame.c playGame.h boardCopy.h validInput.h
	gcc -g -Wall -Werror -c -o playGame.o playGame.c

validInput.o: validInput.c validInput.h boardCopy.h
	gcc -g -Wall -Werror -c -o validInput.o validInput.c

winCond.o: winCond.c winCond.h boardCopy.h playGame.h
	gcc -g -Wall -Werror -c -o winCond.o winCond.c

clean:
	rm -f *.out *.o
