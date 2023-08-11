#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define N 4 // Number of agents (rows) and tasks (columns)

int costMatrix[N][N] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}
};

int minCost = INT_MAX;
bool assigned[N] = {false}; // To keep track of assigned tasks

void printAssignment(int assignment[N]) {
    printf("Agent\tTask\n");
    for (int i = 0; i < N; i++) {
        printf(" %d\t  %d\n", i, assignment[i]);
    }
}

void branchAndBound(int agent, int cost, int assignment[N]) {
    if (agent == N) {
        if (cost < minCost) {
            minCost = cost;
            printAssignment(assignment);
        }
        return;
    }

    for (int task = 0; task < N; task++) {
        if (!assigned[task] && (cost + costMatrix[agent][task] < minCost)) {
            assignment[agent] = task;
            assigned[task] = true;
            branchAndBound(agent + 1, cost + costMatrix[agent][task], assignment);
            assigned[task] = false;
        }
    }
}

int main() {
    int assignment[N]; // Store the final assignment

    for (int i = 0; i < N; i++) {
        assigned[i] = false;
        assignment[i] = -1;
    }

    printf("Assignments with minimum cost:\n");
    branchAndBound(0, 0, assignment);

    printf("Minimum cost: %d\n", minCost);

    return 0;
}
