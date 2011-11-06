/* This file contains function definitions for handling Max Priority Queue and Min Priority Queue operations */ 

#include "PQlib.h"

//MAX PRIORITY QUEUE
int heap_maximum(int A[])          
{
    return A[0];
}

int heap_max_extract(int A[])
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

void heap_increase_key(int A[],int pos,int key)
{
    if(key<A[pos])
	printf("New Key is smaller than Current Key");

    else
    {	
	A[pos]=key;
	
	while(pos>0 && A[parent(pos+1)-1]<A[pos])
	{
	    swap(&A[parent(pos+1)-1],&A[pos]);
	    pos=parent(pos+1)-1;
	}
    }
     
}

void max_heap_insert(int A[],int key)
{
    heapsize++;
    len=heapsize;
    A[heapsize-1]=-20;
    heap_increase_key(A,heapsize-1,key);
}
