#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to heapify the elements in the index range i to j
void Heapify(int i, int j, int* arr) {
    // Important note: children of a node with index i have indices 2i+1 and 2i+2
    // since array indices start at 0
    int k;

    if (2 * i + 1 > j)
        return;

    if (2 * i + 1 == j)
        k = 2 * i + 1;
    else {
        if (arr[2 * i + 1] >= arr[2 * i + 2])
            k = 2 * i + 1;
        else
            k = 2 * i + 2;
    }

    if (arr[i] < arr[k]) {
        // Swap the elements
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
        // Heapify the affected subtree
        Heapify(k, j, arr);
    }
}

// Function to build a heap
void BuildHeap(int* arr, int size) {
    int i = size-1;
    while (i >= 0) {
        Heapify(i, size, arr);
        i--;
    }
}

// Function to perform HeapSort
void HeapSort(int* arr, int size) {
    BuildHeap(arr, size);

    int i = size - 1;

    while (i > 0) {
        // Swap the root (largest element) with the last element
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        // Re-heapify the reduced heap
        Heapify(0, i-1, arr);
        i--;
    }
}  

// Function to partition an array for QuickSort
int partition(int list[], int p, int q) {
    int pivot = list[p];
    int i = p - 1;
    int j = q + 1;

    while (1) {
        do {
            i++;
        } while (list[i] < pivot);

        do {
            j--;
        } while (list[j] > pivot);

        if (i >= j) {
            return j;
        }

        // Swap elements at positions i and j
        int temp = list[i];
        list[i] = list[j];
        list[j] = temp;
    }
}

// Function to perform QuickSort
void quickSort(int list[], int p, int q) {
    if (p < q) {
        int pivot = partition(list, p, q);

        // Recursively sort the two partitions
        quickSort(list, p, pivot);
        quickSort(list, pivot + 1, q);
    }
}

int main(void) {

    int listSize;
    printf("Enter the size of the list: ");
    scanf("%d", &listSize);

    // Dynamically allocate memory for the array
    int *array = (int *)malloc(listSize * sizeof(int));

    int *array2 = (int *)malloc(listSize * sizeof(int));

    // Seed the random number generator
    srand(time(NULL));

    // Populate the array with random integers
    for (int i = 0; i < listSize; i++) {
        array[i] = rand() % 100;  // Generate a random number between 0 and 99
    }

    // Print the unsorted array
    if(listSize < 15){
        printf("Unsorted array: ");
        for (int i = 0; i < listSize; i++) {
            printf("%d ", array[i]);
        }
        printf("\n\n");
    }

    // Make a copy of the unsorted array for sorting
    for(int i = 0; i < listSize; i++){
        array2[i] = array[i];
    }

    // Sort the copied array using QuickSort and measure the running time
    clock_t startQuickSort = clock();
    quickSort(array2, 0, listSize - 1);
    clock_t endQuickSort = clock();

    // Print the sorted array using QuickSort
    if(listSize < 15){
        printf("Sorted array using Quicksort: ");
        for (int i = 0; i < listSize; i++) {
            printf("%d ", array2[i]);
        }
        printf("\n\n");
    }
    
    // Call HeapSort with the original array and measure the running time
    clock_t startHeapSort = clock();
    HeapSort(array, listSize);
    clock_t endHeapSort = clock();

    // Print the sorted array using HeapSort
    if(listSize < 15){
        printf("Sorted Array using HeapSort: ");
        for (int i = 0; i < listSize; i++) {
            printf("%d ", array[i]);
        }
        printf("\n\n");
    }

    // Calculate and print the running times
    double quickSortTime = (double)(endQuickSort - startQuickSort) / CLOCKS_PER_SEC;
    double heapSortTime = (double)(endHeapSort - startHeapSort) / CLOCKS_PER_SEC;

    printf("Running time of QuickSort: %.6f seconds\n\n", quickSortTime);
    printf("Running time of HeapSort: %.6f seconds\n\n", heapSortTime);

    return 0;
}
