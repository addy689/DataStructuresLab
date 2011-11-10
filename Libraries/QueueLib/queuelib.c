/**
* This file contains function definitions for an Integer Queue Implementation 
*/

#include "queuelib.h"
#include<stdlib.h>

void initQueue(struct Queue *Q,int num)
{
	(*Q).size=num;
	(*Q).front=(*Q).rear=-1;
	(*Q).arr=malloc(sizeof(int)*num);
}

void enqueue(struct Queue *Q,int e)
{
	if(!isQueueFull(*Q))
	{
		(*Q).rear++;
		(*Q).rear=(*Q).rear%(*Q).size;
		(*Q).arr[(*Q).rear]=e;
	}
}

int dequeue(struct Queue *Q)
{
	if(!isQueueEmpty(*Q))
	{
		(*Q).front++;
		(*Q).front=(*Q).front%(*Q).size;
		return (*Q).arr[(*Q).front];
	}
}

int isQueueEmpty(struct Queue Q)
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

int isQueueFull(struct Queue Q)
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

void printQueue(struct Queue Q)
{
	int i;
	
	for(i=0;i<Q.size;i++)
	{
		printf("%d ",Q.arr[i]);
	}
	printf("\n");
}

void freeQueue(struct Queue *Q)
{
	free((*Q).arr);
}
