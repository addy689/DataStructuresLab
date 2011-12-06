/**
* Sample main program to input a graph dynamically, display its adjacency list representation, and release the memory allocated to the graph.

* This program uses the following Libraries. Uncomment these libraries in the file MAKEFILE before running this program (refer to MAKEFILE for instructions on executing this program) -

*	gcc -c ../Libraries/GraphLib/graphlib.c

*/

#include "../Libraries/GraphLib/graphlib.h"

main()
{
	struct Vertex *V;
	V=NULL;
	
	wtd=NONWEIGHTED;
	printf("\n**Input Graph**\n");
	buildGraph(&V);
	
	printf("\n***Graph Display***");
	displayGraph(V);
	
	freeGraph(&V);
}
