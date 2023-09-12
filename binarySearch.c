#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int binarySearch(int arr[], int low, int high, int target) {

    //print contents of the array
    printf("Index\tValue\n");
    printf("----------------\n");
    for (int i = 0; i < target; i++) {
        printf("%d\t%d\n", i, arr[i]);
    }
    printf("----------------\n");
    
    //binary search
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] < target) {
            low = mid + 1;
        } else if(arr[mid] > target){
            high = mid - 1;
        }else{
            return mid;
        }
    }

    return -1; // Target element not found
}

int main(void) {
    int listSize;

    printf("Enter the size of the array: ");
    scanf("%d", &listSize);

    // Allocate memory for the array
    int *list = (int *)calloc(listSize, sizeof(int));

    // Populate array
    srand(time(NULL));
   int previousNumber = pow(-1, rand()) * (rand() % 50);

    for (int i = 0; i < listSize; i++) {
        int increment = 0;
        while (increment == 0) {
            increment = rand() % 2 + 1;
        }
        list[i] = previousNumber + increment;
        previousNumber = list[i];
    }

    // Search for 0 in the modified list
    int index = binarySearch(list, 0, listSize - 1, listSize);

    //print results 
    if (index == -1) {
        printf("Not Found\n");
    } else {
        printf("Found at index %d\n", index);
    }

    // Free the allocated memory
    free(list);

    return 0;
}
