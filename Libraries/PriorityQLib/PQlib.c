/* This file contains function definitions for handling Max Priority Queue and Min Priority Queue operations */ 

#include "PQlib.h"
#include "../HeapLib/heaplib.h"


//MAX PRIORITY QUEUE

int heap_maximum(int A[])	//Returns the maximum value in the MaxPriorityQ
{
    return A[0];
}

int heap_max_extract(int A[])	//Extracts and returns the maximum value in the MaxPriorityQ
{
    int max;
    
    if(heapsize<1)
	printf("ERROR: Heap Underflow!");  
    else	
    {
		max=A[0];
		A[0]=A[heapsize-1];

		heapsize--;
		max_heapify(A,1);

		return max;
    }
}

void heap_increase_key(int A[],int pos,int key)		//Increases the value at position 'pos' in the MaxPriorityQ to the value 'key' 
{
    if(key<A[pos-1])
	printf("New Key is smaller than Current Key");

    else
    {	
		A[pos-1]=key;
	
		while(pos>1 && A[parent(pos)-1]<A[pos-1])
		{
			swap(&A[parent(pos)-1],&A[pos-1]);
			pos=parent(pos);
		}
	}
	
}

void maxheap_insert(int A[],int key)		//Inserts a value key into the MaxPriorityQ
{
	heapsize++;
	len=heapsize;
	A[heapsize-1]=-12345;
	heap_increase_key(A,heapsize,key);
}


//MIN PRIORITY QUEUE

int heap_minimum(int A[])			//Returns the minimum value in the MinPriorityQ
{
	return A[0];
}

int heap_min_extract(int A[])			//Extracts and returns the minimum value in the MinPriorityQ
{
	int min;
	
	if(heapsize<1)
		printf("ERROR: Heap Underflow!");  
	else	
	{
		min=A[0];
		A[0]=A[heapsize-1];
		
		heapsize--;
		min_heapify(A,1);
		return min;
	}
}

int heap_decrease_key(int A[],int pos,int key)		//Decreases the value at position 'pos' in the MinPriorityQ to the value 'key' 
{
	if(key>A[pos-1])
	printf("New Key is greater than Current Key");

	else
	{	
		A[pos-1]=key;
	
		while(pos>1 && A[parent(pos)-1]>A[pos-1])
		{
			swap(&A[parent(pos)-1],&A[pos-1]);
			pos=parent(pos);
		}
	}
}

int minheap_insert(int A[],int key)			//Inserts a value key into the MinPriorityQ
{
	heapsize++;
	len=heapsize;
	A[heapsize-1]=12345;
	heap_decrease_key(A,heapsize,key);
}
