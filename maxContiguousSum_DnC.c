#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A structure data type is used to return all the data about a maximum contiguous subsequence
typedef struct struct_mcsData {
int left;
int right;
int sum;
}mcsData;

//function prototypes
mcsData mcs(int s[], int lower, int upper);
mcsData straddlingLeftRight(int s[], int mid, int left, int right);


int main(void){
    // initialize array with random numbers
    srand(time(NULL));

    //generate random numbers
    int s[10];
    for (int i = 0; i < 10; i++) {

        s[i] = rand() % 21 - 10;
        printf("%d ", s[i]);
    }
    printf("\n");

    // call mcs from here
    mcsData result = mcs(s, 0, 10 - 1);


    printf("Maximum contiguous subsequence:\n");
    printf("Sum: %d\n", result.sum);
    printf("Left index: %d\n", result.left);
    printf("Right index: %d\n", result.right);
}// end of main

// the following function returns the data of an mcs that lies between
// the limits lower and upper, both inclusive
mcsData mcs(int s[], int lower, int upper){
    
    //initialize struct for left, right and middle(straddling)
    mcsData leftResult, rightResult, stradResult, result;

    //base case, only 1 element
    if(lower == upper){
        result.left = lower;
        result.right = upper;
        result.sum = s[lower];
        
        return result;
    }
    else{
        
        //find middle index 
        int mid = (upper + lower) / 2;

        
        leftResult = mcs(s, lower, mid);

        rightResult = mcs(s, mid + 1, upper);

        stradResult = straddlingLeftRight(s, mid, lower, upper);

        //compare the 3 results and return the largest one
        if(leftResult.sum >= rightResult.sum && leftResult.sum >= stradResult.sum){
    
            return leftResult;
        }
        else if(rightResult.sum >= leftResult.sum && rightResult.sum >= stradResult.sum){
         
            return rightResult;
        }
        else{
           
            return stradResult;
        }
    }


}// end of mcs
// the following function finds a maximum straddling sequence and
// returns all its data: sum and limits
mcsData straddlingLeftRight(int s[], int mid, int left, int right){

    //initialize struct
    mcsData result;
    int sum = 0;
    int leftSum = 0;
    int leftIndex = mid;
    int rightSum = 0;
    int rightIndex = mid + 1;

    //straddling for left side
    for(int i = mid; i >= left; i--){
        //add mid element to sum
        //add left element to sum for next iteration 
        sum += s[i];

        //if sum is larger than left sum, update left sum and index
        if(leftSum< sum){

            //update sum with new/larger sum
            leftSum = sum;

            //move index to left(current)
            leftIndex = i;
        }

    }

    //reset sum for right side
    sum = 0;

    //straddling for right side
    for(int i = mid +1; i <= right; i++){

        //add mid + 1 element to sum
        //add right element to sum for next iteration
        sum += s[i];

        //if sum is larger than struct sum
        if(rightSum < sum){
            //update sum with new/larger sum
            rightSum = sum;

            //move index to right(current)
            rightIndex = i;
        }

    }

    //add left and right sums
    result.sum = leftSum + rightSum;

    //set left and right index 
    result.left = leftIndex;
    result.right = rightIndex;

    return result;

}// end of straddlingLeftRight
