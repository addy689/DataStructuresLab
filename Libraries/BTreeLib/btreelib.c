/**
* This file contains the function definitions for handling B-Tree related operations 
*/

#include "btreelib.h"

void btreeCreate()
{
	struct Node *r;
	
	allocateNode(&r);

	r->leaf = TRUE;
	r->n = 0;
	r->h = 0;
	
	root = r;		//sets root node
}

void allocateNode(struct Node ** M)
{
	(*M) = malloc(sizeof(struct Node));
	(*M)->key = malloc(sizeof(char)*2*t-1);
	(*M)->child = malloc(sizeof(struct Node *)*2*t);
}


//INSERTION
void btreeInsert(char *k)
{
	struct Node *r;
	
	r = root;
	if(r->n == 2*(t-1))				//Root node is full, so split and insert key in the new Root
	{
		btreeSplitRoot();
		btreeInsertNonFull(root,k);
	}
	
	else btreeInsertNonFull(r,k);	//Root node is not full, so insert key in it
}

void btreeSplitRoot()
{
	struct Node *s;
		
	s->n = 0;
	s->leaf = TRUE;
	s->h = 0;
	s->child[0] = root;
	root = s;

	btreeSplitChild(s,0);
}

void btreeInsertNonFull(struct Node *N,char *k)
{
	int i;
	
	i = N->n - 1;
	
	if(N->leaf)		//node N is a leaf node, insert key in it
	{
		while(i>=0 && k < (N->key[i]))
		{
			N->key[i+1] = N->key[i];
			i--;
		}
		
		N->key[i+1] = k;
	}
	
	else		//node N is an internal node, find and traverse child subtree that contains key k, insert in required node
	{
		while(i>=0 && k < (N->key[i]))
			i--;
		i++;
		
		struct Node *ch;
		ch = N->child[i];
		
		if(ch->n == 2*t-1)
		{
			btreeSplitChild(N,i);
			
			if(k > (N->key[t-1]))
				i++;
		}
		
		btreeInsertNonFull(N->child[i],k);
	}
}

void btreeSplitChild(struct Node *N,int i)
{
	int j;
	struct Node *y,*z;		//y stores the pointer to child[i] of node N
	
	allocateNode(&z);		//allocate new node for storing last t-1 elements of child[i] of node N
	y = N->child[i];
	
	//transfer last t-1 keys in 'y' to 'z'
	for(j=0;j<t-1;j++)
		z->key[j] = y->key[t+j];
	
	//if 'y' is not a leaf node, transfer last t child pointers in 'y' to 'z'
	if(!(y->leaf))
	{
		for(j=0;j<t;j++)
			z->child[j] = y->child[t+j];
	}
	
	z->n = t-1;			//update no of keys in new node 'z'
	z->leaf = y->leaf;
	
	//store key present at position t of child[i] into appropriate position in node N
	for(j=(N->n)-1;j>=i;j--)
		N->key[i+1] = N->key[i];
	N->key[i] = y->key[t-1];
	
	//store child pointer present at position t+1 of child[i] into appropriate position in node N
	for(j=(N->n);j>=i;j--)
		N->key[i+1] = N->key[i];
	N->child[i+1] = z;
	
	y->h = N->h + 1;	//update height of node y
	z->h = N->h + 1;	//update height of node z
	
	y->n = t-1;			//update no. of keys in node y
	N->n = N->n + 1;	//update no. of keys in node N
}

//SEARCHING
/*
void btreeSearch(struct Node *N,int k)			//searches for the key 'k' in the B-tree
{
	int i,n;
	
	i = 0;
	n = N->n;
	
	
	while(i<n && k>(N->key[i]))
		i++;
	
	if(i<n && k==(N->key[i]))
		printf("\nKey found at position %d in the node at height %d!",i+1,N->h);
	
	else if(N->leaf)
		printf("\nKey not found");
	
	else btreeSearch(N->child[i],k);
}
*/

//LISTING KEYS
void listKeys(struct Node *N)
{
	if(N->leaf==TRUE)
		displayNode(N);

	else
	{
		listKeys(N->child[0]);
		
		displayNode(N);
		
		int i;
		for(i=1;i<=(N->n);i++)
			listKeys(N->child[i]);
	}
}

void displayNode(struct Node *N)
{
	int i;
	printf("\n--NODE--\n");

	printf("Keys: "); 
	for(i=0;i<(N->n);i++)
		printf("%s",N->key[i]);

	printf("\nDepth: %d\n",N->h);
}
