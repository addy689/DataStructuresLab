/**
* This file contains function definitions for Min Heap and Max Heap operations 
*/

#include "heaplib.h"
#include "../Functions/funclib.h"


//DISPLAY HEAP
void displayHeap(int A[])
{
	int i;
	for(i=0;i<heapsize;i++)
	printf("%d ",A[i]);

}


//MAX HEAP
void maxHeapify(int A[],int x)
{
	int l,r,max;

	l=left(x);
	r=right(x);

	l--;
	r--;
	x--;

	if(l<heapsize && A[l]>A[x])
	max=l;
	else
		max=x;

	if(r<heapsize && A[r]>A[max])
		max=r;

	if(max!=x)
	{
		swap(&A[x],&A[max]);
		maxHeapify(A,++max);
	}
}

void buildMaxheap(int A[])	//build a max heap
{
	int i;
	for(i=heapsize/2;i>0;i--)
		maxHeapify(A,i);
}

void maxheapSort(int A[])	//sort a max heap in ascending order
{
	buildMaxheap(A);

	while(heapsize>1)
	{
		swap(&A[0],&A[heapsize-1]);
		heapsize--;
		maxHeapify(A,1);
	}
}


//MIN HEAP
void minHeapify(int A[],int x)	
{
	int l,r,min;
	
	l=left(x);
	r=right(x);
	
	l--;
	r--;
	x--;
	
	if(l<heapsize && A[x]>A[l])
		min=l;
	else min=x;
	
	if(r<heapsize && A[r]<A[min])
		min=r;
	
	if(min!=x)
	{
		swap(&A[min],&A[x]);
		
		minHeapify(A,++min);
	}
}

void buildMinheap(int A[])	//build a min heap
{
	int i;
	for(i=heapsize/2;i>0;i--)
		minHeapify(A,i);
}

void minheapSort(int A[])	//sort a min heap in descending order
{
	buildMinheap(A);
	
	while(heapsize>1)
	{
		swap(&A[0],&A[heapsize-1]);
		heapsize--;
		minHeapify(A,1);
	}
}
