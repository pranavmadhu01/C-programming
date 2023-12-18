#include<stdio.h>
#include<string.h>
int main()
{
	FILE *f1 = fopen("input.txt","r");
	int n;
	printf("Enter the number of states.\n");
	scanf("%d",&n);
	char states[20][20];
	printf("Enter the states\n");
	for(int i=0;i<n;i++)
	{
		scanf("%s",states[i]);
	}
	char buffer[20][20];
	int idx = 0;
	for(int i=0;i<n;i++)
	{
		idx=0;
		char from[10],state[10],to[10],current_state[20];
		strcpy(buffer[idx++],states[i]);
		strcpy(current_state,states[i]);
		while(fscanf(f1,"%s %s %s",from,state,to)!=EOF)
		{
			if (strcmp(from,current_state)==0 && strcmp(state,"e")==0)
			{
				strcpy(buffer[idx++],to);
				strcpy(current_state,to); 
			}
				
		}
		printf("Epsilon closure of %s is : ",states[i]);
		printf("{");
		for(int j=0;j<idx;j++)
		{
			printf("%s",buffer[j]);
		}
		printf("}");
		printf("\n");
		rewind(f1);
		
		
	}
	return 0;
}

