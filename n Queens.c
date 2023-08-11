#include <stdio.h>

#define N 8

int board[N][N];

// Function to print the board
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a queen can be placed at a given position
int isSafe(int row, int col) {
    // Check the row on the left side
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return 0;
        }
    }
    
    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return 0;
        }
    }
    
    // Check lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return 0;
        }
    }
    
    return 1;
}

// Recursive function to solve N-Queens problem
int solveNQueens(int col) {
    if (col >= N) {
        printBoard();
        return 1; // Successfully placed all queens
    }

    int res = 0;
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;
            res += solveNQueens(col + 1);
            board[i][col] = 0; // Backtrack
        }
    }
    return res;
}

int main() {
    // Initialize the board
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    int solutions = solveNQueens(0);
    printf("Total solutions: %d\n", solutions);

    return 0;
}
