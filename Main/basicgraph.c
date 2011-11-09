/*
Sample main program to input a graph dynamically, display its adjacency list representation, and release the memory allocated to the graph  
*/

#include "../Libraries/GraphLib/graphlib.h"

main()
{
	struct Vertex *V;
	V=NULL;
	
	wtd=NON;
	printf("\n**Input Graph**\n");
	buildGraph(&V);
	printf("%d",V[0].out_deg);
	printf("%d",V[1].out_deg);
	
	displayGraph(V);
	freeGraph(&V);
	displayGraph(V);
}
