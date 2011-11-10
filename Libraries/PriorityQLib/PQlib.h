/**
* This header file contains the function declarations for handling Max Priority Queue and Min Priority Queue operations 
*/

#include<stdio.h>

//MAX PRIORITY QUEUE
int heapMaximum(int[]);					//returns the maximum value in the maxheap
int heapMaxExtract(int[]);				//removes and returns the maximum value in the maxheap
void heapIncreaseKey(int[],int,int);	//increases the value of an element in the maxheap to a given value
void maxheapInsert(int[],int);			//inserts an element into the maxheap by calling heapIncreaseKey()

//MIN PRIORITY QUEUE
int heapMinimum(int[]);					//returns the minimum value in the minheap
int heapMinExtract(int[]);				//removes and returns the minimum value in the minheap
int heapDecreaseKey(int[],int,int);		//decreases the value of an element in the minheap to a given value
int minheapInsert(int[],int);			//inserts an element into the minheap by calling heapDecreaseKey()
