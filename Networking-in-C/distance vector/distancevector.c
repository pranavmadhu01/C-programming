#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
struct nodes
{
	int adjNode[100];
};
int main()
{
	int no_of_routers;
	printf("Enter the number of routers.\n");
	scanf("%d",&no_of_routers);
	int cost[no_of_routers][no_of_routers];
	printf("Enter the cost matrix.\n");
	struct nodes node[no_of_routers];
	for(int i=0;i<no_of_routers;i++)
	{
		for(int j=0;j<no_of_routers;j++)
		{
			scanf("%d",&cost[i][j]);
			node[i].adjNode[j] = j;
			
		}	
	}
	for(int k =0;k<no_of_routers;k++)
	{
		for(int i =0;i<no_of_routers;i++)
		{
			for(int j =0;j<no_of_routers;j++)
			{
				if(cost[i][j]>cost[i][k]+cost[k][j])
				{
					cost[i][j] = cost[i][k]+cost[k][j];
					node[i].adjNode[j] = k;
				}
			}	
		}	
	}
	for(int i=0;i<no_of_routers;i++)
	{	
		printf("ROUTER NO %d\n",i);
		for(int j=0;j<no_of_routers;j++)
		{
			printf("To ROUTER %d via %d with a DISTANCE of %d\n",j,node[i].adjNode[j],cost[i][j]);	
		}
	}
	
	
}
