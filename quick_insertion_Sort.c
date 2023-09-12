#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void quickSort(int list[], int p, int q);
void insertionSort(int list[], int listSize);
int partition(int list[], int p, int q);

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

    for(int i = 0; i < listSize; i++){
        array2[i] = array[i];
    }

    // Print the unsorted array
    if(listSize < 15){
        printf("Unsorted array: ");
        for (int i = 0; i < listSize; i++) {
            printf("%d ", array[i]);
        }
        printf("\n\n");

    }
    

    // Sort the array using quicksort and measure the running time
    clock_t startQuickSort = clock();
    quickSort(array, 0, listSize - 1);
    clock_t endQuickSort = clock();

    // Print the sorted array using quicksort
    if(listSize < 15){
        printf("Sorted array using Quicksort: ");
        for (int i = 0; i < listSize; i++) {
            printf("%d ", array[i]);
        }
        printf("\n\n");
    }
    

    // Sort the array using insertion sort and measure the running time
    clock_t startInsertionSort = clock();
    insertionSort(array2, listSize);
    clock_t endInsertionSort = clock();

    // Print the sorted array using insertion sort
   
    if(listSize < 15){

        printf("Sorted array using Insertion Sort: ");
        for (int i = 0; i < listSize; i++) {
            printf("%d ", array[i]);
        }
        printf("\n\n");

    }
    

    // Calculate and print the running times
    double quickSortTime = (double)(endQuickSort - startQuickSort) / CLOCKS_PER_SEC;
    double insertionSortTime = (double)(endInsertionSort - startInsertionSort) / CLOCKS_PER_SEC;

    printf("Running time for Quicksort: %.6f seconds\n\n", quickSortTime);
    printf("Running time for Insertion Sort: %.6f seconds\n\n", insertionSortTime);

    // Free the dynamically allocated memory
    free(array);

    return 0;
}

// Quick Sort
void quickSort(int list[], int p, int q) {
    if (p < q) {
        int pivot = partition(list, p, q);
        quickSort(list, p, pivot);
        quickSort(list, pivot + 1, q);
    }
}

// Insertion Sort
void insertionSort(int list[], int listSize) {
    for (int i = 1; i < listSize; i++) {
        int key = list[i];
        int j = i - 1;

        while (j >= 0 && list[j] > key) {
            list[j + 1] = list[j];
            j--;
        }

        list[j + 1] = key;
    }
}

// Partition
int partition(int list[], int p, int q) {
    int pivot = list[p];
    //left pointer
    int i = p - 1;
    //right pointer
    int j = q + 1;

    while (1) {
        do {
            //move left pointer right
            i++;
        } while (list[i] < pivot);

        do {
            //move right pointer left
           j--;
        } while (list[j] > pivot);

        //pointers have crossed
        if (i >= j) {
            return j;
        }

        // Exchange list[i] and list[j]
        int temp = list[i];
        list[i] = list[j];
        list[j] = temp;
    }
}