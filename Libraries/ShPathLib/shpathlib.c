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
		printf("%d",s);
	
	else if(V[v].parent==NIL)
		printf("Inputed vertex is not reachable from the source vertex!!\n");
	
	else 
	{
		printShPath(V,s,V[v].parent);
		printf(" -> %d",v);
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

/*void Bellman(struct Vertex *V,int s)*/
/*{*/
/*	int i,j,u,v,k,p,x;*/
/*	*/
/*	Initialize_SS(V,s);*/
/*	for(i=0;i<n-1;i++)*/
/*		for(u=0;u<n;u++)*/
/*			for(j=0;j<V[u].out_deg;j++)*/
/*				Relax(V,u,j);*/

/*	//Can be attempted another way - using BFS after finding a negative weight cycle*/
/*	printf("\n\nListing of vertices that have a negative weight cycle on some path from the source to that vertex - ");*/
/*	for(i=0;i<n;i++)*/
/*	{*/
/*		if(V[i].parent!=-1)*/
/*		{*/
/*			k=i;*/
/*			*/
/*			do{*/
/*				p=V[k].parent;*/
/*				*/
/*				for(x=0;x<V[p].out_deg;x++)*/
/*					if(V[p].adj[x]==k)*/
/*						break;*/

/*				if(V[p].dist + V[p].wt[x] < V[k].dist)*/
/*				{*/
/*					printf("%d ",i+1);*/
/*					break;*/
/*				}								*/
/*				*/
/*				k=V[k].parent;*/
/*			}while(k!=s);*/
/*		}*/
/*	}*/
/*}*/
