#include <stdio.h>
void main()
{   int n, o, i, j;
    printf("Enter Your Input Number For Whose Table Y19ou Want:  ");
    scanf("%d", &n);
    printf("Enter Upto how Long Table You Want:  ");
    scanf("%d", &o);
    printf("Here Is Your Output Table:\n");
    for (i = 1; i <= o; i++)
    {   j = n * i;
        printf("%d x %d = %d\n", n, i, j);
    }
}