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

typedef struct {
	char *data;
	size_t size;
} String;

extern char **environ;/*External reference to the environment variables*/

int exit_builtin(const char *command, int *exit_status);
void exit_shell(int exit_status);
void execute_command(const char *command, char *args[]);
void display_prompt(void);

void get_path_dir(char *path_dirs[], int *num_dirs);
void handle_command(char *command, char *path_dirs[], int num_dirs);
char *find_executable(char *command, char *path_dirs[], int num_dirs);

char *find_start(char *str, const char *delim);
char *find_end(char *str, const char *delim);
char *_strtok(char *str, const char *delim);
/*char *_strtok(char *str, const char *delim, char **saveptr);*/
/*char *_strtok(const char *str, const char *delim, char **saveptr);*/

void setenv_builtin(const char *command);
void handle_setenv(const char *command);
void unsetenv_builtin(const char *command);
void handle_unsetenv(const char *command);

void init_string(size_t *str_len, char **str);
void append_string(char **str, size_t *str_len, char c);
int read_buffer(char *buffer, size_t *buffer_pos, ssize_t *bytes_in_buffer);
/*ssize_t _getline(char **line, size_t *line_len, FILE *stream);*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

void handle_cd(char *command);



#endif
