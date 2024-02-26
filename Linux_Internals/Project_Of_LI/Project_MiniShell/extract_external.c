#include "main.h"

void extract_external_commands(char **external_commands)
{
	// variable decleration
	char ch;
	char buffer[25] = {'\0'};
	int i = 0;
	int j = 0;
	
	// open the file 
	int fd = open("external_command.txt",O_RDONLY);
	
	// error check
	if(fd == -1)
	{
		printf("File can't open\n");
		exit(1);
	}
	
	// read command from the file
	while(read(fd,&ch,1) >0)
	{
		if(ch != '\n')
		{
			buffer[i++] = ch;
		}
		else
		{
			// allocate sufficient memory 
			external_commands[j] = calloc(strlen(buffer)+1, sizeof(char));
			//copy the contents
			strcpy(external_commands[j++], buffer); 
			//Append NULL character at the end
			external_commands[j] = '\0';
			//clear the buffer
			memset(buffer,'\0',25);
			// reinitilize the variable 
			i = 0;	
		}	
	}		
}
