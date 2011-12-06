/**
* This file contains function definitions for handling Hash Table (with collision resolution using "Chaining" method) related operations 
*/

#include "hashlib.h"


void insertData(struct Node **H, char *str)
{
	int k;
	
	k = hashData(str[0]);
	
	struct Node *N;
	allocateNode(&N,strlen(str));
	
	strcpy(N->data,str);		//input data is copied into the new node
	N->next = H[k]; 			//first node in the existing chain is assigned as the next node to the new node
	
	H[k] = &N;					//new node is inserted at the Head of the chain
}

int hashData(char ch)
{
	ch = toupper(ch);
	return ch%m;
}

void allocateNode(struct Node ** M,int len)
{
	(*M) = malloc(sizeof(struct Node));
	(*M)->data = malloc(sizeof(char)*len);
	(*M)->next = NIL;
}

void displayData(struct Node *)
{
	int i;
	struct Node *ptr;
	 
	printf("\n\n--- Hash Table ---\n");
	for(i=0;i<m;i++)
	{
		printf("\n%d ->",i);
		
		ptr = H[i];
		while(ptr->next!=NIL)
		{
			printf("\t%s",ptr->data);
			ptr = ptr->next;
		}
	}
}

/*void deleteData(struct Node *)*/
