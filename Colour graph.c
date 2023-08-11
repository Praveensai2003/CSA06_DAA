#include <stdio.h>

#define V 4

int graph[V][V] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};

int m = 3; // Number of colors

int color[V];

int isSafe(int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

void printSolution() {
    printf("Vertex colors:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
}

int graphColoring(int v) {
    if (v == V) {
        return 1;
    }
    
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            color[v] = c;
            if (graphColoring(v + 1)) {
                return 1;
            }
            color[v] = 0; // Backtrack
        }
    }
    
    return 0;
}

int main() {
    for (int i = 0; i < V; i++) {
        color[i] = 0;
    }
    
    if (!graphColoring(0)) {
        printf("No solution exists.\n");
    } else {
        printSolution();
    }
    
    return 0;
}
