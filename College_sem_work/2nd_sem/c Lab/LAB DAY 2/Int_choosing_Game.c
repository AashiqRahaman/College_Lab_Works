#include <stdio.h>
void main()
{
    int a, b, i;
    printf("Define Your Lower Limit:-  ");
    scanf("%d", &a);
    printf("Define Your Upper Limit:-  ");
    scanf("%d", &b);
    printf("Here Is Your Even Output In between Your Set Limit:-\n");
    for (i = a; i <= b; i++)
    {
        if (i%2==0)
        {
         printf("%d, ", i);   
        }
    }
}