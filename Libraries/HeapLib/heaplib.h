/**
* This header file contains the global variable and function declarations for Min Heap and Max Heap operations 
*/

#include<stdio.h>

//GLOBAL HEAP VARIABLES
int len,heapsize;

//DISPLAY HEAP
void displayHeap(int[]);		//displays contents of the heap

//MAX HEAP
void maxHeapify(int[],int);		//moves an element into its appropriate position in the maxheap (To satisfy heap property)
void buildMaxheap(int[]);		//builds a maxheap of an array by repeatedly calling maxHeapify()
void maxheapSort(int[]);		//sorts an array in non-descending order

//MIN HEAP
void minHeapify(int[],int);		//moves an element into its appropriate position in the minheap (To satisfy heap property)
void buildMinheap(int []);		//builds a minheap of an array by repeatedly calling minHeapify()
void minheapSort(int[]);		//sorts an array in descending order
