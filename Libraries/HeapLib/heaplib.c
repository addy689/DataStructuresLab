/* This file contains function definitions for Min Heap and Max Heap operations */ 

#include "heaplib.h"
#include "../Functions/funclib.h"

/*	DISPLAY HEAP	*/

void display_heap(int A[])
{
	int i;
	for(i=0;i<heapsize;i++)
	printf("%d ",A[i]);

}


/*	MAX HEAP	*/

void max_heapify(int A[],int x)
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
		max_heapify(A,++max);
	}
}

void build_maxheap(int A[])	//build a max heap
{
	int i;
	for(i=heapsize/2;i>0;i--)
		max_heapify(A,i);
}

void maxheap_sort(int A[])	//sort a max heap in ascending order
{
	build_maxheap(A);

	while(heapsize>1)
	{
		swap(&A[0],&A[heapsize-1]);
		heapsize--;
		max_heapify(A,1);
	}
}


/*	MIN HEAP	*/

void min_heapify(int A[],int x)	
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
		
		min_heapify(A,++min);
	}
}

void build_minheap(int A[])	//build a min heap
{
	int i;
	for(i=heapsize/2;i>0;i--)
		min_heapify(A,i);
}

void minheap_sort(int A[])	//sort a min heap in descending order
{
	build_minheap(A);
	
	while(heapsize>1)
	{
		swap(&A[0],&A[heapsize-1]);
		heapsize--;
		min_heapify(A,1);
	}
}
