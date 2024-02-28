#include <stdio.h>
#include <string.h>
void main()
{   int len, i;
    char string[200];
    printf("Enter a String:-  ");
    scanf("%s", string);
    len = strlen(string);
    printf("Here is Your Input String's Reverse: \n");
    for (i = len - 1; i >= 0; i--)
    {
        printf("%c", string[i]);
    }
    printf("\n");
}