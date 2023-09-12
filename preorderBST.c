#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tnode {
    int key;
    struct tnode *left;
    struct tnode *right;
} tnode;

// Global variables
int numberOfFullNodes = 0;     // Nodes with two children
int numberOfPartialNodes = 0;  // Nodes with one child
int numberOfLeaves = 0;        // Leaf nodes with no children

// Function prototypes
tnode *addtree(tnode *p, int x);
tnode *talloc(void);
void preOrderCount(tnode *t);
void printValues(tnode *t);
int exists(tnode *root, int x);

int main(void) {
    tnode *root = NULL;
    int numNodes;

    srand(time(NULL));

    // Add number of nodes with random key values
    puts("Enter number of nodes: ");
    scanf("%d",&numNodes);
    

    printf("Values added to the tree: ");
    for (int i = 0; i < numNodes; i++) {
        int key;
        do {
            key = rand() % 100;  // Random key value between 0 and 99
        } while (exists(root, key)); // Check if the key already exists in the tree
        root = addtree(root, key);
        printf("%d ", key);
    }
    printf("\n");

    // Call function preOrderCount
    preOrderCount(root);

    // Print the counts
    printf("Number of Full Nodes: %d\n", numberOfFullNodes);
    printf("Number of Partial Nodes: %d\n", numberOfPartialNodes);
    printf("Number of Leaves: %d\n", numberOfLeaves);

    return 0;
}

// Function to add a key to a binary search tree
tnode *addtree(tnode *p, int x) {
    if (p == NULL) {
        p = talloc();
        p->key = x;
        p->left = p->right = NULL;
    } else if (x < p->key) {
        p->left = addtree(p->left, x);
    } else {
        p->right = addtree(p->right, x);
    }
    return p;
}

// Function to visit the binary search tree in preorder and obtain the counts
void preOrderCount(tnode *t) {
    if (t != NULL) {
        if (t->left != NULL && t->right != NULL) {
            numberOfFullNodes++;
        } else if (t->left != NULL || t->right != NULL) {
            numberOfPartialNodes++;
        } else {
            numberOfLeaves++;
        }

        preOrderCount(t->left);
        preOrderCount(t->right);
    }
}

// Function to allocate memory for a tnode
tnode *talloc(void) {
    return (tnode *)malloc(sizeof(tnode));
}

// Function to print all values in the binary search tree
void printValues(tnode *t) {
    if (t != NULL) {
        printValues(t->left);
        printf("%d ", t->key);
        printValues(t->right);
    }
}

//check if random number generated already exist
int exists(tnode *root, int x) {
    if (root == NULL) {
        return 0;
    }

    if (x == root->key) {
        return 1;
    } else if (x < root->key) {
        return exists(root->left, x);
    } else {
        return exists(root->right, x);
    }
}