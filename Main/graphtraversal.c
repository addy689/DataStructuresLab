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
	int x,s;
	struct Vertex *V;
	
	V=NULL;
	vcnt=0;
	wtd=NONWEIGHTED;
	
	printf("\n**Input Graph**\n");
	
	buildGraph(&V);
	
	displayGraph(V);

	//BFS
	printf("\nInput Source Vertex: ");
	scanf("%d",&s);
	
	breadthFirstSearch(V,s-1);
	printf("\nTraversal Complete!!!\n");
	
	printf("\n***Print Shortest Path***\nEnter vertex: ");
	scanf("%d",&x);
	printf("ShPath:  ");
	printShortestPath(V,s-1,x-1);
	
	printf("\n\n***Print Reachable Vertices***\n");
	printReachable(V,s-1);

	freeGraph(&V);
	printf("\n\n");
}
