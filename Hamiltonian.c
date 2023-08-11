#include <stdio.h>
#include <stdbool.h>

#define V 5

int graph[V][V] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

int path[V];

bool isValid(int v, int pos, int path[]) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamiltonianCircuitUtil(int path[], int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < V; v++) {
        if (isValid(v, pos, path)) {
            path[pos] = v;

            if (hamiltonianCircuitUtil(path, pos + 1))
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

bool hamiltonianCircuit() {
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;

    if (!hamiltonianCircuitUtil(path, 1)) {
        printf("No Hamiltonian circuit exists.\n");
        return false;
    }

    printf("Hamiltonian circuit exists:\n");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);

    printf("%d\n", path[0]);

    return true;
}

int main() {
    hamiltonianCircuit();

    return 0;
}
