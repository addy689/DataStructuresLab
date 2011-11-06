/* This header file contains the function declarations for handling Max Priority Queue and Min Priority Queue operations */ 

#include<stdio.h>

//MAX PRIORITY QUEUE
int heap_maximum(int[]);
int heap_max_extract(int[]);
void heap_increase_key(int[],int,int);
void max_heap_insert(int[],int);

//MIN PRIORITY QUEUE
int heap_minimum(int[]);
int heap_min_extract(int[]);
int heap_decrease_key(int[],int,int);
int min_heap_insert(int[],int);
