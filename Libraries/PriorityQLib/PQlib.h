/* This header file contains the function declarations for handling Max Priority Queue and Min Priority Queue operations */ 

#include<stdio.h>

//MAX PRIORITY QUEUE
int heapMaximum(int[]);
int heapMaxExtract(int[]);
void heapIncreaseKey(int[],int,int);
void maxheapInsert(int[],int);

//MIN PRIORITY QUEUE
int heapMinimum(int[]);
int heapMinExtract(int[]);
int heapDecreaseKey(int[],int,int);
int minheapInsert(int[],int);
