#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	int no_of_frames,window_size;
	printf("Enter the number of frames.\n");
	scanf("%d",&no_of_frames);
	printf("Enter the window size.\n");
	scanf("%d",&window_size);
	int start = 0;
	while(start<no_of_frames)
	{	
		printf("Present window content.\n");
		for(int j=start;j<start+window_size && j<no_of_frames;j++)
		{
			printf("%d",j);
			sleep(0.5);	
		}
		printf("\n");
		for(int j=start;j<start+window_size && j<no_of_frames;j++)
		{
			printf("Sending the present window content (frames)....\n");
			sleep(0.5);
		}
		int ifnack = rand()%2;
		if(ifnack)
		{
			sleep(1);
			int selectedonetonack;
			if(start+window_size<no_of_frames)
			{
				selectedonetonack = rand()%window_size;
			}
			else
			{
				selectedonetonack = rand()%(start+window_size-no_of_frames);
			}
			printf("The frame %d have a negative ack\n",selectedonetonack+start);
			printf("Should resend..\n");
		}
		else
		{
			printf("The cumulative acknowledgement is being send.\n");
			start = start+window_size;
		}
	}
}
