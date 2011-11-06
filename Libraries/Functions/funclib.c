#include "funclib.h"

//GENERAL
void swap(int* p,int* q)
{
    int tmp;
    
    tmp=*p;
    *p=*q;
    *q=tmp;
}

//BINARY TREE
int left(int i)
{
    return 2*i;
}

int right(int i)
{
    return 2*i+1;
}

int parent(int j)
{
    return j/2;
}
