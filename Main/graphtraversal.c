/**
* Sample main program to traverse a graph using Breadth First Search and Depth First Search Techniques 

*This program uses the following Libraries. Uncomment these libraries in the file MAKEFILE before running this program (refer to MAKEFILE for instructions on executing this program) -

*	gcc -c ../Libraries/GraphTraversalLib/graphTravlib.c
*	gcc -c ../Libraries/GraphLib/graphlib.c
*	gcc -c ../Libraries/QueueLib/queuelib.c

*/

#include "../Libraries/GraphTraversalLib/graphTravlib.h"

main()
{
	int x;
	int s;			//stores index of the source vertex
	int ch1,ch2,c;	//stores user's choice
	
	//initialize
	vcnt = 0;
	wtd = NONWEIGHTED;
	addvt = 0;
	
	//input graph and display
	struct Vertex *V;
	V=NULL;
	
	printf("\n**Input Graph**\n");
	buildGraph(&V);
	
	printf("\n***Graph Display***");
	displayGraph(V);

	//MENU for selecting method of graph traversal
	printf("\n1. Traverse graph using Breadth-First Search (BFS)");
	printf("\n2. Traverse graph using Depth-First Search (DFS)");
	printf("\n3. Topologically sort the vertices in the graph");
	printf("\nEnter choice (1-3): ");
	scanf("%d",&ch1);
	
	
	//MENU for Breadth-First Search
	if(ch1==1)
	{
		printf("\nInput Source Vertex: ");
		scanf("%d",&s);
		
		breadthFirstSearch(V,s-1);
		printf("\nTraversal Complete!!!\n");

		do
		{
			printf("\n-------MENU--------\n\n");
			printf("1.) Display Adjacency List representation of inputed graph\n");
			printf("2.) List the vertices reachable from the source vertex\n");
			printf("3.) Input a vertex, and print the shortest path to that vertex from the source vertex \n");
			printf("\nEnter choice (1-3): ");
			scanf("%d",&ch2);
	
			switch(ch2)
			{
				case 1: 	printf("\n***Graph Display***");
							displayGraph(V);
							break;
				
				case 2: 	printf("\n***Vertices Reachable From Source***\n");
							printReachable(V,s-1);
							break;
				
				case 3: 	printf("\n***Print Shortest Path***");
							printf("\nEnter vertex: ");
							scanf("%d",&x);
							printf("ShPath:  ");
							printShortestPath(V,s-1,x-1);
							break;
							
				default: c='n';
			}

			printf("\n\nDo you want to go back to menu? (Y/N) - ");
			scanf("%c",&c);
			scanf("%c",&c);
			
		}while(c=='Y' || c=='y');
	}
	
	
	//MENU for Depth-First Search
	else if(ch1==2)
	{
		cycle = 0;
		
		depthFirstSearch(V);
		printf("\n\nTraversal Complete!!!\n");

		do
		{
			printf("\n-------MENU--------\n\n");
			printf("1.) Display Adjacency List representation of inputed graph\n");
			printf("2.) Check if there is a cycle in the graph\n");
			printf("\nEnter choice (1-2): ");
			scanf("%d",&ch2);
	
			switch(ch2)
			{
				case 1: 	displayGraph(V);
							break;
							
				case 2: 	if(cycle==1)
								printf("\nThere is a cycle in the graph.");
							
							else printf("\nThere is no cycle in the graph.");
							
							break;
							
				default: c='n';
			}
			
			printf("\nDo you want to go back to menu? (Y/N) - ");
			scanf("%c",&c);
			scanf("%c",&c);
			
		}while(c=='Y' || c=='y');
	}
	
	
	//MENU for Topological Sort
	else if(ch1==3)
	{
		time = 0;
		
		topoSort(V);
		
		//Display sorted List
		struct listNode *ptr;
		ptr = Head->next;
		
		printf("\nTopologically sorted list of vertices - \n");
		while(ptr!=Nil)
		{
			printf("%d\t",ptr->data+1);
			ptr = ptr->next;
		}
	}
	
	freeGraph(&V);
	printf("\n\n");
}
