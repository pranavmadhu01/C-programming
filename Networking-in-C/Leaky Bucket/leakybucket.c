#include<stdio.h>
#include<unistd.h>
int main()
{
	int no_of_packets,bucket_capacity,deduction_value;
	printf("Enter the number of packets\n");
	scanf("%d",&no_of_packets);
	int packets[no_of_packets];
	printf("Enter the packets in order to enter the bucket.\n");
	for(int i=0;i<no_of_packets;i++)
	{
		scanf("%d",&packets[i]);
	}
	printf("Enter the bucket capacity.\n");
	scanf("%d",&bucket_capacity);
	printf("Enter the deduction value.\n");
	scanf("%d",&deduction_value);
	int filled = packets[0];
	int pointer =1;
	while(filled>0)
	{
		if( pointer < (no_of_packets) && packets[pointer]<(bucket_capacity-filled))
		{
			filled +=packets[pointer];
			pointer ++;
		}
		printf("Now the bucket contains%d\n",filled);
		if(filled>=deduction_value)
		{
			sleep(1);
			printf("The deduction of %d is done from the bucket\n",deduction_value);
			filled = filled-deduction_value;
		}
		else
		{
			printf("Insufficient packet size available in the bucket.\n");
			printf("The deduction of %d is done from the bucket\n",deduction_value-filled);
			filled = 0;
			break;
		}
	}
}
