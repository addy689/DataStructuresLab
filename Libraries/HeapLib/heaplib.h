/* This header file contains the global variable and function declarations for Min Heap and Max Heap operations */ 

#include<stdio.h>

//GLOBAL HEAP VARIABLES
int len,heapsize;

//DISPLAY HEAP
void displayHeap(int[]);

//MAX HEAP
void maxHeapify(int[],int);
void buildMaxheap(int[]);
void maxheapSort(int[]);

//MIN HEAP
void minHeapify(int[],int);
void buildMinheap(int []);
void minheapSort(int[]);
