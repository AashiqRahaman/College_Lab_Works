#include <stdio.h>
void perfect(int);
void main()
{
    int n;
    printf("Enter any number: ");
    scanf("%d", &n);
    perfect(n);
}
void perfect(int n)
{
    int p, q;
    int arr[100] = {-1};
    for (p = 1; p <= n; p++)
    {
        int sum = 0;
        for (q = 1; q < p; q++)
        {
            if (p % q == 0)
            {
                sum = sum + q;
            }
        }
        if (sum == p)
        {
            printf("%d ", p);
            for (int i=0; i<100;i++)
            {
                if (arr[i] == (-1))
                {
                    arr[i]=sum;
                }

            }
        }
    }
    if (arr[0] == (-1))
    {
        printf("No number found in this limit");
    }
}