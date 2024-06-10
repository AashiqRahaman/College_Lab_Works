#include <stdio.h>

struct Item
{
    int value;
    int weight;
    double ratio;
};
void swap(struct Item *a, struct Item *b)
{
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

void sortItems(struct Item items[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (items[j].ratio < items[j + 1].ratio)
            {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

double fractionalKnapSack(int W, struct Item items[], int n)
{
    // qsort(items, n, sizeof(items[0]), compare);
    sortItems(items, n);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (W - items[i].weight >= 0)
        {
            totalValue += items[i].value;
            W -= items[i].weight;
        }
        else
        {
            double fraction = (double)W / items[i].weight;
            totalValue += fraction * items[i].value;
            break;
        }
    }

    return totalValue;
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
