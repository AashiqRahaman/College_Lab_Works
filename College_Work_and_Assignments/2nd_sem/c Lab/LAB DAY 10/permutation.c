#include <stdio.h>
#include <string.h>
void swap(char *x, char *y)
{   char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permute(char *str, int start, int end)
{   int i;
    if (start == end)
    {        printf("%s\n", str);    }
    else
    {   for (i = start; i <= end; i++)
        {   swap((str + start), (str + i));
            permute(str, start + 1, end);
            swap((str + start), (str + i));
        }
    }
}
void main()
{   char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int n = strlen(str);
    printf("Permutations of the string:\n");
    permute(str, 0, n - 1);
}