#include <stdio.h>
void selection_sort(int arr[], int n)
{
	int swap, i, j;
	for (i = 0; i < n - 1; i++)
	{
		int min = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap = arr[i];
			arr[i] = arr[min];
			arr[min] = swap;
		}
	}
	printf("Here is Your Output Array After Selection Sort : \n");
	for (int i = 0; i < n; i++)
	{
		printf("array[%d]  :  %d \n", i, arr[i]);
	}
}
void main()
{
	int n;
	printf("Enter The Elements Number You Want To Input In Array :");
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		printf("Enter The Element To Add An Array[%d] = ", i);
		scanf("%d", &arr[i]);
	}
	selection_sort(arr, n);
}
