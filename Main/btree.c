/**
* Sample main program to find single source shortest path using Bellman Ford and Dijkstra's algorithms 

*This program uses the following Libraries. Uncomment these libraries in the file MAKEFILE before running this program (refer to MAKEFILE for instructions on executing this program) -

*	gcc -c ../Libraries/ShPathLib/shpathlib.c


*/

#include "../Libraries/BTreeLib/btreelib.h"

main()
{
	// main
	int ch,keyvalue;
	root = allocateNode();
	root -> n = 0;
	root -> leaf = 1;
	do {
		printf("------------------- Menu -------------------\n");
		printf(" 1. Insert\n");
		printf(" 2. Display\n");
		printf("    Enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1: {
					printf("Enter the key value: ");
					scanf("%d",&keyvalue);
					btreeInsert(keyvalue);
					break;
					}
			case 2: {
					struct node *tmp;
					tmp = root;
					display(tmp);
					break;
					}
		}
	}while (ch<3);
}

B-Tree-FindLargest(x)
//x is the root of the subtree to be searched.
//B-Tree-FindLargest returns a pointer to the node containing the largest key in the subtree whose root is x.

current_node = x
while current_node is not a leaf
current_node = largest child node of current_node
end while
return current_node 

B-Tree-Delete(x, k)
//k is the key to be deleted and 
//x is the root of the subtree from which k is to be deleted.
//B-Tree-Delete returns true if it successfully deletes k else it returns false.
//Note: This function is designed so that whenever it is called recursively x has at least t keys.
{
if x is a leaf then
		if k is in x then
			delete k from x and return true
		
		else return false //k is not in subtree

else //x is an internal node
	{
		if k is in x then 
		{
			y = the child of x that precedes k

			if y has at least t keys then
					k' = the predecessor of k (use B-Tree-FindLargest)
					Copy k' over k //i.e., replace k with k'
					B-Tree-Delete(y, k') //Note: recursive call

			else //y has t-1 keys
			{
				z = the child of x that follows k
				
				if z has at least t keys then
						k' = the successor of k
						Copy k' over k //i.e., replace k with k'
						B-Tree-Delete(z, k') //Note: recursive call
	
				else //both y and z have t-1 keys. merge k and all of z into y | y now contains 2t-1 keys.| k and the pointer to z will be deleted from x.
				B-Tree-Delete(y, k) //Note: recursive call
			}
		}
	}
	
		else //k is not in internal node x.
			ci[x] points to the root, c, of the subtree that could contain k.
			
			if c has t-1 keys then
			{
				if c has an immediate left/right sibling, z, with t or more keys then
						Let k1 be the key in x that precedes/follows c.
						Move k1 into c as the first/last key in c. 
						Let k2 be the last/first key in the immediate left/right sibling, z.
						Replace k1 in x with k2 from z (i.e., move k2 up into x).
						Move the last/first child subtree of z to be the first/last child subtree of c.

			else //c and both of its immediate siblings have t-1 keys.
				//we cannot descend to a child node with only t-1 keys so merge c with one of its immediate siblings and make the appropriate key of x the middle key of the new node, c.
//Note: This may cause the root to collapse, thus making c the new root.
			}
			B-Tree-Delete(c, k)
}


