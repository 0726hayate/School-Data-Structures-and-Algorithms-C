# School-Data-Structures-and-Algorithms-C
Data Structures and Algorithms made with C
## Balance Parentheses
This C program checks whether a given string of parentheses is balanced or not. It uses a stack data structure to track the opening and closing parentheses. The program includes functions to initialize a stack, check if it's empty, push an element onto the stack, pop an element from the stack, and check if two characters are matching parentheses. The main function prompts the user to enter a string of parentheses, evaluates its balance, and displays the result. The program allows for multiple input validations and continues until the user decides to exit.
## Binary Search
This C program implements the binary search algorithm to search for a target element within a sorted array. It also generates an array with a user-defined size, populates it with pseudo-random numbers, and then searches for a specific value (the size of the array) within the generated list. The program displays the contents of the array along with the index and value. It also indicates whether the target element was found and at what index. The program ensures that the generated list is sorted for binary search.
## Coin Change
This C program helps users determine the minimum number of coins needed to make change for a specified amount. It also provides a breakdown of the denominations used to make the change. The program utilizes dynamic programming to efficiently calculate the minimum coins required for each amount from 1 to the user-specified amount.
## Euclid GCD
This C program demonstrates the Extended Euclidean Algorithm, a mathematical algorithm for finding the Greatest Common Divisor (GCD) of two integers. It also calculates integer coefficients (u and v) that satisfy the equation u * m + v * n = GCD(m, n).
## Fibonacci
This C program calculates the n-th Fibonacci number using three different methods and compares their running times. The Fibonacci sequence is a series of numbers where each number is the sum of the two preceding ones (e.g., 0, 1, 1, 2, 3, 5, 8, ...).
+ Recursive Algorithm:
The program implements the Fibonacci sequence recursively using the formula Fn = Fn-1 + Fn-2. It includes a base case for F0 and F1. This method demonstrates a simple recursive approach to calculate Fibonacci numbers.
+ Iterative Algorithm:
The program uses an iterative approach to compute the n-th Fibonacci number. It uses a loop to calculate each Fibonacci number iteratively from the beginning of the sequence. This method is more efficient than the recursive approach.
+ Dynamic Programming:
The program employs dynamic programming to calculate Fibonacci numbers. It uses an array `knownF` to store previously computed Fibonacci numbers and avoids redundant calculations. This method is the most efficient among the three.
## HashTable
This C program implements a hash table with two probing techniques: linear probing and quadratic probing. It calculates the average number of probes required to insert random keys into the hash table and compares the performance of the two probing methods. The program allows you to specify the load factor, which determines the size of the hash table. It calculates the prime number closest to the desired size for the hash table to optimize performance. Random keys are generated for insertion into the hash table using the `rand()` function. Additionally, the program includes functions to check if a given positive integer is prime and find the next prime after a given number.
## Max Contiguous Sum
This C program generates a series of tables, each representing the calculation of the maximum segment sum of a sequence of 15 random numbers. It uses dynamic programming to calculate the maximum segment sum and provides an initial and final table for each sequence. This program demonstrates dynamic programming techniques for solving the maximum segment sum problem and provides visual representations of the intermediate tables for better understanding.
## Max Contiguous Sum - Divide and Conquer
This C program finds the maximum contiguous subsequence (MCS) from an array of random numbers. It uses a divide-and-conquer algorithm to efficiently find the MCS and returns its sum and indices.The `mcs` function uses a divide-and-conquer approach to find the MCS. It divides the array into smaller segments, finds the MCS for each segment, and then combines the results to find the MCS for the entire array. The `straddlingLeftRight` function is used to find the MCS that straddles the middle of the array. This program demonstrates an efficient algorithm for solving the MCS problem, providing users with the maximum sum and indices of the contiguous subsequence.
## PreOrderBST
This C program generates a binary search tree (BST) with a specified number of nodes, each containing random key values. It then counts the number of different types of nodes in the BST, such as full nodes (nodes with two children), partial nodes (nodes with one child), and leaf nodes (nodes with no children).The program provides insights into the structure of the generated BST by counting the different types of nodes present.
## Quick_Heap_Sort
This C program demonstrates and compares two popular sorting algorithms: QuickSort and HeapSort. It generates a random list of integers, applies both sorting algorithms to the list, and measures their respective running times.The program provides insights into the efficiency of QuickSort and HeapSort for different input sizes.
## Quick_Insertion_Sort
This C program demonstrates and compares two sorting algorithms: QuickSort and Insertion Sort. It generates a list of random integers, applies both sorting algorithms to the list, and measures their respective running times.The program provides insights into the efficiency of QuickSort and Insertion Sort for different input sizes.

