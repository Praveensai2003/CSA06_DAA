#include <stdio.h>

// Function to print Pascal's Triangle
void printPascalTriangle(int n) {
    for (int line = 1; line <= n; line++) {
        int num = 1;
        for (int i = 1; i <= n - line; i++) {
            printf("   "); // Adjust spacing for formatting
        }
        for (int i = 1; i <= line; i++) {
            printf("%6d", num);
            num = num * (line - i) / i;
        }
        printf("\n");
    }
}

int main() {
    int rows;

    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &rows);

    printPascalTriangle(rows);

    return 0;
}
