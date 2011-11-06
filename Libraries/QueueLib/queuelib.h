/**
* Integer Queue Implementation 
*/

#include<stdio.h>

struct Queue{
		int size;
		int front;
		int rear;
		int *arr;
	}Q;

void enqueue(int);
int dequeue();
int isQueueFull();
int isQueueEmpty();
void printQueue();
