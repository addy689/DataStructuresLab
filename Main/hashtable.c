#include "../Libraries/HashLib/hashlib.h"

int main(int argc,char *argv[])
{
	char c,x;
	int i,ch;
	char str[size];
	FILE *fs;
	
	struct Node *H[m];
	
	if(argc!=2)
	{
		printf("\nImproper no. of arguments!!\n");
		return 1;
	}
	
	for(i=0;i<m;i++)
		H[i] = NIL;
	
	do
		{
			printf("\n-------MENU--------\n\n");
			printf("1.) Read source file\n");
			printf("2.) Display Hash Table\n");
			printf("3.) Delete data from the Hash Table\n");
			printf("\nEnter choice (1-3): ");
			scanf("%d",&ch);
			
			switch(ch)
			{
				case 1:		fs = fopen(argv[1],"r");
							
							if(fs==NULL)
							{
								printf("\nCannot open file!!\n");
								return 1;
							}
							
							while(fscanf(fs,"%s",str)!=EOF)
							{
								printf("\n%s",str);
								parse(H,str);
							}
							fclose(fs);
							break;
				
				case 2:		displayTable(H);
							break;
				
				case 3:		printf("\nInput string to delete: ");
							scanf("%s",str); 
							deleteData(H,str);
							break;
				
				default: c='n';
			}

			printf("\n\nDo you want to go back to menu? (Y/N) - ");
			scanf("%c",&c);
			scanf("%c",&c);
			
		}while(c=='Y' || c=='y');

		return 0;
}
