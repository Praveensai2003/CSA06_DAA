#include <stdio.h>

#define MAX_CONTAINERS 100
#define MAX_ITEMS 100

typedef struct {
    int id;
    int weight;
} Item;

int containerCapacity;
int numItems;
Item items[MAX_ITEMS];
int containers[MAX_CONTAINERS][MAX_ITEMS];

int numContainers = 0;

void initializeContainers() {
    for (int i = 0; i < MAX_CONTAINERS; i++) {
        for (int j = 0; j < MAX_ITEMS; j++) {
            containers[i][j] = 0;
        }
    }
}

void packItemsGreedy() {
    initializeContainers();

    int currentContainer = 0;

    for (int i = 0; i < numItems; i++) {
        if (containers[currentContainer][0] + items[i].weight <= containerCapacity) {
            containers[currentContainer][0]++;
            containers[currentContainer][containers[currentContainer][0]] = items[i].id;
        } else {
            currentContainer++;
            containers[currentContainer][0]++;
            containers[currentContainer][containers[currentContainer][0]] = items[i].id;
        }
    }

    numContainers = currentContainer + 1;
}

void printContainers() {
    printf("Container loading result:\n");
    for (int i = 0; i < numContainers; i++) {
        printf("Container %d:", i + 1);
        for (int j = 1; j <= containers[i][0]; j++) {
            printf(" Item%d(%d)", containers[i][j], items[containers[i][j] - 1].weight);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the container capacity: ");
    scanf("%d", &containerCapacity);

    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    printf("Enter the weights of items:\n");
    for (int i = 0; i < numItems; i++) {
        items[i].id = i + 1;
        scanf("%d", &items[i].weight);
    }

    packItemsGreedy();
    printContainers();

    return 0;
}
