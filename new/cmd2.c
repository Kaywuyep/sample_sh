#include "shell.h"
/**
 * execute_command - a function that executes the command
 * @command: arguments
 */
void execute_command(char *command, const char *path)
{
	char *args[MAX_ARGS];
	char *token;
	int num_args = 0;
	char exec_path[BUFF_SIZE];
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/*Child process*/
		token = strtok(command, " ");
		while (token != NULL && num_args < MAX_ARGS - 1)
		{
			args[num_args] = token;
			num_args++;
			token = strtok(NULL, " ");
		}
		args[num_args] = NULL;

		/* Use execve to execute the command */
		strcpy(exec_path, find_exec(args[0], path));
		if (exec_path[0] != '\0')
		{
			if (execve(exec_path, args, NULL) == -1)
			{
				perror(exec_path);
				_exit(EXIT_FAILURE);
			}
		}
		else
		{
			fprintf(stderr, "%s: command not found\n", args[0]);
			_exit(EXIT_FAILURE);
		}

	}
	else
	{
		/*Parent process*/
		wait(NULL);  /*Wait for the child process to finish*/
	}
}
/**
 * is_exec - function that checks if path is executable
 * @path: shows path
 * Return: permission acess
 */
int is_exec(const char *path)
{
	return access(path, X_OK) == 0;
}
/**
 * find_exec - function that finds executables
 * @command: user command
 * @path: ...
 * Return: ...
 */
char *find_exec(const char *command, const char *path)
{
	char *path_copy;
	char *dir;
	char *exec_path;

	path_copy = strdup(path);
	if (!path_copy)
	{
		perror("strdup");
		return (NULL);
	}

	dir = strtok(path_copy, ":");
	while (dir)
	{
		exec_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!exec_path)
		{
			perror("malloc");
			free(path_copy);
			return (NULL);
		}
		sprintf(exec_path, "%s/%s", dir, command);
		if (is_exec(exec_path))
		{
			free(path_copy);
			return (exec_path);
		}

		free(exec_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
/**
 * exit_builtin - handles exit
 * Return: success
 */
int exit_builtin(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		return (1);
	}
	/*Add more built-in commands here*/

	return (0);
}
