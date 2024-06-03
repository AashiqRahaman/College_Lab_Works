#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int value;
    int weight;
    double ratio; // Value-to-weight ratio
};

// Comparison function to sort items by ratio in non-decreasing order
int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    return (item2->ratio - item1->ratio) > 0 ? 1 : -1;
}

// Function to compute maximum value using fractional knapsack
double fractionalKnapSack(int W, struct Item items[], int n) {
    // Sort items based on their value-to-weight ratio
    qsort(items, n, sizeof(items[0]), compare);

    double totalValue = 0.0; // Total value in knapsack

    // Fill the knapsack with items as much as possible
    for (int i = 0; i < n; i++) {
        // If adding the entire item exceeds knapsack capacity
        if (W - items[i].weight >= 0) {
            totalValue += items[i].value;
            W -= items[i].weight;
        } else { // Take fraction of item
            double fraction = (double)W / items[i].weight;
            totalValue += fraction * items[i].value;
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    printf("Enter the profits and weights of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (double)items[i].value / items[i].weight; // Calculate ratio
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &W);

    double maxValue = fractionalKnapSack(W, items, n);
    printf("Maximum value: %.2f\n", maxValue);

    return 0;
}

