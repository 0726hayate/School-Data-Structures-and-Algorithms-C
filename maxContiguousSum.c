//Name: Chun Yiu Jason Yau
//SID: 110117394
//Date created: May 24th 2023

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct entry_struct {
    int start[15];
    int maxSum[15];
    int sum[15];
    int seq[15];
    int maxValue;
} entry;

//generate 15 random numbers from -100 to 200
void seqGen(int*seq){
 
    for (int k = 0; k < 15; k++){ 
        seq[k] = rand() % 200 -100 ; 
    }

}

//assign initial segment sum in intitial table
void initSegSum(int*seq, int*sum){

for (int k = 0; k < 15; k++){
        
        if(seq[k] < 0){
            sum[k] = 0;
        }
        else{

            sum[k] = seq[k];

        }
    }

}

//assigns start index in initial table
void initStart(int*seq, int*start){

    for(int i = 0; i < 15; i++){
        
        //if number is negative, start index is 15
        if(seq[i] < 0){
            start[i] = 15;
        }

        //if number is positive, start index is current
        if(seq[i] >= 0){
            start[i] = i; 
        }
    }

}

//prints the index
void printIndex(){

    printf("Index:\t\t");
    for(int i = 0; i < 15; i++){
        printf("%d\t", i);
    }

    puts("");
}

//prints sequence
void printSeq(int*seq){

    printf("Sequence:\t");
    for(int i = 0; i < 15; i++){
        printf("%d\t", seq[i]);
    }


    puts("");
}

//prints start index
void printStartIndex(int*start){

    printf("Start Index:\t");
    for(int i = 0; i < 15; i++){
        printf("%d\t", start[i]);
    }

    puts("");

}

//prints segment sum
void printSegSum(int*sum){

    printf("Segment Sum:\t");
    for(int i = 0; i < 15; i++){
        printf("%d\t", sum[i]);
    }

    puts("");

}

//prints the table
void printTable(int*seq, int*start, int*sum){
    
    static int count = 1;

    if(count % 2 == 0){
        
        puts("");
        puts("FINAL TABLE");
        puts("___________");
    }
    else{

        puts("");
        puts("INITITAL TABLE");
        puts("______________");

    }

    printIndex();
    printSeq(seq);
    printStartIndex(start);
    printSegSum(sum);

    puts("");

    count++;

}

//calculates segment sum
void calSegSum(int*sum, int*seq, int*start){
    
        for(int i = 1; i < 15; i++){
        
        //if current sum is less than current sum plus next sequence number
        if(sum[i] < sum[i-1] + seq[i]){
        
        // sum will then be current sum plus next sequence number
            sum[i] = sum[i-1] + seq[i];

        //start index will be set to previous index
            start[i] = start[i-1];
        }

    }
}

int calMaxValue(int*sum, int maxValue){

    for(int i = 0; i < 15; i++){

        //if current sum is larger than the max value
        if(sum[i] > maxValue ){
            //then max value will be current sum
            maxValue = sum[i];         

        }

    }

    return maxValue;
}


int main (void){
    
    //seed for random numbers
    srand(time(NULL));

    //array for 10 sequences
    entry en1[10];

    for(int i = 0; i <= 9; i++){

        puts("");
        printf("TABLE %d\n", i+1);
        puts("________________________________________________________________________________________________________________________________________________________");

        //generates 15 random numbers
        seqGen(en1[i].seq);

        //assign start index to numbers
        initSegSum(en1[i].seq, en1[i].sum);

        //assigns start index to segment sum
        initStart(en1[i].seq, en1[i].start);

        //print Initial table
        printTable(en1[i].seq, en1[i].start, en1[i].sum);

        //calculate the segment sum
        calSegSum(en1[i].sum,en1[i].seq,en1[i].start);

        //assign the maxValue
        en1[i].maxValue = calMaxValue(en1[i].sum,0);

        //print final table
        printTable(en1[i].seq, en1[i].start, en1[i].sum);

        //prints max value
        printf("Max Value: %d\n\n", en1[i].maxValue);

        puts("________________________________________________________________________________________________________________________________________________________");

    }



    return 0;
}