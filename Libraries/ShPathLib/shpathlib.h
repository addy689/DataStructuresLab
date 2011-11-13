/**
* This header file contains the function declarations for the various algorithms to compute Single Source Shortest Path 
*/

#include<stdio.h>
#include "../GraphLib/graphlib.h"

#define INFINITY 32767

void initializeSrc(struct Vertex *,int);
void relax(struct Vertex *,int,int);

//BELLMAN FORD
int bellmanFord(struct Vertex *,int);
void printPath(struct Vertex *,int,int);

//DIJKSTRA'S ALGORITHM
void dijkstra(struct Vertex *,int);

//DAG SHORTEST PATH
//void dagShPath(struct Vertex *,int);
