/**
* This file contains function definitions for handling Graph related operations 
*/

//header file "graphlib.h" has been included in file "graphTravlib.h"
#include "graphTravlib.h"
#include "../QueueLib/queuelib.h"

//BREADTH FIRST SEARCH
void breadthFirstSearch(struct Vertex *V,int s)
{
	int u,v;
	int i;
	struct Queue Q;
	
	for(u=0;u<vcnt;u++)
	{
		V[u].color	=	WHITE;
		V[u].dist	=	-10;
		V[u].parent	=	NIL;
	}
	
	V[s].color	=	GRAY;
	V[s].dist	=	0;
	V[s].parent	=	NIL;
	
	initQueue(&Q,vcnt);
	
	enqueue(&Q,s);
	while(!isQueueEmpty(Q))
	{
		u=dequeue(&Q);
		for(i=0;i<V[u].out_deg;i++)
		{
			v = V[u].adj[i];

			if(V[v].color==WHITE)
			{
				V[v].color	=	GRAY;
				V[v].dist	=	V[u].dist+1;
				V[v].parent	=	u;
				
				enqueue(&Q,v);
			}
			
			V[u].color = BLACK;
		}
	}
	
	freeQueue(&Q);
}

void bfsBellmanFord(struct Vertex *V,int s)
{
	int u,v;
	int i;
	struct Queue Q;
	
	for(u=0;u<vcnt;u++)
	{
		V[u].color	=	WHITE;
		V[u].dist	=	-10;
		V[u].parent	=	NIL;
	}
	
	V[s].color	=	GRAY;
	V[s].dist	=	0;
	V[s].parent	=	NIL;
	
	initQueue(&Q,vcnt);
	
	enqueue(&Q,s);
	while(!isQueueEmpty(Q))
	{
		u=dequeue(&Q);
		
		if(V[u].f != 1)
		{
			V[u].f = 1;
			printf("%d ",u);
			
			for(i=0;i<V[u].out_deg;i++)
			{
				v = V[u].adj[i];

				if(V[v].color==WHITE)
				{
					V[v].color	=	GRAY;
					V[v].dist	=	V[u].dist+1;
					V[v].parent	=	u;
				
					enqueue(&Q,v);
				}
			
				V[u].color = BLACK;
			}
		}
		
	}
	
	freeQueue(&Q);
}

void printReachable(struct Vertex *V,int s)
{
	int i;
	
	printf("%d ->",s+1);
	for(i=0;i<vcnt;i++)
	{
		if(V[i].color!=WHITE && i!=s)
			printf(" %d",i+1);
	}
}

void printShortestPath(struct Vertex *V,int s,int u)
{
	if(u==s)
		printf("%d ",u+1);
	
	else if(V[u].parent==NIL)
		printf("\nThe inputed vertex is not reachable from the source vertex!!\n");
	
	else 
	{
		printShortestPath(V,s,V[u].parent);
		printf("-> %d",u+1);
	}
}


//DEPTH FIRST SEARCH
void depthFirstSearch(struct Vertex *V)
{
	int u;
	
	for(u=0;u<vcnt;u++)
	{
		V[u].color	=	WHITE;
		V[u].parent	=	NIL;
	}
	
	time = 0;
	
	for(u=0;u<vcnt;u++)
	{
		if(V[u].color==WHITE)
			dfsVisit(V,u);
	}
}

void dfsVisit(struct Vertex *V,int u)
{
	int i,v;
	
	V[u].color	=	GRAY;
	V[u].d		=	++time;
	
	for(i=0;i<V[u].out_deg;i++)
	{
		v = V[u].adj[i];
		
		if(V[v].color==WHITE)
		{
			V[v].parent = u;
			printf("\n(%d,%d) is a tree edge",u+1,v+1);
			dfsVisit(V,v);
		}
		
		//check if edge is a 'back', 'forward' or 'cross' edge
		else if(V[v].color==GRAY)
		{
			cycle = 1;		//cycle detected in graph
			printf("\n(%d,%d) is a back edge",u+1,v+1);
		}

		else if(V[v].color==BLACK)
		{
			if(isForwardEdge(V,u,v))
				printf("\n(%d,%d) is a forward edge",u+1,v+1);
				
			else printf("\n(%d,%d) is a cross edge",u+1,v+1);
		}
	}
	
	V[u].color	=	BLACK;
	V[u].f		=	++time;
}

int isForwardEdge(struct Vertex *V,int u,int v)
{
	while(V[v].parent!=NIL)
	{
		v = V[v].parent;
		
		if(v==u)
			return 1;
	}
	
	return 0;
}

void topoSort(struct Vertex *V)
{
	int u;
	
	for(u=0;u<vcnt;u++)
	{
		V[u].color	=	WHITE;
		V[u].parent	=	NIL;
	}
	
	time = 0;
	
	allocateNode(&Head);
	Head->next = Nil;
	for(u=0;u<vcnt;u++)
	{
		if(V[u].color==WHITE)
			topoDfsVisit(V,u);
	}
}

void topoDfsVisit(struct Vertex *V,int u)
{
	int i,v;
	
	V[u].color	=	GRAY;
	V[u].d		=	++time;
	
	for(i=0;i<V[u].out_deg;i++)
	{
		v = V[u].adj[i];
		
		if(V[v].color==WHITE)
		{
			V[v].parent = u;
			topoDfsVisit(V,v);
		}
	}
	
	V[u].color	=	BLACK;
	V[u].f		=	++time;

	struct listNode *N;
	allocateNode(&N);
	N->data = u;
	N->next = Head->next;
	Head->next = N;
}

void allocateNode(struct listNode ** M)
{
	(*M) = malloc(sizeof(struct listNode));
	(*M)->next = Nil;
}
