#include <stdio.h>
void main()
{   int i, num[5], diff[4],max;
    for (i = 0; i < 5; i++)
    {   printf("Enter Your Input Value:- ");
        scanf("%d", &num[i]);
    }
    for (i = 0; i < 4; i++)
    {
        diff[i] = (num[i] - num[i + 1]);
    }
    printf("{%d,%d,%d,%d}\n", diff[0], diff[1], diff[2], diff[3]);
    diff[0] = max;
    for (i = 1; i < 4; i++)
    {
        if (max < diff[i])
        {        max = diff[i];    }
    }
    printf("The Largest DIfference from the Output Array is :  %d", max);
}