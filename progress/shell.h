#ifndef _SHELL_H_
#define _SHELL_H_
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_DIRS 100
#define MAX_ARGS 100
#define _GNU_SOURCE /*Define _GNU_SOURCE to enable access to environ*/
#define MAX_ENV_VARS 100  /*maximum number of environment variables*/
#define BUFF_SIZE 1024
#define MAX_PATH_LEN 1024


extern char **environ;

int main(int ac, char **av, char **env);
void prompt(void);
void handle(int signals);
void _EOF(char *buffer);
void shell_exit(char **command);


void create_child(char **command, char *name, char **env, int cicles);
int change_dir(const char *path);


void execute(char **command, char *name, char **env, int cicles);
void print_env(char **env);
char **_getPATH(char **env);
void msgerror(char *name, int cicles, char **command);
int command_exists(const char *command, char **env);


char **tokening(char *buffer, const char *s);


void free_dp(char **command);
void free_exit(char **command);


int _strcmp(char *s1, char *s2);
unsigned int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strcat(char *dest, const char *src);
int _strncmp(const char *s1, const char *s2, size_t n);

char **duplicate_pathways(char **pathways);

int is_delim(char c, const char *delim);
char *find_token(char *str, const char *delim);
char *_strtok(char *str, const char *delim);

void update_oldpwd(char *path);
void c_dir(char *path);
void handle_cd(char *command);

#endif /* _SHELL_H_ */
