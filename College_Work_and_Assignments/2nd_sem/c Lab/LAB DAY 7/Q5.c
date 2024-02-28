#include <stdio.h>
void main() {
    int arr[5];
    int *ptr = arr;
    int i, max;
      printf("Enter Value in Array:\n");
    for(i=0;i<5;i++)
    {
     scanf("%d",&arr[i]);
    }
    max = *ptr;
    for(i=0; i<5; i++) 
    {
        if(*(ptr+i) > max) 
        {
            max = *(ptr+i);
        }
    }
    printf("The maximum number is: %d \n", max);
}