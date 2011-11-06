/*
Sample main program to input an array, construct a PriorityQ using the array, and perform basic operations on Priority Queues.
*/

#include "../Libraries/HeapLib/heaplib.h"
#include "../Libraries/PriorityQLib/PQlib.h"

main()
{
    int i,ch,H[20],ps,ky;
    
    printf("Input array length: ");
    scanf("%d",&len);
	
    printf("\nInput array -\n");
    for(i=0;i<len;i++)
        scanf("%d",&H[i]);

    heapsize=len;
    
    //build_maxheap(H);
    build_minheap(H);
    
    printf("\nDisplaying heap -\n");
    display_heap(H);
    
	//printf("\n---------PRIORITY QUEUE-----------\n\n1.) Print maximum value in queue\n2.) Print and extract maximum value in queue\n3.) Increase key for an element in the queue\n4.) Insert key into the queue\n");
	printf("\n---------PRIORITY QUEUE-----------\n\n1.) Print minimum value in queue\n2.) Print and extract minimum value in queue\n3.) Decrease key for an element in the queue\n4.) Insert key into the queue\n");
	
	printf("\nEnter choice (1-4): ");
	scanf("%d",&ch);
	printf("\n");

	switch(ch)
	{
		case 1:
		//printf("%d\n",heap_maximum(H)); 
		printf("%d\n",heap_minimum(H));
		
		printf("Displaying PriorityQ: ");
		display_heap(H);
		break;

		case 2:
		//printf("%d\n",heap_max_extract(H));
		printf("%d\n",heap_min_extract(H));
		printf("Displaying PriorityQ: ");
		display_heap(H);
		break;

		case 3: 
		//printf("Enter position of the queue element whose key you want to increase (1-%d): ",len);
		printf("Enter position of the queue element whose key you want to decrease (1-%d): ",len);
		
		scanf("%d",&ps);
		printf("Enter new key: ");
		scanf("%d",&ky);
		
		//heap_increase_key(H,ps,ky);
		heap_decrease_key(H,ps,ky);
		
		printf("Displaying PriorityQ: ");
		display_heap(H);
		break;

		case 4: printf("Enter the new key you want to insert: ");
		scanf("%d",&ky);
		
		//maxheap_insert(H,ky);
		minheap_insert(H,ky);
		printf("Displaying PriorityQ: ");
		display_heap(H);
		break;

		default: break;
	}
	
	printf("\n");   
}
