#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<netdb.h>
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
	 while(1)
	 {
	 	recvfrom(serversocketnumber,message,sizeof(message),0,(struct sockaddr*)&clientaddr,&clientlen);
	 	printf("The data received  from client is %s\n",message);
	 	printf("Should we give acknowledgement?\nType\n1 for 'Yes'\n2 for 'No'\n");
	 	int selection;
	 	scanf("%d",&selection);
	 	switch(selection)
	 	{
	 		case 1:
		 		sendto(serversocketnumber,"Acknowledged",sizeof("Acknowledged"),0,(struct sockaddr*)&clientaddr,clientlen);
		 		break;
	 		case 2:
		 		sendto(serversocketnumber,"Not Acknowledged",sizeof("Not Acknowledged"),0,(struct sockaddr*)&clientaddr,clientlen);
		 		break;
	 	}	
	 }
}
