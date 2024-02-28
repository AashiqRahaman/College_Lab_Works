#include <stdio.h>
void main() 
{
    int A[] = {10, 6, 5, 4, 3};
    int diff[4];
    int i, max;
    for(i=0; i<4; i++) {
        diff[i] = A[i] - A[i+1];
        if(diff[i] < 0) {
            diff[i] = -diff[i];
        }
    }
    max = diff[0];
    for(i=1; i<4; i++) {
        if(diff[i] > max) {
            max = diff[i]; 
        }
    }
    printf("The largest difference is: %d \n", max);
}