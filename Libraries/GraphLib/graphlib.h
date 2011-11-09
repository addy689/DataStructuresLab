/* This header file contains the function declarations for handling Graph related operations */

#include<stdio.h>

#define WEIGHTED 1
#define NON 0

int wtd;
static int vcnt=0;

//Structure that defines the members of a Vertex in the graph
struct Vertex{
		int color;	
		int parent;	//integer index of parent vertex 
		int dist;	//distance from source/root vertex of tree (only in BFS)
		int d;		//vertex discovery time (only in DFS)
		int f;		//vertex finishing time (only in DFS)
		
		int out_deg;	//out degree of vertex
		int *adj;	//pointer to an array that stores adjacent vertices
		int *wt;	//pointer to an array that stores weight of each edge
	};


void buildGraph(struct Vertex **);		//constructs a graph at runtime by calling addVertex repeatedly
void addVertex(struct Vertex **);		//adds a vertex to the graph at runtime
void addAdjVert(int**,int);				//allocates memory at runtime for storing (vertices + weights) for a particular vertex
void freeGraph(struct Vertex **);		//releases the memory allocated to the graph 
void displayGraph(struct Vertex *);		//displays the inputed graph

