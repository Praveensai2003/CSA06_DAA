#include <stdio.h>
#include <limits.h>

#define MAX_KEYS 10

float sumOfProb(float freq[], int i, int j) {
    float sum = 0;
    for (int k = i; k <= j; k++)
        sum += freq[k];
    return sum;
}

float optimalBSTCost(float keys[], float freq[], int n) {
    float dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
        dp[i][i] = freq[i];

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int r = i; r <= j; r++) {
                float c = ((r > i) ? dp[i][r - 1] : 0) +
                          ((r < j) ? dp[r + 1][j] : 0) +
                          sumOfProb(freq, i, j);
                if (c < dp[i][j])
                    dp[i][j] = c;
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    float keys[MAX_KEYS], freq[MAX_KEYS];
    printf("Enter the keys and their corresponding probabilities:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &keys[i], &freq[i]);
    }

    float cost = optimalBSTCost(keys, freq, n);
    printf("Optimal BST cost: %f\n", cost);

    return 0;
}
