/*
* Name : Sk Sahil
* Project : Minishell
* Date of Submission : 21/01/2023
* Description:
	Implement a minimalistic shell, mini-shell(msh) as part of the Linux Internal module.
* Objective:
	The objective is to understand and use the system calls w.r.t process creation, signal handling, process synchronization, exit status, text parsing etc..
* Requirement details:
	1.Provide a prompt for the user to enter commands
		Display the default prompt as msh>
		Prompt should be customizable using environmental variable PS1
		To change the prompt user will do PS1=NEW_PROMPT
		Make sure that you do not allow whitespaces between = i.e., do not allow PS1 = NEW_PROMPT
		In the above case, it should be treated like a normal command

	2. Execute the command entered by the user
		User will enter a command to execute
		If it is an external command
		Create a child process and execute the command
		Parent should wait for the child to complete
 		Only on completion, msh prompt should be displayed
 		If user entering without a command should show the prompt again

	3 Special Variables:
		Exit status of the last command (echo $?)
 		After executing a command the exit status should be available
 		echo $? should print the exit status of the last command executed
		PID of msh (echo $$)
		echo $$: should print msh's PID
		Shell name (echo $SHELL)
		echo $SHELL: should print msh executable path

	4.Built-in commands
		1. exit exit: This command will terminate the msh program
		2. cd cd: Change directory
		3. pwd: show the current working directory
*/


#include "main.h"

int main()
{
	system("clear");
	
	//Array to store the Input
	char input_string[25];
	
	//Array to store the Prompt
	char prompt[25] = "msh";
	
	// scan the input
	scan_input(prompt,input_string);

	return 0;	
}
