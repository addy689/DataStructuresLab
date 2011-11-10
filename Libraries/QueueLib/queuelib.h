/**
* This header file contains function declarations for an Integer Queue Implementation 
*/

#include<stdio.h>

struct Queue{
		int size;
		int front;
		int rear;
		int *arr;
	};

void initQueue(struct Queue *,int);			//initializes the queue
void enqueue(struct Queue *,int);			//adds an element to the queue
int dequeue(struct Queue *);				//removes an element from the queue
int isQueueFull(struct Queue);				//if queue is full then returns 1, otherwise 0
int isQueueEmpty(struct Queue);				//if queue is empty then returns 1, otherwise 0
void printQueue(struct Queue);				//prints the contents of the queue
void freeQueue(struct Queue *);				//frees the memory allocated to the queue
