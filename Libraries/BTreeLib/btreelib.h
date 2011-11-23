/**
* This header file contains the function declarations for handling B-Tree related operations 
*/

#include<stdio.h>
#include<stdlib.h>

#define FALSE 0
#define TRUE 1

int t;		//stores the minimum degree of a B-tree

//Structure that defines the members of a node in a B-tree data structure
struct Node{
		int n;									//stores the count of keys in the node
		int h;									//stores the height of the node
		int leaf;								//stores 1 if node is a leaf node, otherwise stores 0
		struct Node **child;					//pointer to an array of child nodes
		char **key;								//pointer to an array of keys in the node
	}*root;


void btreeCreate();								//constructs a btree with a single (root) node
void allocateNode(struct Node **);				//allocates memory to a node at runtime

//INSERTION
void btreeInsert(char *);							//inserts the given key into the B-tree using btreeInsertNonFull()
void btreeInsertNonFull(struct Node *,char *);		//inserts the given key into a non full node in the B-tree
void btreeSplitChild(struct Node *,int);		//splits a child node after it becomes full
void btreeSplitRoot();

//SEARCHING
void btreeSearch(struct Node *,int);			//searches for the given key in the B-tree
void listKeys(struct Node *);
void displayNode(struct Node *);
