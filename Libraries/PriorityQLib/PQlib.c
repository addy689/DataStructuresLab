/* This file contains function definitions for handling Max Priority Queue and Min Priority Queue operations */ 

#include "PQlib.h"


//MAX PRIORITY QUEUE

int heap_maximum(int A[])	//Returns the maximum value in the PriorityQ
{
    return A[0];
}

int heap_max_extract(int A[])	//Extracts and returns the maximum value in the PriorityQ
{
    int max;
    
    if(heapsize<1)
	printf("ERROR: Heap Underflow!");  
    else	
    {
    	max=A[0];
    	A[0]=A[heapsize-1];

	heapsize--;
    	len=heapsize;
    	max_heapify(A,1);
    
    	return max;
    }
}

void heap_increase_key(int A[],int pos,int key)		//Increases the value at position 'pos' in the PriorityQ to the value 'key' 
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

void max_heap_insert(int A[],int key)		//Inserts a value key into the PriorityQ
{
    heapsize++;
    len=heapsize;
    A[heapsize-1]=-20;
    heap_increase_key(A,heapsize,key);
}


//MIN PRIORITY QUEUE

int heap_minimum(int A[])			//Returns the minimum value in the PriorityQ
{}

int heap_min_extract(int A[])			//Extracts and returns the maximum value in the priority queue
{}

int heap_decrease_key(int A[],int pos,int key)		//Increases the value at position 'pos' in the PriorityQ to the value 'key' 
{}

int min_heap_insert(int A[],int key)			//Inserts a value key into the PriorityQ
{}
