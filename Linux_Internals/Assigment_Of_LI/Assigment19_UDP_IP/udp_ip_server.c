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

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/stat.h>

#define SERVER_IP     "127.0.0.1"
#define SERVER_PORT   5001
#define SERVER_LENGTH 20
#define SERVER_BUFF   64

int main()
{
	// variable decleration
	int sock_fd, buffer_len, client_len;
	struct sockaddr_in serv_addr;
	struct sockaddr_in client_addr;

	char buffer[SERVER_BUFF];
	int num;
	
	printf("Server is Weating ...\n");
	
	// creat UDP/IP socket
	if((sock_fd = socket(AF_INET,SOCK_DGRAM,0)) < 0)
	{
		perror("socket");
		exit(1);
	}
	
	//bind it to a particular IP address & port
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
	serv_addr.sin_port = htons(SERVER_PORT);
	
	bind(sock_fd, (struct sockaddr*) &serv_addr, sizeof(serv_addr));

	//Try to get some actual data ffrom client i.e receive a message from a socket
	client_len = sizeof(struct sockaddr_in);	
	recvfrom(sock_fd, (void *)buffer, SERVER_BUFF, 0, (struct sockaddr *)&client_addr, &client_len);
	recvfrom(sock_fd, (void *)&num, sizeof(int), 0, (struct sockaddr *)&client_addr, &client_len);

	//print the data received from client
	printf("Client data:  %s\n", buffer);
	printf("No of times %d\n",num);

	int fd = open("file.txt",O_CREAT | O_RDWR,0664); // open the file write mode
	int bit_pack = 0;
	int c_size,str_cpy;
	str_cpy = dup2(fd,1); // redirect the std out
	char buf[64];
	
	strcpy(buf,buffer);

	for(int i = 0; i < num;i++)
	{
		system(buffer);
		c_size = sendto(sock_fd, (void *)buf,strlen(buf), 0, (struct sockaddr*)&client_addr, sizeof(client_addr));
		
	}
	
	close(fd);
	
	//close the sockets now
	close(sock_fd);
	
}
