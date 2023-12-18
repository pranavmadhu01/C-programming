#include<stdio.h>
#include<string.h>
struct closures
{
	char state[20];
	int length;
	char closure[20][20];
}close[20];
int main()
{
	FILE *f1 = fopen("input.txt","r");
	int n,a_n;
	char alp[20];
	printf("Enter the number of alphabets.\n");
	scanf("%d",&a_n);
	printf("Enter the alphabets.\n");
	for(int i=0;i<a_n;i++)
	{
		scanf(" %c",&alp[i]);
	}
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
		
		strcpy(close[i].state,states[i]);
		printf("Epsilon closure of %s is : ",close[i].state);
		close[i].length = idx;
		printf("{");
		for(int j=0;j<idx;j++)
		{
			strcpy(close[i].closure[j],buffer[j]);
			printf("%s",close[i].closure[j]);
		}
		printf("}");
		printf("\n");
		rewind(f1);
		
		
	}
	for(int i=0;i<n;i++)
	{
		int length = close[i].length;
		for(int j=0;j<a_n;j++)
		{
			idx=0;
			char c_alp[20];
			c_alp[0] = alp[j];
			c_alp[1] = '\0';
			for(int k=0;k<length;k++)
			{
				char from[10],state[10],to[10];
				while(fscanf(f1,"%s %s %s",from,state,to)!=EOF)
				{
					if (strcmp(from,close[i].closure[k])==0 && strcmp(c_alp,state)==0)
					{
						for(int l=0;l<n;l++)
						{
							if(strcmp(to,close[l].state)==0)
							{
								int flag=0;
								for(int m=0;m<close[l].length;m++)
								{
									strcpy(buffer[idx++],close[l].closure[m]);	
								}
							}
						}
					}
				
				}
				rewind(f1); 
			}
			printf("NFA of %s on alphabet %c : ",close[i].state,alp[j]);
			printf("{");
			for(int k=0;k<idx;k++)
			{
				printf("%s",buffer[k]);
			}
			printf("}");
			printf("\n");	
		}
		
	}
	
	return 0;
}

