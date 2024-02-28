#include <stdio.h>
#include <stdlib.h>
int main(void)
{   int i, j;
    int arr1[4] = {1, 2, 3, 5};
    int arr2[3] = {4, 8, 9};
    int arr3[4 + 3];
    i = j = 0;
    int in;
    for (in = 0; in < 3 + 4; in++)
    {if (i < 4 && j < 3)
        {if (arr1[i] < arr2[j])
            {  arr3[in] = arr1[i];
               i++;           }
            else
            {   arr3[in] = arr2[j];
                j++;           }
        }
    else if (i < 4)
        {arr3[in] = arr1[i];
         i++;        }
    else
        {  arr3[in] = arr2[j];
           j++;        }
    }
printf("The merged array is: \n");
    for (in = 0; in < 4 + 3; in++)
        printf("%d ", arr3[in]);
    printf("\n");
    return 0;
}