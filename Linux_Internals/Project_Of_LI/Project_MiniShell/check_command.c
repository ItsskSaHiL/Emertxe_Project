#include "main.h"

// command internal , external , no command
int check_command_type(char *command)
{
	//List builtin commands

	char *builtins[] = {"echo", "printf", "read", "cd", "pwd", "pushd", "popd", "dirs", "let ", "eval", "set", "unset", "export", "declare", "typeset", 				"readonly", "getopts", "source", "exit", "exec", "shopt", "caller", "true", "type", "hash", "bind", "help", NULL};

	for (int i=0; builtins[i] != NULL;i++)	
	{
		if(strcmp(command,builtins[i]) == 0)
		{
			return BUILTIN;
		}	
	}
	
	// EXTER KEY
	if(strcmp(command,"\0") == 0)
	{
		return NO_COMMAND;
	}	

	// to extract the external command 
	char *external_commands[172] = {NULL};
	extract_external_commands(external_commands);
	
	for (int i=0; external_commands[i] != NULL;i++)	
	{
		if(strcmp(command,external_commands[i]) == 0)
		{
			return EXTERNAL;
		}	
	}

}

