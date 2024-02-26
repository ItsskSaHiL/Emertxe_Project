#include "main.h"
void execute_internal_commands (char *prompt,char *input_string) 
{

	//exit -->terminate the program 
	if(strncmp("exit", input_string,4) == 0)
	{
		exit(2);
	}

	//pwd

	if(strncmp("pwd", input_string, 3) == 0)
	{	
		system("pwd");
	}
	//cd
	if(strncmp("cd", input_string, 2) == 0) //input_string =>cd abc
	{
		replace_blank(input_string);

		chdir(&input_string[3]); // with outspaces
		
		// prompt change
		strcat(prompt,"/");
		strcat(prompt,&input_string[3]);
	}
}
