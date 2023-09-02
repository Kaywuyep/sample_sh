#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100

int is_delim(char c, const char *delim);
char *find_token(char *str, const char *delim);
char *_strtok(char *str, const char *delim);

#endif
