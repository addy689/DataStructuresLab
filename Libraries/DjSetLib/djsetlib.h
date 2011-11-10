/**
* This header file contains the function declarations for handling Disjoint Set data structure operations 
*/

#include<stdio.h>

struct Dset{
		int rank;
		int parent;
		int flag;
	};

void makeSet(struct Dset *,int);			//constructs a set of a given element
void unionSets(struct Dset *,int,int);		//if the 2 given elements do not belong to same set, then combines the 2 sets
int findSet(struct Dset *,int);				//returns the representative of the set that the given element belongs to
