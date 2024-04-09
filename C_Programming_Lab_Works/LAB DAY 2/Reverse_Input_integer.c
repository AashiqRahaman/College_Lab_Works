#include <stdio.h>
void main()
{
    int a, i;
    printf("Enter Any Number:-\n");
    scanf("%d", &i);
    printf("Here is Your Reverse Output:\n");
    while (i != 0)
    {
        a = i % 10;
        printf("%d", a);
        i = i / 10;
    }
}