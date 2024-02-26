/*
* Name : Sk Sahil
* Assigment : A08 - WAP to create three child from the same parent
* Date of Submission : 07/01/2023
*
* Pre-requisites: 
*	Knowledge about system calls, How to read and understand ‘man pages’. 
* 	Good knowledge about processes.
* 	Working of fork & wait system calls. 
*
* Objective: 
* To understand how to use fork system calls.
*
* Requirements: 
*	Create three child process from same parent. 
*	Parent has to wait for all three child process.
*	Print exit status of each child when they terminates.
*
* Sample execution: 
*	./three_child 
*	Child 1 with pid 2020 created 
*	Child 2 with pid 2021 created
*	Child 3 with pid 2022 created 
*	Child 2020 is terminated with code 0 
*	Child 2021 is terminated with code 0 
*	Child 2022 is terminated with code 0
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/wait.h>	

int main()
{
	// process creation
	int c1 = fork();
	
	// error check
	if(c1 <0)
	{
		perror("fork");
		exit(1);
	}
	
	// validate parent and child 
	if(c1 > 0)
	{
		// 2nd process creat
		int c2 = fork();
		
		// error check
		if(c2 <0)
		{
			perror("fork");
			exit(1);
		}
		
		// validate parent and child
		if(c2 > 0)
		{
			// 2nd process creat
                  	int c3 = fork();
 
                  	// error check
                 	if(c3 <0)
                  	{
                        	perror("fork");
                          	exit(1);
                  	}
 
                  	// validate parent and child
                  	if(c3 > 0)
                  	{	
				//parent process
				int status;
				int wpid;
				int i = 0;
			
				for(i = 0; i < 3; i++)
				{
					//wait for children
					wpid = wait(&status);
					
					//check exit status of child
					if(WIFEXITED(status))
					{
						printf("Child %d is terminated with code %d \n", wpid, WEXITSTATUS(status));
						sleep(1);
					}
				}				
				
			}
			else
                  	{
                        	// print the child status
                          	printf("Child 3 with pid %d created\n",getpid());
                  		exit(0);
			}
		
		}
		else
		{
                	// print the child status
                	printf("Child 2 with pid %d created\n",getpid());
         		exit(0);
		}
		
	}
	else
	{
		// print the child status
		printf("Child 1 with pid %d created\n",getpid());
		exit(0);
	}
	
	
	return 0;
}
	
