#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int no_of_packets,bucket_capacity,deduction_rate;
	printf("Enter the no of packets.\n");
	scanf("%d",&no_of_packets);
	int packets[no_of_packets];
	printf("Enter the size of each packets.\n");
	for(int i=0;i<no_of_packets;i++)
	{
		scanf("%d",&packets[i]);
	}
	printf("Enter the bucket capacity.\n");
	scanf("%d",&bucket_capacity);
	printf("Enter the deduction rate.\n");
	scanf("%d",&deduction_rate);
	int i = 0;
	int filled = packets[0];
	printf("The bucket got filled with %d and the remaining capacity is %d\n",packets[0],bucket_capacity-filled);
	int j = 1;
	while(filled!=0)
	{	
		while(j<no_of_packets)
		{
			if((bucket_capacity - filled)>=packets[j])
			{
				filled = filled + packets[j];
				printf("The bucket got filled with %d and the remaining capacity is %d\n",packets[j],bucket_capacity-filled);
				j++;	
			}
			else
			{
				printf("Overflow !!! maximum capacity for bucket reached\n");
				break;
			}
		}
		if(filled<deduction_rate)
		{
			printf("The deduction of %d has happened and the remaining bucket capacity is %d\n",filled,bucket_capacity);
			filled = 0;
		}
		else
		{
		
			printf("The deduction of %d has happened and the remaining bucket capacity is %d\n",deduction_rate,bucket_capacity-filled+deduction_rate);
			filled = filled - deduction_rate;
		}
	}
}
