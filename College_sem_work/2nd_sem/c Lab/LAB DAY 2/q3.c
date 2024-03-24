#include <stdio.h>
void main()
{
    int a, b, i, n = 2;
    printf("Define Your Lower Limit:-  ");
    scanf("%d", &a);
    printf("Define Your Upper Limit:-  ");
    scanf("%d", &b);
    printf("Here Is Your Odd Output In between Your Set Limit:-\n");
    for (i = a; i <= b; i++)
    {
        if (i == n)
        {
            n = n + 2;
            continue;
        }
        printf("%d, ", i);
    }
}