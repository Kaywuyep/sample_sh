#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define _GNU_SOURCE /*Define _GNU_SOURCE to enable access to environ*/

/*char *strtok(char *str, const char *delim);prototype from man strtok*/
int exit_builtin(const char *command);
void execute_command(const char *command);
void display_prompt(void);

#endif
