# MineSweeperC
Minesweeper made in C#.

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
