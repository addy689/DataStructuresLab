/**
* Sample main program to input a graph and list all its connected components using Disjoint Set data structure.

*This program uses the following Libraries. Uncomment these libraries in the file MAKEFILE before running this program (refer to MAKEFILE for instructions on executing this program) -

*	gcc -c ../Libraries/GraphLib/graphlib.c
*	gcc -c ../Libraries/DjSetLib/djsetlib.c

*/

#include "../Libraries/GraphLib/graphlib.h"
#include "../Libraries/DjSetLib/djsetlib.h"
#include<stdlib.h>

int main()
{
	int i,j;
	int u,v;
	int ru,rv;
	
	struct Vertex *V;
	
	V=NULL;
	vcnt=0;
	wtd=NONWEIGHTED;
	
	printf("\n**Input Graph**\n");
	
	buildGraph(&V);
	
	printf("\n***Graph Display***");
	displayGraph(V);
	
	
	//Disjoint Set Operations begin here
	struct Dset *D;
	
	D=(struct Dset *)malloc(sizeof(struct Dset)*vcnt);
	
	for(i=0;i<vcnt;i++)
		makeSet(D,i);
	
	for(u=0;u<vcnt;u++)
	{
		for(j=0;j<V[u].out_deg;j++)
		{
			v=V[u].adj[j];
			
			ru=findSet(D,u);
			rv=findSet(D,v);
			if(ru!=rv)
				unionSets(D,ru,rv);
		}
	}
	
		
	printf("\nThe connected components are -\n");
	for(i=0;i<vcnt;i++)
	{
		if(D[i].flag==0)
		{
			printf("( %d ",i+1);
			D[i].flag=1;
			
			for(j=0;j<vcnt;j++)
			{
				if(i!=j && D[j].flag==0 && D[j].parent==D[i].parent)
				{
					printf("%d ",j+1);
					D[j].flag=1;
				}
			}
			
			printf(")\n");
		}
	}
	
	free(D);
	
	freeGraph(&V);
	
	return 0;
}
