/**
* Sample main program to find single source shortest path using Bellman Ford and Dijkstra's algorithms 

*This program uses the following Libraries. Uncomment these libraries in the file MAKEFILE before running this program (refer to MAKEFILE for instructions on executing this program) -

*	gcc -c ../Libraries/ShPathLib/shpathlib.c
*	gcc -c ../Libraries/GraphTraversalLib/graphTravlib.c
*	gcc -c ../Libraries/GraphLib/graphlib.c
*	gcc -c ../Libraries/QueueLib/queuelib.c


*/

#include "../Libraries/ShPathLib/shpathlib.h"

main()
{
	int x,u;
	int s;			//stores index of the source vertex
	int ch1,ch2;	//stores user's choice
	char c;			//stores user's choice
	int negcycle;	//stores 1 if negative weight cycle is present, otherwise stores 0
	
	//initialize
	wtd = WEIGHTED;
	vcnt = 0;
	addvt = 0;
	
	//input graph and display
	struct Vertex *V;
	V=NULL;
	
	printf("\n**Input Graph**\n");
	buildGraph(&V);
	
	printf("\n***Graph Display***");
	displayGraph(V);

	//MENU for selecting method of computing shortest path of vertices from single source
	printf("\n1. Bellman Ford");
	printf("\n2. Dijkstra's");
	printf("\nEnter choice (1 or 2): ");
	scanf("%d",&ch1);
	
	
	//MENU for Bellman Ford
	if(ch1==1)
	{
		printf("\nInput Source Vertex: ");
		scanf("%d",&s);
		
		negcycle = !bellmanFord(V,s-1);
		printf("\nShortest path calculation complete!!!\n");
		
		
		do
		{
			printf("\n-------MENU--------\n\n");
			printf("1.) Display Adjacency List representation of inputed graph\n");
			printf("2.) Display the weight of the shortest path (from the source vertex) to each vertex\n");
			printf("3.) Input a vertex, and print the shortest path to that vertex from the source vertex\n");
			printf("4.) Print each of those vertices that have a negative weight cycle on some path from the source to that vertex\n");
			printf("\nEnter choice (1-4): ");
			scanf("%d",&ch2);
			
			switch(ch2)
			{
				case 1:		printf("\n***Graph Display***");
							displayGraph(V);
							break;
				
				case 2:		printf("\nVertex\t->\tWeight of shortest path from source");
							for(u=0;u<vcnt;u++)
								printf("\n%d\t%d",u+1,V[u].dist);
							break;
				
				case 3:		if(negcycle)
							{
								printf("\nNegative weight cycle has been detected!!");
								break;
							}
							
							printf("\n***Print Shortest Path***");
							printf("\nEnter vertex: ");
							scanf("%d",&x);
							printf("\nPath - ");
							printShPath(V,s-1,x-1);
							break;
							
				case 4:		printf("\nList of vertices with a -ve weight cycle on some path from the source to that vertex --\n");
							listNegCycleVertices(V,s-1);
							break;
				
				default: c='n';
			}

			printf("\n\nDo you want to go back to menu? (Y/N) - ");
			scanf("%c",&c);
			scanf("%c",&c);
			
		}while(c=='Y' || c=='y');
	}
	
	
	//MENU for Dijkstra's
	
	freeGraph(&V);
}

