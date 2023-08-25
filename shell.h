#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stdbool.h>/* provides the bool data type and true/false constants*/

#define MAX_COMMAND_LENGTH 1024
#define MAX_DIRS 100
#define MAX_ARGS 100
#define _GNU_SOURCE /*Define _GNU_SOURCE to enable access to environ*/
#define MAX_ENV_VARS 100  /*maximum number of environment variables*/
#define BUFF_SIZE 1024

void display_prompt(void);
int read_input(char **command, size_t *command_len);
void handle_command(char *command, char ***argv, int *num_tok);
void cleanup(char *command, char **argv);
void execute_command(char *command);

#endif
