/* This header file contains the function declarations for handling Disjoint Set data structure operations */

#include<stdio.h>

struct Dset{
		int rank;
		int parent;
	};

void makeSet(struct Dset *,int)
void unionSets(struct Dset *);
int findSet(struct Dset *);
