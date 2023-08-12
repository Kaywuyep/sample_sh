#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024

/*ssize_t getline(char **restrict lineptr, size_t *restrict n,
		FILE *restrict stream);prototype from man 3 getline*/
char *strtok(char *str, const char *delim);/*prototype from man strtok*/

void execute_command(const char *command);

#endif
