/**
* This header file contains the function declarations for three algorithms to compute Single Source Shortest Path 
*/

#include<stdio.h>
#include "../GraphLib/graphlib.h"

void initializeSrc(struct Vertex *,int);
void relax(struct Vertex *,int,int);

//BELLMAN FORD
int bellmanFord(struct Vertex *,int);
void printPath(struct Vertex *,int,int);

//DAG SHORTEST PATH
//void dagShPath(struct Vertex *,int);

//DIJKSTRA'S ALGORITHM
void dijkstra(struct Vertex *,int);
