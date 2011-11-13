/**
* This file contains the function definitions for the various algorithms used to compute Single Source Shortest Path 
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

void relax()
{
	
}

/*#include "ShPath_lib.h"*/
/*#include "heaplib.h"*/


/*void Initialize_SS(struct Vertex *V,int s)*/
/*{*/
/*	int i;*/
/*	for(i=0;i<n;i++)*/
/*	{*/
/*		V[i].dist=12345;*/
/*		V[i].parent=-1;*/
/*	}*/
/*	*/
/*	V[s].dist=0;*/
/*}*/

/*void Relax(struct Vertex *V,int u,int k)*/
/*{*/
/*	int U_d,V_d,W,v;*/
/*	*/
/*	U_d = V[u].dist;*/
/*	W = V[u].wt[k];*/

/*	v = V[u].adj[k];*/
/*	V_d = V[v].dist;*/
/*	*/
/*	if(V_d > U_d + W)*/
/*	{*/
/*		V[v].dist = U_d + W;*/
/*		V[v].parent = u;*/
/*	}*/
/*}*/

/*//BellMan Ford*/
/*int Bellman_Ford(struct Vertex *V,int s)*/
/*{*/
/*	int i,j,u,v;*/
/*	*/
/*	Initialize_SS(V,s);*/
/*	for(i=0;i<n-1;i++)*/
/*		for(u=0;u<n;u++)*/
/*			for(j=0;j<V[u].out_deg;j++)*/
/*				Relax(V,u,j);*/
/*	*/
/*	printf("\n\nCOOL--");*/
/*	for(i=0;i<n;i++)*/
/*		printf("%d, ", V[i].dist);*/
/*				*/
/*	for(u=0;u<n;u++)*/
/*	{*/
/*		for(j=0;j<V[u].out_deg;j++)*/
/*		{*/
/*			v = V[u].adj[j];*/
/*			if(V[v].dist > V[u].dist + V[u].wt[j])*/
/*				return 0;*/
/*		}*/
/*	}*/
/*	*/
/*	*/
/*	//printing shortest paths to vertices reachable from source vertex*/
/*	printf("\n\n----SHORTEST PATHS-----");*/
/*	for(i=0;i<n;i++)*/
/*	{*/
/*		if(V[i].dist==12345 || i==s)*/
/*			continue;*/
/*			*/
/*		else*/
/*			print_path(V,i,s);*/
/*	}*/
/*	  	*/
/*	return 1;*/
/*				*/
/*}*/

/*void print_path(struct Vertex *V,int u,int s)*/
/*{*/
/*	int st[n],ctr,i,temp;*/
/*	*/
/*	temp=u;*/
/*	*/
/*	ctr=0;*/
/*	while(u!=s)*/
/*	{*/
/*		st[ctr++]=u;*/
/*		u=V[u].parent;*/
/*	}*/
/*	*/
/*	st[ctr++]=s;*/
/*	*/
/*	printf("\nPath to Vertex %d  - ",temp+1);*/
/*	for(i=ctr-1;i>=0;i--)*/
/*		printf("%d ",st[i]+1);*/
/*	*/
/*	printf("\n");*/
/*}*/

/*//DAG_ShPath*/
/*void DAG_ShPath(struct Vertex *V,int s)*/
/*{}*/


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
