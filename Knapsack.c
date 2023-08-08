#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int weight;
    double ratio;
} Item;

// Comparison function for qsort
int compareItems(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    return (itemB->ratio - itemA->ratio);
}

double fractionalKnapsack(int capacity, Item items[], int n) {
    // Calculate value-to-weight ratio for each item
    for (int i = 0; i < n; i++) {
        items[i].ratio = (double) items[i].value / items[i].weight;
    }

    // Sort items based on value-to-weight ratio
    qsort(items, n, sizeof(Item), compareItems);

    double totalValue = 0.0;
    int currentWeight = 0;

    // Fill the knapsack
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            totalValue += items[i].value;
            currentWeight += items[i].weight;
        } else {
            // Take a fraction of the item to fill the remaining space
            double fraction = (double)(capacity - currentWeight) / items[i].weight;
            totalValue += fraction * items[i].value;
            break;
        }
    }

    return totalValue;
}

int main() {
    int capacity = 50;
    Item items[] = {
        {60, 10},
        {100, 20},
        {120, 30}
    };

    int n = sizeof(items) / sizeof(items[0]);

    double maxValue = fractionalKnapsack(capacity, items, n);

    printf("Maximum value in the knapsack: %.2f\n", maxValue);

    return 0;
}
