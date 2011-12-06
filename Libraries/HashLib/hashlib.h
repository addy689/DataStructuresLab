/**
* This header file contains the function declarations for handling Hash Table (with collision resolution using "Chaining" method) related operations 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

#define m 26
#define size 255

//Structure that defines a node in a Hash Table chain
struct Node{
		int ct;
		char *data;							//the data to be stored in the Hash Table
		struct Node *next;					//pointer to the next node in the chain
	};

struct Node *NIL;							//to be used as NULL pointer

void insertData(struct Node **,char *);			//inserts the input data
int hashData(char);								//applies the hashing function on the input data (on data[0] actually)
void allocateNode(struct Node **,int);			//allocates memory to a node at runtime
void deleteData(struct Node **,char *);
void displayTable(struct Node **);				//displays the chains corresponding to each hash table slot

struct Node* searchChain(struct Node **,int,char *,int *);			//searches a slot's chain for the given data
void parse(struct Node **,char *);									//parses the data according to certain rules
