/*
* Sample main program to input an array, construct a heap using the array, and display the values in the heap in descending order 

*This program uses the following Libraries. Uncomment these libraries in the file MAKEFILE before running this program (refer to MAKEFILE for instructions on executing this program) -

*	gcc -c ../Libraries/HeapLib/heaplib.c
*	gcc -c ../Libraries/Functions/funclib.c

*/

#include "..Libraries/HeapLib/heaplib.h"

main()
{
    int i,H[20];
    
    printf("Input array length: ");
    scanf("%d",&len);
	
    printf("\nInput array -\n");
    for(i=0;i<len;i++)
        scanf("%d",&H[i]);
    
    heapsize=len;
    build_minheap(H);
    printf("\nDisplaying heap -\n");
    display_heap(H);
    
    printf("\nArray sorted in descending order (using Min Heap Sort) -\n");
    minheap_sort(H);
    display_heap(H);

            
    printf("\n");
}
