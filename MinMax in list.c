#include <stdio.h>

int main() {
    int n; // Number of elements in the list
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int list[n]; // List of elements
    
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }
    
    int minVal = list[0];
    int maxVal = list[0];
    
    for (int i = 1; i < n; i++) {
        if (list[i] < minVal) {
            minVal = list[i];
        }
        if (list[i] > maxVal) {
            maxVal = list[i];
        }
    }
    
    printf("Minimum value: %d\n", minVal);
    printf("Maximum value: %d\n", maxVal);
    
    return 0;
}
