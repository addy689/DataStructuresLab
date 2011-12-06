/**
* Sample main program to demonstrate B-Tree operations 

*This program uses the following Libraries. Uncomment these libraries in the file MAKEFILE before running this program (refer to MAKEFILE for instructions on executing this program) -

*	gcc -c ../Libraries/ShPathLib/shpathlib.c


*/

#include <string.h>
#include <ctype.h>

#include "../Libraries/BTreeLib/btreelib.h"
#define SIZE 255

int isName(char *s)
{
	if(isalpha(s[0]))
		return 1;
}

int main(int argc, char *argv[])
{
	char str[SIZE],c,arr[50][100];
	int t,ch,len;
	int i,j,k;
	FILE *fp;

	if (argc < 2)
	{
		printf ("\nError..!!\nInput text filename missing.!!\n");
		exit(1);
	}
	
	printf("\nInput t: ");
	scanf("%d",&t);	

	btreeCreate();
	
	do
		{
			printf("\n-------MENU--------\n\n");
			printf("1.) Read from File\n");
			printf("2.) Display the root node\n");
			printf("3.) Visit all the nodes of the tree in Preorder, and list the depth and the keys for each node\n");
			printf("\nEnter choice (1-4): ");
			scanf("%d",&ch);
			
			switch(ch)
			{
				case 1:		fp = fopen(argv[1],"r"); 					

							while (fgets(str,SIZE,fp) != NULL)
							{
								len=strlen(str);
								j=0;
								for(i=0;i<len;i++)
								{
									while(isalnum(str[i]))
									{
										arr[j][k]=str[i];
										k++;

										if(!isalnum(str[i]))
										{
											arr[j][k]='\0';
											j++;
											k=0;
										}
									}
								}

								for(i=1;i<j;i++)
								{
									if(strcmp(arr[i-1],"void")==0 || strcmp(arr[i-1],"int")==0 || strcmp(arr[i-1],"float")==0 || strcmp(arr[i-1],"struct")==0)
									{
										if(strcmp(arr[i-1],"struct")==0)
											strcpy(str,arr[i+1]);
																					
										else
											strcpy(str,arr[i]);

										if(isName(str));
												btreeInsert(str);

										break;
									}
								}
							}
								
							fclose(fp);
							break;
				
				case 2:		displayNode(root);
							break;
				
				case 3:		printf("\n***LIST IF NODES***\n");
							listKeys(root);	

				case 4:		break;
				
				default: c='n';
			}

			printf("\n\nDo you want to go back to menu? (Y/N) - ");
			scanf("%c",&c);
			scanf("%c",&c);
			
		}while(c=='Y' || c=='y');

		return 0;
}
