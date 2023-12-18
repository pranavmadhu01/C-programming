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
		printf("The present window content.\n");
		for(int i = start;i<start+window_size && i<no_of_frames;i++)
		{
			printf("%d",i);
		}
		for(int i = start;i<start+window_size && i<no_of_frames;i++)
		{
			printf("Sending the frames in the widow.\n");
		}
		for(int i = start;i<start+window_size && i<no_of_frames;i++)
		{
			sleep(2);
			int choice = rand()%3;
			if(choice==0)
			{
				printf("The frame %d is acknowledged.\n",i);
				start++;
			}
			else if (choice==1)
			{
				printf("The frame %d is not acknowledged.\n",i);
				printf("Resending...\n");
				break;
			}
			else
			{
				printf("Timeout occured\n");
				printf("Resending...\n");
				break;
			}
		}
		
	}
}
