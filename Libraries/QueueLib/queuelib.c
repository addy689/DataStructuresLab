#include "queuelib.h"

void enqueue(int e)
{
	if(!isQueueFull())
	{
		Q.rear++;
		Q.rear=Q.rear%Q.size;
		Q.arr[Q.rear]=e;
	}
}

int dequeue()
{
	if(!isQueueEmpty(Q))
	{
		Q.front++;
		Q.front=Q.front%Q.size;
		return Q.arr[Q.front];
	}
}

int isQueueEmpty()
{	
	if(Q.rear==Q.front)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

int isQueueFull()
{
	if(Q.front-Q.rear==1 || Q.rear-Q.front==Q.size)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

void printQueue()
{
	int i;
	
	for(i=0;i<Q.size;i++)
	{
		printf("%d ",Q.arr[i]);
	}
	printf("\n");
}
