#include <stdio.h>

// A structure to represent an item with weight, value, and ratio
typedef struct {
    int weight;
    int value;
    double ratio; // value-to-weight ratio
} Item;

// Function to swap two items
void swap(Item* a, Item* b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

// Function to calculate the value-to-weight ratio for each item
void calculateRatios(Item items[], int n) {
    for (int i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }
}

// Function to sort items according to value/weight ratio using Bubble Sort
void sortItems(Item items[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (items[j].ratio < items[j+1].ratio) {
                swap(&items[j], &items[j+1]);
            }
        }
    }
}

// Function to calculate the maximum value we can get
double fractionalKnapsack(int W, Item items[], int n) {
    // Calculate value-to-weight ratios
    calculateRatios(items, n);

    // Sort items by value/weight ratio
    sortItems(items, n);

    int currentWeight = 0; // Current weight in knapsack
    double finalValue = 0.0; // Result (value in knapsack)

    for (int i = 0; i < n; i++) {
        // If adding the whole item doesn't overflow, add it
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            finalValue += items[i].value;
        } else {
            // If we can't add the whole item, add the fractional part of it
            int remainingWeight = W - currentWeight;
            finalValue += items[i].value * ((double)remainingWeight / items[i].weight);
            break;
        }
    }
    return finalValue;
}






int main()
{
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &W);

    struct Item items[n];
    printf("Enter the profits and weights of each item:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    double maxValue = fractionalKnapSack(W, items, n);
    printf("Maximum value: %.2f\n", maxValue);

    return 0;
}


// int main() {
//     int W = 50; // Weight of knapsack
//     Item items[] = {{10, 60}, {20, 100}, {30, 120}}; // List of items with (weight, value)
//     int n = sizeof(items) / sizeof(items[0]);

//     printf("Maximum value we can obtain = %.2f\n", fractionalKnapsack(W, items, n));
//     return 0;
// }
