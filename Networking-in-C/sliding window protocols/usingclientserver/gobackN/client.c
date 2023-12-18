#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<netdb.h>
struct frames
{
	char value[10];
};
int main()
{
	 int clientsocketnumber,PORT=8000;
	 struct sockaddr_in serveraddr;
	 socklen_t serverlen;
	 char message[100];
	 clientsocketnumber = socket(AF_INET,SOCK_DGRAM,0);
	 printf("The socket number for the server is %d\n",clientsocketnumber);
	 serverlen = sizeof(serveraddr);
	 memset(&serveraddr,0,serverlen);
	 serveraddr.sin_family = AF_INET;
	 serveraddr.sin_port = htons(PORT);
	 serveraddr.sin_addr.s_addr = INADDR_ANY;
	 char no_of_frames[10];
	 char window_size[10];
	 printf("Enter the number of frames\n");
	 scanf("%s",no_of_frames);
	 struct frames f[atoi(no_of_frames)];
	 printf("Enter the window size.\n");
	 scanf("%s",window_size);
	 sendto(clientsocketnumber,window_size,sizeof(window_size),0,(struct sockaddr*)&serveraddr,serverlen);
	 sendto(clientsocketnumber,no_of_frames,sizeof(no_of_frames),0,(struct sockaddr*)&serveraddr,serverlen);
	 printf("Enter the frame numbers\n");
	 for(int i=0;i<atoi(no_of_frames);i++)
	 {
	 	scanf("%s",f[i].value);
	 }
	 int acknowledgement_count = 0;
	 int start=0;
	 int end = start+atoi(window_size);
	 for(int i=start;i<end;i++)
	 {
	 	sendto(clientsocketnumber,f[i].value,sizeof(f[i].value),0,(struct sockaddr*)&serveraddr,serverlen);
	 }
	 while (acknowledgement_count<atoi(no_of_frames))
	 {
		 recvfrom(clientsocketnumber,message,sizeof(message),0,(struct sockaddr*)&serveraddr,&serverlen);
		 if (!strcmp(message,"Acknowledged"))
		 {
		 	printf("Received Acknowledgement\n");
		 	start++;
		 	if(end!=atoi(no_of_frames))
		 	{
		 		printf("Window shifting...\n");
		 		end = start+atoi(window_size);
		 		sendto(clientsocketnumber,f[end-1].value,sizeof(f[end-1].value),0,(struct sockaddr*)&serveraddr,serverlen);
		 	}
		  	acknowledgement_count++;
		  	
		 }
		 else
		 {
		 	printf("Resending frames in the window..\n");
		 	for(int i=start;i<end;i++)
		 	{
		 		printf("Resending the frame %s\n",f[i].value);
		 	}
		 }
 	
 	}
}
