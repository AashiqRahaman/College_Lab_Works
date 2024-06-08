#include <stdio.h>

void buildMaxHeap(float* a, int n) {
    for (int i = n / 2; i >= 0; i--) {
        maxHeapify(a, n, i);
    }
}


void maxHeapify(float* a, int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;

    if (l < n && a[l] > a[largest]) {
        largest = l;
    }

    if (r < n && a[r] > a[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(a, i, largest);
        maxHeapify(a, n, largest);
    }
}


void heapSort(float* a, int n) {
    buildMaxHeap(a, n);

    for (int i = n - 1; i >= 0; i--) {
        swap(a, 0, i);
        maxHeapify(a, i, 0);
    }
}

int main() 
	{
	    int n;
	    printf("Enter the number of elements: ");
	    scanf("%d", &n);

	    float a[n];
	    printf("Enter the elements:\n");
	    for (int i = 0; i < n; i++) {
		scanf("%f", &a[i]);
	    }

	    printf("\nOriginal array:\n");
	    for (int i = 0; i < n; i++) {
		printf("%.2f ", a[i]);
	    }
	    
	    heapSort(a, n);
	    printf("\nSorted array using Heap Sort:\n");
	    for (int i = 0; i < n; i++) {
		printf("%.2f ", a[i]);
	    }
	    return 0;
	 }