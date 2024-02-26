#include "main.h"
int pid;

void scan_input(char *prompt,char *input_string)
{
	// variable for command 
	char *command = "\0";
	int command_type;
	int status;

	while(1)
	{
		memset(input_string,'\0',25);

		printf(ANSI_COLOUR_CYAN"[%s]$:"ANSI_COLOUR_YELLOW,prompt);
		
		// clear the stdout buffer
		fflush(stdout);
		// read from user
		scanf("%[^\n]s",input_string);
		// clear the stdin buffer
		getchar();
		
		// customize the prompt
		if(strncmp("PS1=",input_string,4) == 0)
		{
			if(input_string[4] != ' ')
			{
				strcpy(prompt,&input_string[4]);
				// clear the input
				memset(input_string,'\0',25);
				continue;
			}
			else
			{
				printf("Command NOT Found\n");
			}
		}
		
		// get the command
		command = get_command(input_string);
		//printf("Command is %s\n",command);
		
		command_type = check_command_type(command);
		printf("Command Type is %d\n",command_type);
		
		// External command
		if(command_type == EXTERNAL)
		{
			// creat a child process and perfrom the operation
			pid = fork();

			if(pid > 0)
			{
				//Parent process
				wait(&status); 
				if(WIFEXITED(status))
				{
					printf("Child process terminated %d\n", pid);
				}		
			}
			else if(pid == 0)
			{
				int ret_status = system(input_string);
				if(ret_status == 0)
				{
					exit(0);
				}
			}
			else
			{
				printf("Error Occure Fork\n");
				exit(1);
			}
		}
			
		// Inplement family of echo function
		echo(input_string,status);
		
		// Execute internal commands
		execute_internal_commands(prompt,input_string);
	}
	
}


