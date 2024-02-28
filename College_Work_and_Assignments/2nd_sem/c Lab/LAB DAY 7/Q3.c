#include <stdio.h>
void main()
{
    int input1[] = {1, 2, 3, 4, 5};
    int input2[] = {3, 4, 5, 6, 7};
    int output[5];
    int i, j, k = 0;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (input1[i] == input2[j])
            {
                output[k] = input1[i];
                k++;
                break;
            }
        }
    }
    printf("The common elements are: [ ");
    for (i = 0; i < k; i++)
    {
        printf("%d ", output[i]);
    }
    printf("]\n");
}