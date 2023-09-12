//Name: Chun Yiu Jason Yau
//SID: 110117394
//Date created: May 16th 2023

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct entry_struct {
   int firstNumber;
    int secondNumber;
    int gcd;
    int count;
    int predicted;
} entry;

int main(void){

    entry table[50];

    printf("m\tn\tum + vn\t\tnPrime\t\tCount\t\tPredicted\n\n");

    //loop for every random number generated
    for(int i = 0; i < 50; i++){

        // Step 1: initialize variables
        int m = rand() % 100 + 1;
        int n = rand() % 100 + 1;

        int uPrime = 1;   int vPrime = 0;
        int u = 0;        int v = 1;
        int mPrime = m;   int nPrime = n;

        int count = 0;
        
        //loop calculation to get GCD
        while(nPrime != 0){

            //step 2: if mPrime mod nPrime = 0, break out of 2nd loop and print
            if (mPrime % nPrime == 0){
                break;
            }

            //step 3:
            else{
                //save u, v
                int temp1= u;   int temp2 = v;

            //update u,v, 
                //assigning uPrime - mPrime div nPrime * u to u
                u = uPrime - (mPrime / nPrime) * u;
            
                //assigning vPrime - mPrime div nPrime * v to v
                v = vPrime - (mPrime / nPrime) * v;

                //update uPrime with saved old u
                uPrime = temp1;
                //update vPrime with saved old v
                vPrime = temp2;
            
            //Step 4:
                int r = mPrime % nPrime;
                mPrime = nPrime;
                
                nPrime = r;
                
                count++;

            }

            table[i].firstNumber = m;
            table[i].secondNumber = n;            
            table[i].gcd = u*m + v*n;
            table[i].count = count;
            table[i].predicted = 2 * (int)ceil( log(n) / log(2)) + 1;
        
        }

        //both m and n is 0, fix divide by 0 error
        if(table[i].firstNumber == 0 && table[i].secondNumber == 0)
            nPrime = 0;
            
    //Step 5:
        printf("%d\t%d\t%d\t\t%d\t\t%d\t\t%d\n\n", 
                table[i].firstNumber, table[i].secondNumber, table[i].gcd,nPrime ,table[i].count, table[i].predicted);
    }

   

    return 0;
}


