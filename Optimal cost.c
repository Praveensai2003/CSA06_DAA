#include <stdio.h>
#include <limits.h>

#define MAX_N 10

int n; // Number of cities
int dist[MAX_N][MAX_N];
int memo[MAX_N][1 << MAX_N];

int tsp(int u, int mask) {
    if (mask == (1 << n) - 1) {
        return dist[u][0];
    }

    if (memo[u][mask] != -1) {
        return memo[u][mask];
    }

    int minCost = INT_MAX;
    for (int v = 0; v < n; v++) {
        if (!(mask & (1 << v))) {
            int newCost = dist[u][v] + tsp(v, mask | (1 << v));
            minCost = (newCost < minCost) ? newCost : minCost;
        }
    }

    return memo[u][mask] = minCost;
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            memo[i][j] = -1;
        }
    }

    int optimalCost = tsp(0, 1); // Start from city 0 with the first bit set

    printf("Optimal cost for the Traveling Salesman Problem: %d\n", optimalCost);

    return 0;
}
