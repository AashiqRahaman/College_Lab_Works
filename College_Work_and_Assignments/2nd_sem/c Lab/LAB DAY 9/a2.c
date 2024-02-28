#include <stdio.h>
#include <string.h>
int main()
{
    char str1[100], str2[100];
    int len1, len2, cmp;
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    len1 = strlen(str1);
    len2 = strlen(str2);
    printf("Length of first string is : %d\n", len1);
    printf("Length of second string is : %d\n", len2);
    cmp = strcmp(str1, str2);
    if (cmp == 0)
    {
        printf("The strings are equal.\n");
    }
    else if (cmp < 0)
    {
        printf("First strings character has smaller ASCII value.\n");
    }
    else
    {
        printf("First strings character has greater ASCII value.\n");
    }
    return 0;
}