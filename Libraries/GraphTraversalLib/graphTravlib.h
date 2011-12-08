/**
* This header file contains the function declarations for Graph Traversal algorithms and related operations 
*/

#include<stdio.h>
#include<stdlib.h>
#include "../GraphLib/graphlib.h"

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define NIL -1

struct listNode{
		int data;
		struct listNode *next;
	};

struct listNode *Head,*Nil;

//BREADTH FIRST SEARCH
void breadthFirstSearch(struct Vertex *,int);		//traverses a graph using the Breadth First Search technique
void bfsBellmanFord(struct Vertex *,int);			//Modified BFS used by Bellman Ford shortest path algorithm
void printReachable(struct Vertex *,int);			//prints all vertices reachable from the source vertex
void printShortestPath(struct Vertex *,int,int);	//prints all vertices in the shortest path from source to given vertex

//DEPTH FIRST SEARCH
int time;
int cycle;											//if a cycle present in graph, then 'cycle' is 1, otherwise 0
void depthFirstSearch(struct Vertex *);				//traverses a graph using the Depth First Search technique

void dfsVisit(struct Vertex *,int);					//visits a vertex in the graph. This function is called in depthFirstSearch(). It also prints the tree, forward, back and cross edges in the graph

int isForwardEdge(struct Vertex *,int,int);			//returns 1 if edge (u,v) is a forward edge, otherwise returns 0

//TOPOLOGICAL SORT
void topoSort(struct Vertex *,struct listNode **);		//topologically sorts the vertices, and stores the pointer to the sorted list in pointer *Head
void topoDfsVisit(struct Vertex *,int,struct listNode **);		//computes the topologically sorted array
void allocateNode(struct listNode **);							//allocates memory to a node at runtime
void displayList(struct listNode *);							//displays a linked list using its HEAD pointer
