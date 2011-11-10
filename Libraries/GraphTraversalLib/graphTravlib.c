/**
* This file contains function definitions for handling Graph related operations 
*/

#include "graphTravlib.h"
#include "../QueueLib/queuelib.h"

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
