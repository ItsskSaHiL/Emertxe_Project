#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio_ext.h>
#include <signal.h>
#include <sys/wait.h>

#define BUILTIN    1
#define EXTERNAL   2
#define NO_COMMAND 3

#define ANSI_COLOUR_RED      "\x1b[31m"
#define ANSI_COLOUR_GERRN    "\x1b[32m"
#define ANSI_COLOUR_YELLOW   "\x1b[33m"
#define ANSI_COLOUR_BLUE     "\x1b[34m"
#define ANSI_COLOUR_MAGENTA  "\x1b[35m"
#define ANSI_COLOUR_CYAN     "\x1b[36m"
#define ANSI_COLOUR_RESET      "\x1b[0m"

// function Decleartion
void scan_input(char *prompt,char *input_string);
char *get_command(char *input_string);
int check_command_type(char *command);
void echo(char *input_string,int status);
void signal_handler(int sig_num);
void extract_external_commands(char **external_commands);
void execute_internal_commands(char *prompt,char *input_string);
void replace_blank(char *input_string);

#endif
