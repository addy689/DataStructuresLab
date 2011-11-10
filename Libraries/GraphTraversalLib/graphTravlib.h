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
void printShortestPath(struct Vertex *,int,int);	//prints all vertices in the shortest path from source to given vertex
void printReachable(struct Vertex *,int);			//prints all vertices reachable from the source vertex

//DEPTH FIRST SEARCH
