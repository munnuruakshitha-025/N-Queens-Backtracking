#include <iostream>
#include <vector>
using namespace std;
bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }
    int i = row - 1;
    int j = col - 1;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 1)
            return false;
        i--;
        j--;
    }
    i = row - 1;
    j = col + 1;

    while (i >= 0 && j < n) {

        if (board[i][j] == 1)
            return false;

        i--;
        j++;
    }

    return true;
}

// Backtracking function
bool solveNQueens(vector<vector<int>>& board,
                  vector<int>& solution,
                  int row,
                  int n) {

    // All queens are placed
    if (row == n)
        return true;

    // Try every column
    for (int col = 0; col < n; col++) {

        // Check whether position is safe
        if (isSafe(board, row, col, n)) {

            // Place queen
            board[row][col] = 1;

            // Store column position
            solution[row] = col + 1;

            // Move to next row
            if (solveNQueens(board, solution, row + 1, n))
                return true;

            // Backtrack
            board[row][col] = 0;
            solution[row] = 0;
        }
    }

    return false;
}

int main() {

    int n;

    cout << "Enter number of queens: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    // Solution vector
    vector<int> solution(n, 0);

    // Solve N-Queens
    if (solveNQueens(board, solution, 0, n)) {

        // Display chessboard
        cout << "\nN-Queens Solution:\n\n";

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                if (board[i][j] == 1)
                    cout << "Q ";
                else
                    cout << ". ";
            }

            cout << endl;
        }

        // Display solution vector
        cout << "\nSolution Vector:\n";

        for (int i = 0; i < n; i++) {
            cout << solution[i] << " ";
        }

        cout << endl;

        cout << "\nSolution found successfully." << endl;
    }
    else {

        cout << "\nNo solution exists for N = "
             << n << endl;
    }

    return 0;
}

