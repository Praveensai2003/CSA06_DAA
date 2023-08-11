#include <stdio.h>

#define MAX_SIZE 100

int set[MAX_SIZE];
int subset[MAX_SIZE];
int n, targetSum;

void printSubset(int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

void subsetSum(int currentIndex, int currentSum, int length) {
    if (currentSum == targetSum) {
        printSubset(length);
        return;
    }

    for (int i = currentIndex; i < n; i++) {
        if (currentSum + set[i] <= targetSum) {
            subset[length] = set[i];
            subsetSum(i + 1, currentSum + set[i], length + 1);
        }
    }
}

int main() {
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    printf("Subsets with sum %d:\n", targetSum);
    subsetSum(0, 0, 0);

    return 0;
}
