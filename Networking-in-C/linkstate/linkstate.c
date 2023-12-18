#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
struct nodes 
{
	int distance;
	int parent;
	int visited;
};
int getMin(struct nodes node[50],int no_of_nodes)
{
	int min;
	for (int i=0;i<no_of_nodes;i++)
	{
		if(node[i].visited!=1)
		{
			min = i;
			break;
		}
	}
	for (int i=0;i<no_of_nodes;i++)
	{
		if(node[min].distance>node[i].distance && node[i].visited!=1)
		{
			min = i;
		}
	}
	return min;
}
int main()
{
	int no_of_routers;
	printf("Enter the number of routers.\n");
	scanf("%d",&no_of_routers);
	int cost[no_of_routers][no_of_routers];
	printf("Enter the cost matrix.\n");
	for(int i=0;i<no_of_routers;i++)
	{
		for(int j =0;j<no_of_routers;j++)
		{
			scanf("%d",&cost[i][j]);
		}
	}
	struct nodes node[no_of_routers];
	for(int i=0;i<no_of_routers;i++)
	{
		for(int j=0;j<no_of_routers;j++)
		{
			node[j].distance = 999;
			node[j].visited = 0;
			node[j].parent = 999;
		}
		node[i].distance = 0;
		node[i].parent = i;
		int sum_visited = 0;
		while(sum_visited<no_of_routers)
		{	
			sum_visited++;
			int min_node = getMin(node,no_of_routers);
			node[min_node].visited =1;
			for(int j =0;j<no_of_routers;j++)
			{
				if(node[j].distance>node[min_node].distance+cost[min_node][j] && cost[min_node][j]!=999 && node[j].visited!=1)
				{
					node[j].distance = node[min_node].distance+cost[min_node][j];
					node[j].parent = min_node;	
				}
			}
		}
		printf("Routing table for %d\n",i);
		for(int j =0;j<no_of_routers;j++)
		{
			printf("Distance %d and parent %d\n",node[j].distance,node[j].parent);
		}
		
		
	}
	
}

