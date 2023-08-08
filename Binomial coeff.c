#include <stdio.h>

unsigned long long binomialCoeff(int n, int k) {
    unsigned long long dp[n + 1][k + 1];
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k && j <= i; j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }
    
    return dp[n][k];
}

int main() {
    int n, k;
    printf("Enter the values of n and k (n choose k): ");
    scanf("%d %d", &n, &k);
    
    unsigned long long coefficient = binomialCoeff(n, k);
    printf("Binomial Coefficient (%d choose %d): %llu\n", n, k, coefficient);
    
    return 0;
}
