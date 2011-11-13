#include "ShPath_lib.h"

main()
{
	int ch,s,x;
	char c;
	
	printf("Input no. of vertices: ");
	scanf("%d",&n);
	
	struct Vertex V[n];
	
	input_graph(V);
	display_graph(V);
	
	do
	{
		printf("\n-------MENU--------\n\n1. Bellman Ford\n2. Bellman Ford Modified\n3. Dijkstra's\n");
	 	
		printf("\nEnter choice (1-3): ");
		scanf("%d",&ch);	
	
		switch(ch)
		{
			case 1: printf("\nInput source vertex s: ");
				scanf("%d",&s);
	
				x=Bellman_Ford(V,s-1);
				if(x==0)
					printf("\nThere is a negative weight cycle!");
				break;
						
			case 2: printf("\nInput source vertex s: ");
				scanf("%d",&s);
	
				Bellman(V,s-1);
				break;
					
			case 3: printf("\nVertices reachable from source vertex (i.e., %d) - ",s);
					reachable_vertices(V,s-1); 
					break;
				
			default: c='n';
		}

		printf("\n\nDo you want to go back to menu? (Y/N) - ");
		scanf("%c",&c);
		scanf("%c",&c);

	}while(c=='Y' || c=='y');
}

