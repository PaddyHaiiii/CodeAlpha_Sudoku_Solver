# CodeAlpha Sudoku Solver

A C++ console application that solves a standard 9 x 9 Sudoku puzzle using **recursion and backtracking**.

## Features

- Stores the Sudoku puzzle in a two-dimensional array
- Uses `0` to represent empty cells
- Prints the puzzle in a readable 9 x 9 grid
- Checks whether a candidate number is valid in its row, column, and 3 x 3 box
- Rejects an initial puzzle that already contains conflicting numbers
- Uses recursive backtracking to try possible numbers
- Prints the solved grid or reports that no solution exists

## Requirements

- A C++ compiler that supports C++11 or later
- Terminal or an IDE such as Visual Studio Code

## Compile

```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o sudoku_solver
```

## Run

Linux/macOS:

```bash
./sudoku_solver
```

Windows (MinGW):

```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o sudoku_solver.exe
sudoku_solver.exe
```

## How it works

1. The program loads a sample Sudoku puzzle. Empty cells are represented by `0`.
2. `findEmptyCell()` finds the next empty position.
3. `isSafe()` checks the candidate number against the row, column, and 3 x 3 box.
4. `solve()` tries numbers from 1 to 9 and calls itself recursively.
5. If a choice leads to a dead end, the program resets that cell to `0` and tries another number. This is the **backtracking** step.
6. When no empty cells remain, the puzzle is solved.

## Customizing the puzzle

Edit the 9 rows in the `puzzle` array in `main.cpp`. Use numbers from 1 to 9 for filled cells and `0` for empty cells. The program checks for conflicting starting values before attempting to solve the puzzle.

## Project structure

```text
CodeAlpha_Sudoku_Solver/
├── main.cpp
└── README.md
```

## CodeAlpha task mapping

This project demonstrates a 2D grid, recursive backtracking, and row/column/3 x 3 box validation.

## Author

Add your name, course, and internship details here before publishing.
