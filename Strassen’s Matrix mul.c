#include <stdio.h>

void addMatrix(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrix(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassenMatrixMultiply(int n, int A[][n], int B[][n], int C[][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int P1[newSize][newSize], P2[newSize][newSize], P3[newSize][newSize], P4[newSize][newSize];
    int P5[newSize][newSize], P6[newSize][newSize], P7[newSize][newSize];

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    subtractMatrix(newSize, B12, B22, P1);
    strassenMatrixMultiply(newSize, A11, P1, P2);

    addMatrix(newSize, A11, A12, P1);
    strassenMatrixMultiply(newSize, P1, B22, P3);

    addMatrix(newSize, A21, A22, P1);
    strassenMatrixMultiply(newSize, P1, B11, P4);

    subtractMatrix(newSize, B21, B11, P1);
    strassenMatrixMultiply(newSize, A22, P1, P5);

    addMatrix(newSize, A11, A22, P1);
    addMatrix(newSize, B11, B22, P2);
    strassenMatrixMultiply(newSize, P1, P2, P6);

    subtractMatrix(newSize, A12, A22, P1);
    addMatrix(newSize, B21, B22, P2);
    strassenMatrixMultiply(newSize, P1, P2, P7);

    addMatrix(newSize, P3, P5, C12);
    addMatrix(newSize, P2, P4, C21);

    addMatrix(newSize, P1, P5, P2);
    addMatrix(newSize, P2, P6, P1);
    subtractMatrix(newSize, P1, P3, P2);
    addMatrix(newSize, P2, P7, C11);

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

void printMatrix(int n, int matrix[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 4; // Size of matrices (should be a power of 2)
    int A[][4] = {{1, 2, 3, 4},
                  {5, 6, 7, 8},
                  {9, 10, 11, 12},
                  {13, 14, 15, 16}};
    int B[][4] = {{17, 18, 19, 20},
                  {21, 22, 23, 24},
                  {25, 26, 27, 28},
                  {29, 30, 31, 32}};
    int C[n][n];

    strassenMatrixMultiply(n, A, B, C);

    printf("Matrix A:\n");
    printMatrix(n, A);

    printf("Matrix B:\n");
    printMatrix(n, B);

    printf("Matrix C (Result of Strassen's Matrix Multiplication):\n");
    printMatrix(n, C);

    return 0;
}
