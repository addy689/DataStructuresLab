/* This header file contains the function definitions for handling Disjoint Set data structure operations */

#include "djsetlib.h"

void makeSet(struct Dset *dj,int x)
{
	dj[x].rank=0;
	dj[x].parent=x;
}

void unionSets(struct Dset *dj,int x,int y)
{
	if()
}

int findSet(struct Dset *dj,int x)
{

}
