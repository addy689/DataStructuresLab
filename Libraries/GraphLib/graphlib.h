#include<stdio.h>

int time,flag,wtd;
static int i=0;

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

//Structure that defines a BFS Tree
struct Tree{
		int out_deg;
		int ctr;
		int *adj;
	}*T;

void addVertex(struct Vertex *);
int* addAdjVert(int);

void input_graph(struct Vertex *);
void display_graph(struct Vertex *);
void BFS(struct Vertex *,int);
void reachable_vertices(struct Vertex *,int);
void shortest_path(struct Vertex *, int);
int shortest_dist(struct Vertex *, int);
void display_bfstree();
void DFS(struct Vertex *);
void DFS_Visit(struct Vertex *,int);
