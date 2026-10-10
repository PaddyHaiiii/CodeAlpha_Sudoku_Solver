#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

const int SIZE = 9;
const int BOX_SIZE = 3;

class SudokuSolver {
private:
    int grid[SIZE][SIZE];

    bool isSafe(int row, int col, int number) const {
        // Check the row.
        for (int c = 0; c < SIZE; ++c) {
            if (grid[row][c] == number)
                return false;
        }

        // Check the column.
        for (int r = 0; r < SIZE; ++r) {
            if (grid[r][col] == number)
                return false;
        }

        // Check the 3 x 3 box.
        int boxStartRow = row - row % BOX_SIZE;
        int boxStartCol = col - col % BOX_SIZE;

        for (int r = boxStartRow; r < boxStartRow + BOX_SIZE; ++r) {
            for (int c = boxStartCol; c < boxStartCol + BOX_SIZE; ++c) {
                if (grid[r][c] == number)
                    return false;
            }
        }

        return true;
    }

    bool findEmptyCell(int& row, int& col) const {
        for (row = 0; row < SIZE; ++row) {
            for (col = 0; col < SIZE; ++col) {
                if (grid[row][col] == 0)
                    return true;
            }
        }
        return false;
    }

public:
    SudokuSolver() {
        for (int r = 0; r < SIZE; ++r) {
            for (int c = 0; c < SIZE; ++c)
                grid[r][c] = 0;
        }
    }

    bool setPuzzle(const int puzzle[SIZE][SIZE]) {
        // Copy the puzzle into the working grid.
        for (int r = 0; r < SIZE; ++r) {
            for (int c = 0; c < SIZE; ++c) {
                if (puzzle[r][c] < 0 || puzzle[r][c] > 9)
                    return false;
                grid[r][c] = puzzle[r][c];
            }
        }

        // Reject a puzzle that already breaks Sudoku rules.
        for (int r = 0; r < SIZE; ++r) {
            for (int c = 0; c < SIZE; ++c) {
                int number = grid[r][c];
                if (number == 0)
                    continue;

                grid[r][c] = 0;
                bool valid = isSafe(r, c, number);
                grid[r][c] = number;

                if (!valid)
                    return false;
            }
        }

        return true;
    }

    void printGrid() const {
        cout << "\n+-------+-------+-------+\n";

        for (int r = 0; r < SIZE; ++r) {
            cout << "| ";
            for (int c = 0; c < SIZE; ++c) {
                if (grid[r][c] == 0)
                    cout << ". ";
                else
                    cout << grid[r][c] << ' ';

                if ((c + 1) % BOX_SIZE == 0)
                    cout << "| ";
            }

            cout << '\n';

            if ((r + 1) % BOX_SIZE == 0)
                cout << "+-------+-------+-------+\n";
        }
    }

    bool solve() {
        int row, col;

        // If no empty cell remains, the puzzle is solved.
        if (!findEmptyCell(row, col))
            return true;

        // Try numbers 1 through 9 in the empty cell.
        for (int number = 1; number <= 9; ++number) {
            if (isSafe(row, col, number)) {
                grid[row][col] = number;

                // Recursively solve the remaining puzzle.
                if (solve())
                    return true;

                // Backtrack when this choice leads to no solution.
                grid[row][col] = 0;
            }
        }

        return false;
    }
};

int main() {
    // Zero represents an empty cell.
    const int puzzle[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    SudokuSolver solver;

    cout << "========== SUDOKU SOLVER ==========\n";
    cout << "Initial puzzle ('.' means an empty cell):\n";

    if (!solver.setPuzzle(puzzle)) {
        cout << "The supplied puzzle is invalid: a number is repeated in a row, "
             << "column, or 3x3 box.\n";
        return 1;
    }

    solver.printGrid();

    cout << "\nSolving with recursive backtracking...\n";

    if (solver.solve()) {
        cout << "\nSolved Sudoku:\n";
        solver.printGrid();
    } else {
        cout << "\nNo solution exists for this Sudoku puzzle.\n";
        return 1;
    }

    return 0;
}
