#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<netdb.h>
int main()
{
	 int clientsocketnumber,PORT = 8000;
	 struct sockaddr_in serveraddr;
	 socklen_t serverlen;
	 char message[100];
	 char status[100];
	 clientsocketnumber = socket(AF_INET,SOCK_DGRAM,0);
	 printf("The serversocket number in the client side is %d\n",clientsocketnumber);
	 serverlen = sizeof(serveraddr);
	 memset(&serveraddr,0,serverlen);
	 serveraddr.sin_family = AF_INET;
	 serveraddr.sin_port = htons(PORT);
	 serveraddr.sin_addr.s_addr  = INADDR_ANY;
	 printf("Enter the number of data to be acknowledged\n");
	 int number_of_data,i=1,sending_flag=0;
	 scanf("%d",&number_of_data);
	 while(i<=number_of_data)
	 {
	 	switch(sending_flag)
	 	{
	 		case 0:
		 		printf("Enter the data to be send\n");
		 		scanf("%s",message);
		 		sendto(clientsocketnumber,message,sizeof(message),0,(struct sockaddr*)&serveraddr,serverlen);
		 		recvfrom(clientsocketnumber,status,sizeof(status),0,(struct sockaddr*)&serveraddr,&serverlen);
		 		if(!strcmp(status,"Acknowledged"))
		 		{
		 			printf("%s\n",status);
		 			i++;
		 			continue;
		 		}
		 		else
		 		{
		 			printf("%s\n",status);
		 			sending_flag=1;
		 		}
		 		break;
	 		case 1:
		 		printf("resending...\n");
		 		printf("%s\n",status);
		 		sendto(clientsocketnumber,message,sizeof(message),0,(struct sockaddr*)&serveraddr,serverlen);
		 		recvfrom(clientsocketnumber,status,sizeof(status),0,(struct sockaddr*)&serveraddr,&serverlen);
		 		if(!strcmp(status,"Acknowledged"))
		 		{
		 			i++;
		 			sending_flag=0;
		 			continue;
		 		}
		 		break;
	 		
	 	}
	 }
}
