/*
Write a recursive program to find the solution of placing n queens on the chessboard so that no two queens attack each other using Backtracking.
*/
#include <iostream>
#define n 5 // Height of Chessboard and number of Queens
using namespace std;

class nqueens {
public:
    void solveQueens(int board[n][n], int col);
    bool isSafe(int board[n][n], int row, int col);
    void displayBoard(int board[n][n]);
};

void nqueens::solveQueens(int board[n][n], int col) {
    if (col >= n) {
        displayBoard(board);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            solveQueens(board, col + 1);
            board[i][col] = 0; // Backtrack
        }
    }
}

bool nqueens::isSafe(int board[n][n], int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    for (int i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

void nqueens::displayBoard(int board[n][n]) {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << " " << board[i][j];
        cout << "\n";
    }
    cout << "**************************\n";
}

int main() {
    nqueens nq;
    int board[n][n] = {0};
    nq.solveQueens(board, 0);
    return 0;
}