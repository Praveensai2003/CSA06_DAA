#include <stdio.h>

#include <stdlib.h>

int compare(const void *a, const void *b) {

  int x = ((int*)a)[1];

  int y = ((int*)b)[1];

  return x - y;

}



int optimal_cost(int costs[][2], int n) {

  qsort(costs, n, sizeof(int[2]), compare); 



  int total_cost = 0;

  for (int i = 0; i < n; i++) {

    if (costs[i][0] > 0) { 

      total_cost += costs[i][1];

      costs[i][0]--; 

    }

  }



  return total_cost;

}



int main() {

  int costs[][2] = {{10, 20}, {20, 30}, {30, 40}};

  int n = sizeof(costs) / sizeof(costs[0]);

  printf("Optimal cost: %d\n", optimal_cost(costs, n));

  return 0;

}

