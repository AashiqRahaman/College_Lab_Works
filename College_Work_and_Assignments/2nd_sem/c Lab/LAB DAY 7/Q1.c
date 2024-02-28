#include <stdio.h>
#include <string.h>
int countWords(char str[])
{
    int i, count = 0;

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {
            count++;
        }
    }
    return count;
}
void main()
{   char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    printf("Total number of words = %d\n", countWords(str));
}