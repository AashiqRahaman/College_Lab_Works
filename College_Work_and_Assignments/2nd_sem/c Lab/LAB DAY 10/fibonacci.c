#include <stdio.h>
void fibonacciSeries(int n, int *prev, int *curr, int count) 
{   if (count == 0) 
    {        printf("%d ", *prev);    }
    if (count < n) 
    {   printf("%d ", *curr);
        int next = *prev + *curr;
        *prev = *curr;
        *curr = next;
        fibonacciSeries(n, prev, curr, count + 1);
    }
}
int main() 
{   int n, prev = 0, curr = 1;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    fibonacciSeries(n, &prev, &curr, 0);
    printf("\n");
    return 0;
}

