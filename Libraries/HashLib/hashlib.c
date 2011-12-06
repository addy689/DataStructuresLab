/**
* This file contains function definitions for handling Hash Table (with collision resolution using "Chaining" method) related operations 
*/

#include "hashlib.h"

void insertData(struct Node **H, char *str)
{
	int k,flag;
	
	k = hashData(str[0]);
	flag = 0;
	
	struct Node *ptr;
	ptr = searchChain(H,k,str,&flag);
	
	if(ptr!=NIL)
	{
		if(flag!=1)
			ptr = ptr->next;
			
		(ptr->ct)++;
	}
	
	else
	{
		struct Node *N;
		allocateNode(&N,strlen(str));
	
		strcpy(N->data,str);		//input data is copied into the new node
		N->next = H[k];			//first node in the existing chain is assigned as the next node to the new node
	
		H[k] = N;					//new node is inserted at the Head of the chain
	}
}

int hashData(char ch)
{
	ch = toupper(ch);
	return ch%m;
}

void allocateNode(struct Node ** M,int len)
{
	(*M) = malloc(sizeof(struct Node));
	(*M)->ct = 1;
	(*M)->data = malloc(sizeof(char)*len);
	(*M)->next = NIL;
}

void deleteData(struct Node ** H,char *del)
{
	int k,flag;
	
	k = hashData(del[0]);
	flag = 0;
	
	struct Node *ptr,*nptr;
	ptr = searchChain(H,k,del,&flag);
	
	if(ptr!=NIL)
	{
			if(flag==1)
			{
					if((ptr->ct)==1)
					{
						H[k] = ptr->next;
						free(ptr);
					}
			
					else
						(ptr->ct)--;
			}
		
			else
			{
					nptr = ptr->next;
			
					if(nptr->ct==1)
					{
						ptr->next = nptr->next;
						free(nptr);
					}
			
					else
						(nptr->ct)--;
			}
			
			printf("\nAn item has been deleted!");
	}
	
	else
		printf("\nThe item was not found!!");
}

void displayTable(struct Node ** H)
{
	int i;
	struct Node *ptr;
	 
	printf("\n\n--- Hash Table ---\n");
	for(i=0;i<m;i++)
	{
		printf("\n%d ->",i);
		
		ptr = H[i];
		while(ptr!=NIL)
		{
			printf("\t%s(%d)",ptr->data,ptr->ct);
			ptr = ptr->next;
		}
	}
}

struct Node* searchChain(struct Node ** H,int k,char *str,int *flag)
{
	struct Node *loc,*nextloc;
	loc = H[k];
	
	if(loc!=NIL)
	{
		if(!strcmp(loc->data,str))
		{
			(*flag) = 1;
			return loc;
		}
	}
	
	while(loc!=NIL)
	{
		nextloc = loc->next;
		if(nextloc!=NIL)
			if(!strcmp(nextloc->data,str))
				return loc;
		
		loc = loc->next;
	}
	
	return loc;
}

void parse(struct Node ** H,char *str)
{
	int i,j,flg;
	char S[30];
	
	i = 0;
	j = 0;
	flg = 0;
	while(str[i]!='\0')
	{
		while(isalnum(str[i]))
		{
			S[j] = str[i];
			j++;
			i++;
			
			if(str[i]=='\0')
			{
				flg = 1;
				break;
			}
		}
		
		if(j!=0)
		{
			S[j] = '\0';
			
			if(isalpha(S[0]))
				insertData(H,S);
			
			j = 0;
		}
		
		if(flg==1)
			break;
		
		i++;
	}
}
