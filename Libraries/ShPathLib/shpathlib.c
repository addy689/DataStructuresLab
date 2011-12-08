/**
* This file contains the function definitions for three algorithms used to compute Single Source Shortest Path 
*/

#include "shpathlib.h"

void initializeSrc(struct Vertex *V,int s)
{
	int u;
	
	for(u=0;u<vcnt;u++)
	{
		V[u].dist = INFINITY;
		V[u].parent = NIL;
	}
	
	V[s].dist = 0;
}

void relax(struct Vertex *V,int u,int k)
{
	int Ud,Vd,W;
	int v;
	
	Ud = V[u].dist;
	W = V[u].wt[k];

	v = V[u].adj[k];
	Vd = V[v].dist;
	
	if(Vd > Ud + W)
	{
		V[v].dist = Ud + W;
		V[v].parent = u;
	}
}

//BELLMAN FORD
int bellmanFord(struct Vertex *V,int s)
{
	int i,j;
	int u,v;
	
	initializeSrc(V,s);
	
	for(i=0;i<vcnt-1;i++)
		for(u=0;u<vcnt;u++)
			for(j=0;j<V[u].out_deg;j++)
				relax(V,u,j);
				
	//check for negative weight cycles
	for(u=0;u<vcnt;u++)
	{
		for(j=0;j<V[i].out_deg;j++)
		{
			v = V[u].adj[j];
			if(V[v].dist > V[u].dist + V[u].wt[j])
				return 0;
		}
	}
	
	return 1;
}

void printShPath(struct Vertex *V,int s,int v)
{
	if(v==s)
		printf("%d",s+1);
	
	else if(V[v].parent==NIL)
		printf("Inputed vertex is not reachable from the source vertex!!\n");
	
	else 
	{
		printShPath(V,s,V[v].parent);
		printf(" -> %d",v+1);
	}
}

void listNegCycleVertices(struct Vertex *V,int s)	//slight modification to Bellman Ford
{
	int i,j;
	int u,v;
	
	for(u=0;u<vcnt;u++)
		V[u].f=0;
	
	for(u=0;u<vcnt;u++)
	{
		for(j=0;j<V[i].out_deg;j++)
		{
			v = V[u].adj[j];
			if(V[v].dist > V[u].dist + V[u].wt[j])
				bfsBellmanFord(V,v);
		}
	}
}

//DAG SHORTEST PATH
void dagShPath(struct Vertex *V,int s)
{
	int u,i;
	
	struct listNode *Head,*ptr;
	Head = Nil;
	
	//topologically sort the vertices
	topoSort(V,&Head);
	
	//initialize source vertex s
	initializeSrc(V,s);
	
	ptr = Head;
	while(ptr!=Nil)
	{
		u = ptr->data;
		printf("\n%d",u);
		for(i=0;i<V[u].out_deg;i++)
			relax(V,u,i);
		
		ptr = ptr->next;
	}
}
/*void Dijkstra(struct Vertex *V,int s)*/
/*{*/
/*	int A[n];*/
/*	*/
/*	Initialize_SS(V,s);*/

/*	for(i=0;i<n;i++)*/
/*		A[i]=i;*/
/*		*/
/*	heapsize=1;*/
/*	len=n;*/
/*	for(i=1;i<len;i++)*/
/*		min_heap_insert(V,A,A[i]);*/
/*	*/
/*	*/
/*	while(Q!=EMPTY)*/
/*	{*/
/*		u=heap_min_extract(Q);*/
/*	}*/

/*}*/
