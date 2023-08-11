#include <stdio.h>

int main() {
    int n;
    
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    
    int numbers[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    printf("Number\tMinimum\tMaximum\n");

    for (int i = 0; i < n; i++) {
        int num = numbers[i];
        int min = num;
        int max = num;

        for (int j = i + 1; j < n; j++) {
            if (numbers[j] < min) {
                min = numbers[j];
            }

            if (numbers[j] > max) {
                max = numbers[j];
            }
        }

        printf("%d\t%d\t%d\n", num, min, max);
    }

    return 0;
}
