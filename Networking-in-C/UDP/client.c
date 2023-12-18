#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netdb.h>
#include<unistd.h>

int main()
{
	int clientsocketnumber,PORT = 8000;
	struct sockaddr_in serveraddr;
	socklen_t serverlen;
	serverlen = sizeof(serveraddr);
	clientsocketnumber  = socket(AF_INET,SOCK_DGRAM,0);
	printf("The client socket descriptor is %d\n",clientsocketnumber);
	memset(&serveraddr,0,serverlen);
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(PORT);
	serveraddr.sin_addr.s_addr = INADDR_ANY;
	sendto(clientsocketnumber,"Hello",sizeof("Hello"),0,(struct sockaddr*)&serveraddr,serverlen);
	//up to simple message sending part
	//staring sum of the array program
	char size[10];
	char message[100];
	printf("Enter the size of the array to be summed.\n>>>");
	scanf("%s",size);
	sendto(clientsocketnumber,size,sizeof(size),0,(struct sockaddr*)&serveraddr,serverlen);
	int i = atoi(size);
	while(i!=0)
	{
		printf("Enter the element of the array to be summed.\n>>>");
		scanf("%s",message);
		sendto(clientsocketnumber,message,sizeof(message),0,(struct sockaddr*)&serveraddr,serverlen);
		i--;
	}
	recvfrom(clientsocketnumber,message,sizeof(message),0,(struct sockaddr*)&serveraddr,&serverlen);
	printf("The sum of the array is %s\n",message);
	//end of sum of array program
	//starting of string reversal program
	printf("Enter the string to be reversed.\n>>>");
	scanf("%s",message);
	sendto(clientsocketnumber,message,sizeof(message),0,(struct sockaddr*)&serveraddr,serverlen);
	recvfrom(clientsocketnumber,message,sizeof(message),0,(struct sockaddr*)&serveraddr,&serverlen);
	printf("The reversed string is %s\n",message);
	//end of string reversal program
	
	
	
	
}
