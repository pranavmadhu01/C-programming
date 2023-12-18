#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netdb.h>
#include<unistd.h>

int main()
{
	int clientsocketnumber,serversocketnumber,PORT = 8000;
	struct sockaddr_in serveraddr,clientaddr;
	socklen_t serverlen,clientlen;
	serverlen = sizeof(serveraddr);
	clientlen = sizeof(clientaddr);
	serversocketnumber = socket(AF_INET,SOCK_DGRAM,0);
	printf("The server socket descriptor is %d\n",serversocketnumber);
	memset(&serveraddr,0,serverlen);
	memset(&clientaddr,0,clientlen);
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(PORT);
	serveraddr.sin_addr.s_addr = INADDR_ANY;
	int bindnumber = bind(serversocketnumber,(struct sockaddr*)&serveraddr,serverlen);
	char message[100];
	recvfrom(serversocketnumber,message,sizeof(message),0,(struct sockaddr*)&serveraddr,&serverlen);
	printf("The message received is %s\n",message);
	//up to simple message receiving part
	//staring of sum of array program
	int sum = 0;
	char size[10];
	recvfrom(serversocketnumber,size,sizeof(size),0,(struct sockaddr*)&serveraddr,&serverlen);
	int i = atoi(size);
	while(i!=0)
	{
		recvfrom(serversocketnumber,message,sizeof(message),0,(struct sockaddr*)&serveraddr,&serverlen);
		sum = sum + atoi(message);
		i--;
	}
	sprintf(message,"%d",sum);
	sendto(serversocketnumber,message,sizeof(message),0,(struct sockaddr*)&serveraddr,serverlen);
	//end of sum of array program
	//starting of string reversal program
	recvfrom(serversocketnumber,message,sizeof(message),0,(struct sockaddr*)&serveraddr,&serverlen);
	int start = 0;
	int end = strlen(message)-1;
	while(start<end)
	{
		char temp = message[start];
		message[start] = message[end];
		message[end] = temp;
		start++;
		end--;
	}
	sendto(serversocketnumber,message,sizeof(message),0,(struct sockaddr*)&serveraddr,serverlen);
	//end of string reversal logic
	
	
	
	
	
	
	 
}
