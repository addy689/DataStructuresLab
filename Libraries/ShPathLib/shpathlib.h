/**
* This header file contains the function declarations for three algorithms to compute Single Source Shortest Path 
*/

#include<stdio.h>
#include "../GraphTraversalLib/graphTravlib.h"

#define INFINITY 32767

void initializeSrc(struct Vertex *,int);			//initialize the source vertex
void relax(struct Vertex *,int,int);				//relax an edge (u,v)

//BELLMAN FORD
int bellmanFord(struct Vertex *,int);				//implementation of Bellman Ford algorithm
void printShPath(struct Vertex *,int,int);		//printing shortest paths to reachable vertices from source vertex
void listNegCycleVertices(struct Vertex *,int);		//list each of those vertices having a -ve weight cycle on some path from the source to that vertex

//DAG SHORTEST PATH
void dagShPath(struct Vertex *,int);

//DIJKSTRA'S ALGORITHM
void dijkstra(struct Vertex *,int);					//implementation of Dijkstra's Algorithm
