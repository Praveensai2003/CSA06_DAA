#include <stdio.h>
#include <stdbool.h>

void sieveOfEratosthenes(int limit) {
    bool isPrime[limit + 1];
    for (int i = 0; i <= limit; i++) {
        isPrime[i] = true;
    }

    for (int p = 2; p * p <= limit; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }

    printf("Prime numbers up to %d are:\n", limit);
    for (int p = 2; p <= limit; p++) {
        if (isPrime[p]) {
            printf("%d ", p);
        }
    }
    printf("\n");
}

int main() {
    int limit;
    printf("Enter the limit to generate prime numbers: ");
    scanf("%d", &limit);

    sieveOfEratosthenes(limit);

    return 0;
}
