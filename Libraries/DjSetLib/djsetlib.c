/* This header file contains the function definitions for handling Disjoint Set data structure operations */

#include "djsetlib.h"

void makeSet(struct Dset *Dj,int x)
{
	Dj[x].rank=0;
	Dj[x].parent=x;
	Dj[x].flag=0;
}

void unionSets(struct Dset *Dj,int rx,int ry)
{
	if(Dj[rx].rank > Dj[ry].rank)
		Dj[ry].parent = rx;
	
	else
	{
		Dj[rx].parent = ry;
		if(Dj[rx].rank == Dj[ry].rank)
			Dj[ry].rank = Dj[ry].rank + 1;
	}
}

int findSet(struct Dset *Dj,int x)
{
	if(Dj[x].parent!=x)
		Dj[x].parent = findSet(Dj,Dj[x].parent);
	
	return Dj[x].parent;
}
