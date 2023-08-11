#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int list[MAX_SIZE];
    int size, position, newNumber;

    // Input the size of the list
    printf("Enter the size of the list: ");
    scanf("%d", &size);

    if (size >= MAX_SIZE) {
        printf("List size exceeds maximum limit.\n");
        return 1; // Exit with an error code
    }

    // Input the elements of the list
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }

    // Input the position and new number to insert
    printf("Enter the position where you want to insert: ");
    scanf("%d", &position);
    printf("Enter the new number to insert: ");
    scanf("%d", &newNumber);

    // Check if the position is valid
    if (position < 1 || position > size + 1) {
        printf("Invalid position.\n");
        return 1; // Exit with an error code
    }

    // Shift elements to make space for the new number
    for (int i = size; i >= position; i--) {
        list[i] = list[i - 1];
    }

    // Insert the new number at the desired position
    list[position - 1] = newNumber;

    // Increase the size of the list
    size++;

    // Print the updated list
    printf("Updated list after insertion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}
