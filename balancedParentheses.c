//Name: Chun Yiu Jason Yau
//SID: 110117394
//Date created: May 31st 2023

#include <stdio.h> // include the standard input/output library
#include <stdlib.h> // include the standard library
#include <string.h> // include the string library
#define SIZE 100 // define a constant for the maximum size of the stack

// define a structure for a stack
typedef struct stack_struct {
    int top; // index of the top element in the stack
    int array[SIZE]; // array to hold the elements of the stack
}Stack;

// function to initialize a stack
void initStack(Stack *stack) {
    stack->top = -1; // set the top index to -1 to indicate an empty stack
}

// function to check if a stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1; // return 1 if the top index is -1, indicating an empty stack
}


// function to push an element onto a stack
void push(Stack *stack, int item) {

    stack->array[++stack->top] = item; // increment the top index and add the item to the top of the stack
}

// function to pop an element from a stack
int pop(Stack *stack) {

    return stack->array[stack->top--]; // return the top element of the stack and decrement the top index
}

// function to check if two characters are matching parentheses
int isMatchingPair(char character1, char character2) {
   if (character1 == '(' && character2 == ')') // check if the characters are an opening and closing parenthesis
     return 1; // return 1 if the characters are a matching pair
   else
     return 0; // return 0 if the characters are not a matching pair
}

// function to check if a string of parentheses is balanced
int areParenthesesBalanced(char exp[]) {
  int i = 0; // initialize a counter variable

  Stack stack; // create a stack
  initStack(&stack); // initialize the stack

  while (exp[i]) { // loop through each character in the string
    if (exp[i] == '(') // if the character is an opening parenthesis
      push(&stack, exp[i]); // push it onto the stack
    if (exp[i] == ')') { // if the character is a closing parenthesis
      if (isEmpty(&stack)) { // check if the stack is empty
        return 0; // return 0 if the stack is empty, indicating an unbalanced string
      } else if (!isMatchingPair(pop(&stack), exp[i])) { // pop the top element from the stack and check if it is a matching pair with the current character
        return 0; // return 0 if the characters are not a matching pair, indicating an unbalanced string
      }
    }
    i++; // increment the counter variable
  }

  if (isEmpty(&stack)) // check if the stack is empty after processing all characters in the string
    return 1; // return 1 if the stack is empty, indicating a balanced string
  else
    return 0; // return 0 if the stack is not empty, indicating an unbalanced string
}

// main function
int main(int argc, char *argv[]) {
  
  char exp[100]; // create an array to hold the input string of parentheses
  int signal = 0; // create a variable to control the while loop

  while(signal == 0){ // loop until the user enters a non-zero value for signal

    printf("Enter a parentheses string: "); // prompt the user to enter a string of parentheses
    scanf("%s", exp); // read the input string from the user

    if (areParenthesesBalanced(exp)) // check if the input string is balanced
        printf("Balanced \n"); // print "Balanced" if the string is balanced
    else
        printf("Not Balanced \n"); // print "Not Balanced" if the string is not balanced

    puts("Press 0 to continue otherwise press any other number"); // prompt the user to enter a value for signal
    scanf("%d", &signal); // read the value of signal from the user

  }

  return 0; // return 0 to indicate successful completion of the program
}