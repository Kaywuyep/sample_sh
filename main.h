#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_DIRS 64
#define MAX_ARGS 64
#define _GNU_SOURCE /*Define _GNU_SOURCE to enable access to environ*/
#define MAX_ENV_VARS 100  /*maximum number of environment variables*/
#define BUFF_SIZE 1024

extern char **environ;/*External reference to the environment variables*/
/*char *strtok(char *str, const char *delim);prototype from man strtok*/
int exit_builtin(const char *command);
void execute_command(const char *command, char *args[]);
void display_prompt(void);
void get_path_dir(char *path_dirs[], int *num_dirs);
void handle_command(char *command, char *path_dirs[], int num_dirs);
char *find_executable(char *command, char *path_dirs[], int num_dirs);

#endif
