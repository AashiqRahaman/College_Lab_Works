#include <stdio.h>
void main()
{
    int a;
    printf("Enter a Natural Number:-\n");
    scanf("%d", &a);
    while (a != 0)
    {
        if (a < 0)
            break;
        printf("Enter a Natural Number:-\n");
        scanf("%d", &a);
    }
    printf("Your Last Input Is Not a Natural Number.");
}