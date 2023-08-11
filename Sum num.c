#include <stdio.h>

int main() {
    int number, originalNumber, sum = 0, digit;

    printf("Enter an integer: ");
    scanf("%d", &number);

    originalNumber = number;

    while (number != 0) {
        digit = number % 10;
        sum += digit;
        number /= 10;
    }

    printf("Sum of digits of %d is %d\n", originalNumber, sum);

    return 0;
}
