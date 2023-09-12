#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void denominationsUsed(int *, int);
void minimumNumberOfCoinsUsed(int *, int *, int);

int main(void) {

    int signal = 1;

    while (signal == 1) {

        int amount;

        // Prompt user for input
        puts("Enter amount for which change has to be made: ");
        scanf("%d", &amount);

        // Allocate memory for arrays
        int *minCoin = (int *)calloc(amount +1, sizeof(int));
        int *lastCoin = (int *)calloc(amount +1, sizeof(int));

        // Compute minimum number of coins used
        minimumNumberOfCoinsUsed(minCoin, lastCoin, amount);

        // Compute denominations breakdown
        denominationsUsed(lastCoin, amount);

        // Free allocated memory
        free(minCoin);
        free(lastCoin);

        puts("");

        // Prompt user for continuation
        puts("Enter 1 to continue, otherwise press any other number ");
        scanf("%d", &signal);

        puts("");
    }
}

// Function to compute the minimum number of coins used
void minimumNumberOfCoinsUsed(int *minCoin, int *lastCoin, int amount) {
    //variable used to count up to amount
    int cents = 1;

    //define change denominations
    int valueofDenominations[4] = {1, 5, 10, 25};

    while (cents <= amount) {
        //Initial value of the minimum numbers of coins needed to make change for the amount cents
        int numCoin = cents;
        //first denomination to try
        int newCoin = 1;
        
        //counter for denominations used so far
        int j = 0;

        while (j < 4) {
            if (valueofDenominations[j] <= cents) {
                if (minCoin[cents - valueofDenominations[j]] + 1 < numCoin) {
                    numCoin = minCoin[cents - valueofDenominations[j]] + 1;
                    newCoin = valueofDenominations[j];
                }
            }
            //next higher denomination 
            j++;
        }

        //record minimum
        minCoin[cents] = numCoin;
        //record coin that gave minimum
        lastCoin[cents] = newCoin;

        //increase amount
        cents++;
    }
    printf("Minimum number of coins needed: %d\n", minCoin[amount]);
}

// Function to compute denominations breakdown
void denominationsUsed(int *lastCoin, int amount) {

    printf("Denominations breakdown: ");
    int remainingAmount = amount;
    while (amount > 0) {
        int coin = lastCoin[amount];
        printf("%d ", coin);
        amount -= coin;
    }
    printf("\n");

    
}
