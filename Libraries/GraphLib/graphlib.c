/**
* This file contains function definitions for handling Graph related operations 
*/

#include "graphlib.h"
#include<stdlib.h>

void buildGraph(struct Vertex ** vt)
{
	char c;

	do
	{
		printf("\n---VERTEX %d---\n",vcnt+1);
		addVertex(vt);
		printf("Input one more vertex? (Y/N) - ");
		scanf("%c",&c);
		scanf("%c",&c);
	}while(c=='Y' || c=='y');
}

void addVertex(struct Vertex ** vt)
{
	int num,wgt,in,out,outctr,k,flg;

	(*vt)=(struct Vertex *)realloc(*vt,sizeof(struct Vertex)*(vcnt+1));
	
	struct Vertex *Vt;
	Vt=*vt;
	
	outctr=0;	//keeps count of outbound vertices
	flg=0;
	
	
	if(addvt==1)	//check if a vertex is being added after entire graph has already been inputed once
	{
		//INPUT LIST OF INBOUND VERTICES FOR THE CURRENT VERTEX
		printf(" List adjacent Inbound vertices ");

		if(wtd==WEIGHTED)
			printf("and corresponding weights ");
		
		printf("(Enter V=-1 to stop inputing):\n");
	
		do
		{
			printf(" V= ");
			scanf("%d",&in); 	//takes vertex index as input in a variable 'ch'
	
			if(in!=-1)		//if input is -1, stops input  
			{
				if(wtd==WEIGHTED)
				{
					printf(" Wt= ");
					scanf("%d",&wgt);
				}
			
				if(in<=vcnt)	//checks if the inbound vertex is not already present, and updates its adjacency list
				{
					k=0;
					while(k<Vt[in].out_deg)		//searches the adjacent vertices array of vertex 'in' for vertex 'vcnt'
					{
						if(Vt[in].adj[k]==vcnt)
						flg=1;
						k++;
					}
					
					if(flg==1)
					{
						in--;
						num=Vt[in].out_deg++;
						addAdjVert(&Vt[in].adj,num+1);
						Vt[in].adj[num]=vcnt;
				
						if(wtd==WEIGHTED)
						{
							addAdjVert(&Vt[in].wt,num+1);
							Vt[in].wt[num]=wgt;
						}
					}
				
				}
			}
		
		}while(in!=-1);
	}
	
	//INPUT LIST OF OUTBOUND VERTICES FOR THE CURRENT VERTEX
	printf("\n List adjacent Outbound vertices ");

	if(wtd==WEIGHTED)
		printf("and corresponding weights ");
		
	printf("(Enter V=-1 to stop inputing):\n");
	
	Vt[vcnt].adj=NULL;
	Vt[vcnt].wt=NULL;
	do
	{
		printf(" V= ");
		scanf("%d",&out); 	//takes vertex index as input in a variable 'ch'
		
		if(out!=-1)		//if input is -1, stops input  
		{
			addAdjVert(&Vt[vcnt].adj,outctr+1);
			Vt[vcnt].adj[outctr]=out-1;
			
			if(wtd==WEIGHTED)
			{
				printf(" Wt= ");
				scanf("%d",&wgt);
				addAdjVert(&Vt[vcnt].wt,outctr+1);
				Vt[vcnt].wt[outctr]=wgt;
			}
			
			outctr++;
		}
		
	}while(out!=-1);
	
	Vt[vcnt].out_deg=outctr;
	vcnt++;
}

void addAdjVert(int **arr,int num)
{
	(*arr)=(int *)realloc(*arr,sizeof(int)*num);
}

void freeGraph(struct Vertex ** vt)
{
	int u;
	for(u=0;u<vcnt;u++)
	{
		free((*vt)[u].adj);
		free((*vt)[u].wt);
	}
	free(*vt);
}

void displayGraph(struct Vertex *V)
{
	int i,j;
	
	printf("\n***Graph Display***");
	for(i=0;i<vcnt;i++)
	{
		printf("\n%d ->\t",i+1);
		
		for(j=0;j<(V[i].out_deg);j++)
			printf("%d ",V[i].adj[j]+1);
	}
	
	printf("\n");
}
