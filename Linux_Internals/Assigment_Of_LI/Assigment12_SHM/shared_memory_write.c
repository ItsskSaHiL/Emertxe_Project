/*
  Name : Sk Sahil
  Assigment : A12 - Implement communication between two different processes using SHM
  Date of Submission : 11/01/2023
  Pre-requisites:- 
	Knowledge about system calls, How to read and understand ‘man pages’.
	Good knowledge about Shared memory 
  Objective: 
	To understand how to establish communication between 2 different process.
  Requirements: 
	Create 2 different process by executing 2 different a.out (executable) file’s
	Create SHM from any of the process. Either Process 1 or Process 2
	In process 1 
	Prompt the user to enter a string 
	Convert the string into Upper case
	Write the Upper case string  in shared memory
	4.In process 2

	Read the data from the shared memory 
	Reverse input which is read from SHM
	Write the Reverse string  in shared memory
	5.Read the data from shared memory in process 1
	6.Print the output string on stdout
	Sample output :

	Run the two process executable in two different tabs 

	1. ./Process1 

	Enter the string: Hello

	Writing to shared memory ......
	
	Reading from shared memory:  OLLEH

	2. ./Process 2

	Reading from shared memory :olleh

	Writing to Shared memory ...
*/
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>


/* Define the shared memory size */
#define SMSIZE 100
// function prototype;
void convert_to_uppercase(char* s);
void strrev(char* s, char size, char iter);

int main()
{
	// variable decleration
   	int shmid;
	char data[20] = {'\0'};		
	char *shm,*shm2;
    	key_t key;

	// read the input	
	printf("Enter the String : ");
    	scanf("%[^\n]s",data);

	// convert into upper case
	convert_to_uppercase(data);

	/* Key can be hardcoded, but use the same in reader & writer */
    	key = 'B';


    	/* Create a shared memory */
	shmid = shmget(key,SMSIZE,IPC_CREAT | 0666);

   	if (shmid < 0)
    	{
    		perror("shmget");
    		exit(1);
    	}
    	else
	{
    		shm = shmat(shmid,NULL,0);
	
		// store the string
		strcpy(shm,data);
		
		shmdt(shm); // detach 
	}

	
	printf("The Data send to READ process\n");
		
	strrev(data,strlen(data),0);	
	// when process 2 done its job print the reverse string
	
	// make a child process to wait
	int pid = fork();
	
	if(pid == 0)
	{
		while(strcmp(shm2,data) != 0)
		{
			shm2 = shmat(shmid,NULL,0);
		}

		// recive the data and print it 
		printf("The recieve string : %s\n",shm2);
	}
	else if(pid > 0)
	{
		wait(NULL);
	}
	else
	{
		perror("Fork");
		exit(3);
	}
	return 0;
}

void convert_to_uppercase(char* s)
{
	while(*s != '\0')
	{
			if (*s >= 'a' && *s <= 'z')
			*s -= 32;
			s++;
	}
}

void strrev(char* s, char size, char iter)
{
        //Swap lower half of the string with its upper half
        if (iter < (size) / 2)
        {
                //Using XOR swapping technique 
                s[iter] ^= s[size - 1 - iter];
                s[size - 1 - iter] ^= s[iter];
                s[iter] = s[size - 1 - iter] ^ s[iter];
                //Recursive call with incremented iter value
                strrev(s, size, ++iter);
        }
        //Implicit return
}
