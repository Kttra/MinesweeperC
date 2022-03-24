# MineSweeperC
Minesweeper made in C#. The arguments expected to be entered are the number of rows, columns, mines, and the seed number in this order. After the board is generated, the program will tell the user how many boards are left and what move they would like to do. We receive first the row # and then the col #. After we receive that, we ask if they want to reveal, question, or mark the tile. In addition, they can cancel that move. Afterwards, the program repeats these steps until a mine is hit or until the user wins. The winning conditions are when all the safe tiles have been revealed and when all the mines have been marked.

**Full Game Example**
----------------------------
Below is an example of the program on a 5 by 5 grid.

```
There are 2 mines left
4 # # # # #
3 # # # # #
2 # # # # #
1 # # # # #
0 # # # # #
  0 1 2 3 4
Enter row a row between 0-4 and a column between 0-4: 4 4
Enter Action
0. Reveal
1. Question
2. Mark
3. Cancel
Action: 0

There are 2 mines left
4 # 1 0 0 0
3 # 1 0 0 0
2 # 1 0 0 0
1 # 1 1 0 0
0 # # 1 0 0
  0 1 2 3 4
Enter row a row between 0-4 and a column between 0-4: 0 0
Enter Action
0. Reveal
1. Question
2. Mark
3. Cancel
Action: 1

There are 2 mines left
4 # 1 0 0 0
3 # 1 0 0 0
2 # 1 0 0 0
1 # 1 1 0 0
0 ? # 1 0 0
  0 1 2 3 4
Enter row a row between 0-4 and a column between 0-4: 0 0
Enter Action
0. Reveal
1. Question
2. Mark
3. Cancel
Action: 0

There are 2 mines left
4 # 1 0 0 0
3 # 1 0 0 0
2 # 1 0 0 0
1 # 1 1 0 0
0 1 # 1 0 0
  0 1 2 3 4
Enter row a row between 0-4 and a column between 0-4: 0
1
Enter Action
0. Reveal
1. Question
2. Mark
3. Cancel
Action: 2

There is 1 mine left
4 # 1 0 0 0
3 # 1 0 0 0
2 # 1 0 0 0
1 # 1 1 0 0
0 1 ! 1 0 0
  0 1 2 3 4
Enter row a row between 0-4 and a column between 0-4: 1
0
Enter Action
0. Reveal
1. Question
2. Mark
3. Cancel
Action: 0

There is 1 mine left
4 # 1 0 0 0
3 # 1 0 0 0
2 # 1 0 0 0
1 1 1 1 0 0
0 1 ! 1 0 0
  0 1 2 3 4
Enter row a row between 0-4 and a column between 0-4: 2 0 0
Enter Action
0. Reveal
1. Question
2. Mark
3. Cancel
Action: There is 1 mine left
4 # 1 0 0 0
3 # 1 0 0 0
2 1 1 0 0 0
1 1 1 1 0 0
0 1 ! 1 0 0
  0 1 2 3 4
Enter row a row between 0-4 and a column between 0-4: 4 0 0
Enter Action
0. Reveal
1. Question
2. Mark
3. Cancel

Action: There is 1 mine left
4 1 1 0 0 0
3 # 1 0 0 0
2 1 1 0 0 0
1 1 1 1 0 0
0 1 ! 1 0 0
  0 1 2 3 4
Enter row a row between 0-4 and a column between 0-4: 3 0 2
Enter Action
0. Reveal
1. Question
2. Mark
3. Cancel
Action: 4 1 1 0 0 0
3 * 1 0 0 0
2 1 1 0 0 0
1 1 1 1 0 0
0 1 * 1 0 0
  0 1 2 3 4
You Won!!
```
**Setting Arguments/Parameters**
----------------------------
For those unfamiliar with arguments, you can either set parameters through cmd by opening cmd in the directory of the exe file or through codeblocks if you are running it through the source code. For example, for the .exe file, the command through the command prompt to generate a 5x5 board with 2 mines and a seed of 2 would be:
```
minesweeper.exe 5 5 2 2
```
