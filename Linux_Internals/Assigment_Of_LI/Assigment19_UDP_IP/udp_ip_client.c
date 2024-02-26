/* 
  Name : Sk Sahil
  Assigment NO : 19
  Assigment : Implement Remote command execution using UDP sockets
  Pre-requisites:
	Knowledge about system calls, How to read and understand ‘man pages’. 
	Good knowledge about File I/O
	Good knowledge about UDP/IP Protocol
  Objective: 
	The idea is to understand Remote command execution using UDP socket
  Requirements: 
	Create  a Server and Client Program 
	Send command & number of executions from Client to Server
	Server execute the command and store output in a file
	Read data from file and and Send to client
	Client sends acknowledgement back. 
	Stop communication at EOF and flag 0.
  Sample execution:
	$ ./udp_server & (Running server in background)
		[123423]
	$ ./udp_client
	Enter any standard LS command :  date
	Enter no.of times to be executed :  3
	Wed Apr 28 13:27:19 IST 2020
	Wed Apr 28 13:27:19 IST 2020
	Wed Apr (64 bytes of 1th packet received from server, sending ack)
	28 13:27:19 IST 2020 (20 bytes of 2th packet received from server,sending ack)﻿

  Date of Submission : 14/01/2023
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>		
#include <arpa/inet.h>

#define SERVER_IP 	"127.0.0.1"
#define	SERVER_PORT	5001
#define SERVER_LENGTH	10
#define CLIENT_BUFF	64

int main()
{
	int sock_fd;
	int c_size;

	struct sockaddr_in serv_addr;
	char client_buffer[CLIENT_BUFF];
	int num;

	printf("Client requesting ....\n");
	
	//create a client UDP Socket
	if( (sock_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) 
	{
		printf("Error: Could not create socket");
		return 1;
	}

	//binding with client socket is optional here

	//populate it with server's adress details
	//order is imp
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(SERVER_PORT);
	serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
	
	//get the message from the client
	printf("Enter the data to be sent to the server : ");
        fgets(client_buffer, CLIENT_BUFF, stdin);
	printf("Enter the data Number of time : ");
        scanf("%d",&num);
	
	//send the data to the server
	c_size = sendto(sock_fd, (void *)&client_buffer, CLIENT_BUFF, 0, (struct sockaddr*) &serv_addr, sizeof(serv_addr));

/*	if(c_size)
	{
		printf("Connection successful\nMessage sent to server successfully, please check\n");
	}
	else
	{
		printf("Error : Message send failed\n");
	}
*/
	c_size = sendto(sock_fd, (void *)&num, sizeof(int), 0, (struct sockaddr*) &serv_addr, sizeof(serv_addr));

/*	if(c_size)
	{
		printf("Connection successful\nMessage sent to server successfully, please check\n");
	}
	else
	{
		printf("Error : Message send failed\n");
	}
*/	
	int serv_len = sizeof(struct sockaddr_in);
	int r_size;
	int bit_pack = 0;
	int ack = 0;
	for(int i = 0; i < num;i++)
	{
		r_size = recvfrom(sock_fd, (void *)client_buffer, CLIENT_BUFF, 0, (struct sockaddr *)&serv_addr, &serv_len);
		
	//	printf("Recive from server %s\n",client_buffer);
		
		system(client_buffer);
	
		bit_pack += r_size;
		
		if(bit_pack == 64)
		{
			printf("[ %d bytes of %dth packet received from server, sending ack ]\n",bit_pack,ack++);
			bit_pack = 0; 	
		}
	}
	printf("[ %d bytes of %dth packet received from server, sending ack ]\n",bit_pack,ack++);
	
	//close the sockets now
	close(sock_fd);
}
