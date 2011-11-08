/*

*/

#include "../QLib/queuelib.h"
#include "graphlib.h"
#include<stdlib.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

void input_graph(struct Vertex *V)
{
	int i,j,num;

	for(i=0;i<n;i++)
	{
		printf("\n---VERTEX %d---\nInput no. of adjacent vertices: ",i+1);
		scanf("%d",&num);
		
		V[i].out_deg = num;
		V[i].adj=malloc(sizeof(int)*num);
		V[i].wt=malloc(sizeof(int)*num);
		
		printf("Input adjacent vertices -\n");
		for(j=0;j<num;j++)
		{
			scanf("%d",&(V[i].adj[j]));
			V[i].adj[j]-=1;
		}
		printf("Input corresponding weights -\n");
		for(j=0;j<num;j++)
			scanf("%d",&(V[i].wt[j]));
	}
}

void display_graph(struct Vertex *V)
{
	int i,j;
		
	for(i=0;i<n;i++)
	{
		printf("\n%d ->\t",i+1);
		for(j=0;j<(V[i].out_deg);j++)
			printf("%d ",V[i].adj[j]+1);
	}
	printf("\n");
}

void BFS(struct Vertex *V,int s)
{
	int i,j,u,p,ct;
	
	Q.size=n;
	Q.front=Q.rear=-1;
	Q.arr=malloc(sizeof(int)*n);
		
	ct=sizeof(*T) * n;
	T=(struct Tree*)malloc(ct);

	for(i=0;i<n;i++)
		T[i].ctr=0;

	for(i=0;i<n;i++)
	{
		if(i==s)
			continue;

		V[i].color=WHITE;
		V[i].parent=-1;
		V[i].dist=-1;
	}
	

	V[s].color=GRAY;
	V[s].parent=-2;
	V[s].dist=0;

	enqueue(s);
	
	while(!isQueueEmpty())
	{
		u=dequeue();
		if(V[u].parent!=-2)
		{
			p=V[u].parent;
			ct=T[p].ctr;
			T[p].adj[ct]=u;
			T[p].ctr++;
		}

		T[u].out_deg=0;
		for(i=0;i<V[u].out_deg;i++)
		{
			j=V[u].adj[i];
			
			if(V[j].color==WHITE)
			{
				V[j].color=GRAY;
				V[j].parent=u;
				V[j].dist=V[u].dist+1;
				enqueue(j);
				T[u].out_deg++;					
			}
		}
		
		T[u].adj=malloc(T[u].out_deg * sizeof(int));
		V[u].color=BLACK;
	}

	free(Q.arr);
}

void reachable_vertices(struct Vertex *V,int s)
{
	int i;
	
	for(i=0;i<n;i++)
		if(V[i].color!=WHITE && i!=s)
			printf(" %d",i+1);
	printf("\n");		V[i].adj=malloc(sizeof(int)*num);
		V[i].wt=malloc(sizeof(int)*num);
}

void shortest_path(struct Vertex *V, int x)
{
	if(V[x].parent==-2)
		printf(" %d",x+1);
		
	else if(V[x].parent==-1)
		printf("\nThis vertex is not reachable from the source vertex!!");

	else
	{
		shortest_path(V,V[x].parent);	
		printf(" %d",x+1);	
	}
}

int shortest_dist(struct Vertex *V,int x)
{
	return V[x].dist;
}

void display_bfstree()
{
	int i,j;
		
	for(i=0;i<n;i++)
	{
		printf("\n%d ->\t",i+1);
		for(j=0;j<(T[i].out_deg);j++)
			printf("%d ",T[i].adj[j]+1);
	}
	printf("\n");
}

void DFS(struct Vertex *V)
{
	int i;
	
	for(i=0;i<n;i++)
	{
		V[i].color=WHITE;
		V[i].parent=-1;
		V[i].dist=-1;
	}
	
	time=0;
	flag=0;
	for(i=0;i<n;i++)
	{
		if(V[i].color==WHITE)
		{
			V[i].dist=0;
			V[i].parent=-2;
			DFS_Visit(V,i);
		}
	}
	
	for(i=0;i<n;i++)
		printf("\n\n%d ",V[i].parent);
	printf("\n\n");
}

void DFS_Visit(struct Vertex *V,int u)
{
	int i,j;
	
	V[u].d=++time;
	V[u].color=GRAY;
	
	for(i=0;i<V[u].out_deg;i++)
	{
		j=V[u].adj[i];
		if(V[j].color==WHITE)
		{
			V[j].parent=u;
			V[j].dist=V[u].dist+1;
			
			DFS_Visit(V,j);
			V[j].color=BLACK;
			V[j].f=++time;
		}
		else if(V[j].color==GRAY)
			flag=1;
	}
}

int* addAdjVert(int num)
{
	int *arr;
	arr=(int *)realloc(arr,sizeof(int)*num);
	return arr;
}

void addVertex(struct Vertex *V)
{
	int num,wgt,ch,outctr;
	V=(struct Vertex *)realloc(V,sizeof(struct Vertex)*(i+1));
	
	outctr=0;	//keeps count of outbound vertices
	
		
	//INPUT LIST OF INBOUND VERTICES FOR THE CURRENT VERTEX
	printf("List adjacent Inbound  vertices and Corresponding weights (Enter V = -1 to stop inputing) -");
	do
	{
		printf("\n V = ");
		scanf("%d",ch); 	//takes vertex index as input in a variable 'ch'
		
		if(ch!=-1)		//if input is -1, stops input  
		{
			if(wtd==TRUE)
			{
				printf(" Wt = ");
				scanf("%d",&wgt);
			}
			
			if(ch<=i)	//checks if the inbound vertex exists, and updates its adjacency list
			{
				ch--;
				num=V[ch].out_deg++;
				V[ch].adj=addAdjVert(num+1);
				V[ch].adj[num]=i-1;
				
				if(wtd==TRUE)
				{
					V[ch].wt=addAdjVert(num+1);
					V[ch].wt[num]=wgt;
				}
			}
			
		}
		
	}while(ch!=-1);
	
	
	//INPUT LIST OF OUTBOUND VERTICES FOR THE CURRENT VERTEX
	printf("\n\nList adjacent Outbound vertices and Corresponding weights (Enter V = -1 to stop inputing) -");
	do
	{
		printf("\n V = ");
		scanf("%d",ch); 	//takes vertex index as input in a variable 'ch'
		
		if(ch!=-1)		//if input is -1, stops input  
		{
			V[i].adj=addAdjVert(outctr+1);
			V[i].adj[outctr]=ch-1;
			
			if(wtd==TRUE)
			{
				printf(" Wt = ");
				scanf("%d",&wgt);
				V[i].wt[outctr]=addAdjVert(outctr+1);
			}
			
			outctr++;
		}
		
	}while(ch!=-1);
	
	V[i].out_deg=outctr;
	i++;
}
