/* This header file contains the function declarations for handling Disjoint Set data structure operations */

#include<stdio.h>

struct Dset{
		int rank;
		int parent;
		int flag;
	};

void makeSet(struct Dset *,int);
void unionSets(struct Dset *,int,int);
int findSet(struct Dset *,int);
