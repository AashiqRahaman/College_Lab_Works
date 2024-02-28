#include <stdio.h>
void printArray(int array[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}
void insertionSort(int array[], int size)
{
  for (int step = 1; step < size; step++)
  {
    int key = array[step];
    int j = step - 1;
    while (key < array[j] && j >= 0)
    {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}
int main()
{
  int n;
  printf("Enter number of elements to insert in array   :");
  scanf("%d", &n);
  int data[n];
  for (int i = 0; i < n; i++)
  {
    printf("Enter the input values to the array :");
    scanf("%d", &data[i]);
  }
  int size = n;
  insertionSort(data, size);
  printf("Sorted array in ascending order:\n");
  printArray(data, size);
}
