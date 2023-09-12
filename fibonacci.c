#include <stdio.h>
#include <time.h>

#define MAX 100

int knownF[MAX];

//part 1: Fn = Fn-1 + Fn-2 for n > 1; and F0 = 0; F1 = 1;
unsigned long fibo1(unsigned int n) {

    //base case when n is 0
    if (n == 0) {

        return 0;

    //base case when n is 1
    } else if (n == 1) {

        return 1;

    //case when n is larger than 1
    } else {

        //recursive formula for Fibonacci number
        return fibo1(n-1) + fibo1(n-2);
    }
}

//Part 2: iterative algorithm for computing the n-th Fibonacci number
unsigned long fibo2(unsigned int n) {

    //when user enters 0
    if (n == 0) {

        return 0;

    // when user enters 1
    } else if (n == 1) {

        return 1;

    } 
    //use enters number larger than 1
    //to calculate Fibonacci number
    else {

        //store previous 2 numbers, starting from the begining of the Fibonacci sequence
        unsigned long prev1 = 0, prev2 = 1, curr;

        //loop to calculate the Fibonacci number
        for (unsigned int i = 2; i <= n; i++) {

            //formula for nth Fibonacci number
            curr = prev1 + prev2;

            //store previoous 2nd number for next loop
            prev1 = prev2;

            //store previous number for next loop
            prev2 = curr;

        }
        //returns the nth Fibonacci number
        return curr;
    }
}

//Part 3: Dynamic programming for computing the n-th Fibonacci number
unsigned long fibo3(int n) {

    if (knownF[n] != 0) return knownF[n];

    unsigned long t = n ;
    
    if (n < 0) return 0;
    
    if (n > 1) t = fibo3(n-1) + fibo3(n-2);
    
    return knownF[n] = t;
}



int main(){

    int n;
    clock_t start, end;
    double time, time1, time2, quick;
    unsigned long long result;

    //promt user to enter the nth Fibonacci number they want
    puts("Please enter a number less than 100 for the nth Fibonacci that you want");
    scanf("%d", &n);
    puts("");



    //start timing the running time for part 1, Fn = Fn-1 + Fn-2 for n > 1; and F0 = 0; F1 = 1;
    start = clock();

    //call function for part 1
    result = fibo1(n);
    printf("Result for part 1: %llu\n", result);

    //stop timing the running time for part 1
    end = clock();

    //caculate the running time in seconds
    time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Running time of part 1: %0.20f\n\n", time);




    //start timing the running time for part 2, iterative algorithm
    start = clock();

    //call the function for part 2
    result = fibo2(n);
    printf("Result for part 2: %llu\n", result);

    //stop timing the running time for part 2
    end = clock();

    //caculate the running time in seconds
    time1 = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Running time of part 2: %0.20f\n\n", time1);




    //start timing the running time for part 3, code given in the lab
    start = clock();

    //call the function for part 3
    result = fibo3(n);
    printf("Result for part 3: %llu\n", result);

    //stop timing the running time for part 3
    end = clock();

    //caculate the running time in seconds
    time2 = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Running time of part 3: %0.20f\n\n", time2);


    //code to find the quickest running time out of the 3 functions, to compare the 3 functions
    quick = time;
    int quickest = 1;

    if (time1 < quick){
        quick = time1;
        quickest = 2;
    }

    if (time2 < quick){
        quick = time2;
        quickest = 3;
    }

    if (quickest == 1) {
        printf("The function with the shortest running time is the recursive algorithm for computing the n-th Fibonacci number (part1)\n");
    } else if (quickest == 2) {
        printf("The function with the shortest running time is the iterative function (part2)\n");
    } else {
        printf("The function with the shortest running time is the one using dynamic programming\n");
    }

    return 0;
    
}
