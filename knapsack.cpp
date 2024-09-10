#include <stdio.h>
#include <stdlib.h>

struct Item {
    int weight;
    int value;
};

int cmp(const void* a, const void* b) {
    struct Item* itemA = (struct Item*)a;
    struct Item* itemB = (struct Item*)b;
    double r1 = (double)itemA->value / itemA->weight;
    double r2 = (double)itemB->value / itemB->weight;
    return r2 - r1 > 0 ? 1 : -1;
}

double knapsack(struct Item arr[], int n, int W) {
    qsort(arr, n, sizeof(struct Item), cmp);

    double totalValue = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            totalValue += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    struct Item arr[] = {{60, 100}, {100, 120}, {120, 150}};
    int W = 50;
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Maximum value in Knapsack = %.2f\n", knapsack(arr, n, W));
    return 0;
}

