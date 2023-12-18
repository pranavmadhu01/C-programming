#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<netdb.h>
struct window
{
	char value[100];
};
int main()
{
	 int serversocketnumber,PORT=8000;
	 struct sockaddr_in serveraddr, clientaddr;
	 socklen_t serverlen,clientlen;
	 char message[100];
	 serversocketnumber = socket(AF_INET,SOCK_DGRAM,0);
	 printf("The socket number for the server is %d\n",serversocketnumber);
	 serverlen = sizeof(serveraddr);
	 memset(&serveraddr,0,serverlen);
	 serveraddr.sin_family = AF_INET;
	 serveraddr.sin_port = htons(PORT);
	 serveraddr.sin_addr.s_addr = INADDR_ANY;
	 int bindnumber = bind(serversocketnumber,(struct sockaddr*)&serveraddr,serverlen);
	 printf("The bind number is %d\n",bindnumber);
	 clientlen = sizeof(clientaddr);
	 char window_size[10];
	 char frame_size[10];
	 recvfrom(serversocketnumber,window_size,sizeof(window_size),0,(struct sockaddr*)&clientaddr,&clientlen);
	 printf("The window size  received is %s\n",window_size);
	 recvfrom(serversocketnumber,frame_size,sizeof(frame_size),0,(struct sockaddr*)&clientaddr,&clientlen);
	 printf("The frame size  received is %s\n",frame_size);
	 struct window w[atoi(window_size)];
	 int receival_count =0;
	 int enqueue_flag = 0; 
	 while(1)
	 {
	 	if(receival_count<atoi(window_size))
	 	{
	 		if(receival_count<atoi(frame_size))
	 		{
		 		recvfrom(serversocketnumber,message,sizeof(message),0,(struct sockaddr*)&clientaddr,&clientlen);
		 		printf("The data received  from client is %s\n",message);
	 		}
	 		strcpy(w[receival_count].value,message);
	 		receival_count++;
	 	}
	 	else
	 	{
	 		printf("Should we give acknowledgement for frame number %s?\nType\n1 for 'Yes'\n2 for 'No'\n",w[0].value);
	 		int selection;
	 		scanf("%d",&selection);
	 		switch(selection)
	 		{
		 		case 1:
		 			sendto(serversocketnumber,"Acknowledged",sizeof("Acknowledged"),0,(struct sockaddr*)&clientaddr,clientlen);
		 			enqueue_flag=1;
		 			break;
		 		case 2:
		 			sendto(serversocketnumber,"Not Acknowledged",sizeof("Not Acknowledged"),0,(struct sockaddr*)&clientaddr,clientlen);
		 			for (int i =0;i<atoi(window_size);i++)
			 		{
			 			printf("Received the frame number %s\n",w[i].value);
			 		}
		 			break;
	 		}
	 		if(enqueue_flag!=0)
	 		{
	 			if(receival_count<atoi(frame_size))
	 			{
			 		recvfrom(serversocketnumber,message,sizeof(message),0,(struct sockaddr*)&clientaddr,&clientlen);
			 		printf("The data received  from client is %s\n",message);
	 			}
		 		for (int i=1;i<atoi(window_size);i++)
		 		{
		 			strcpy(w[i-1].value,w[i].value);
		 		}
	 			if(receival_count<atoi(frame_size))
	 			{
	 				strcpy(w[atoi(window_size)-1].value,message);
	 			}
	 			else
	 			{
	 				strcpy(w[atoi(window_size)-1].value,"#");
	 			}
	 			enqueue_flag=0;
	 			receival_count++;
	 		}
	 	
	 	}
	 	
	 	
	 		
	 }
	 
	 
	}
