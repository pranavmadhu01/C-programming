#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int no_of_frames;
	printf("Enter the number of frames.\n");
	scanf("%d",&no_of_frames);
	int start = 0;
	while(start<no_of_frames)
	{
		printf("The FRAME %d is send\n",start);
		int shouldack = rand()%2;
		sleep(2);
		if(shouldack)
		{
			printf("Frame %d is acknowledged.\n",start);
			start++;
		}
		else
		{
			printf("FRAME %d is not acknowledged.\n",start);
			printf("Resending....\n");
		}
	}
	return 0;
}
