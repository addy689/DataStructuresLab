/**
* This header file contains the function declarations for Graph Traversal algorithms and related operations 
*/

#include<stdio.h>
#include "../GraphLib/graphlib.h"

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define NIL -1

//BREADTH FIRST SEARCH
void breadthFirstSearch(struct Vertex *,int);		//traverses a graph using the Breadth First Search technique
void printReachable(struct Vertex *,int);			//prints all vertices reachable from the source vertex
void printShortestPath(struct Vertex *,int,int);	//prints all vertices in the shortest path from source to given vertex

//DEPTH FIRST SEARCH
int time;
int cycle;											//if cycle present in graph, then flag is 1, otherwise 0
void depthFirstSearch(struct Vertex *);				//traverses a graph using the Depth First Search technique
void dfsVisit(struct Vertex *,int);					//visits a vertex. This function is called in depthFirstSearch()
int isForwardEdge(struct Vertex *,int,int);			//returns 1 if edge (u,v) is a forward edge, otherwise returns 0
