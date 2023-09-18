#include "shell.h"

/**
 * execute - A function that executes a command.
 * @command: The pointer to tokienized command
 * @name: The name of the shell.
 * @env: The pointer to the enviromental variables.
 * @cicles: Number of executed cicles.
 * Return: Nothing.
 */
void execute(char **command, char *name, char **env, int cicles)
{
	char **pathways = NULL, *full_path = NULL;
	struct stat st;
	unsigned int i = 0;

	if (_strcmp(command[0], "env") != 0)
		print_env(env);

	/* Check if the command is an absolute path or in the current directory */
	if (command[0][0] == '/' || command[0][0] == '.')
	{
		if (stat(command[0], &st) == 0)
		{
			if (execve(command[0], command, env) < 0)
			{
				perror(name);  /*Print permission-related error*/
				free_exit(command);
			}
		}
		else
		{
			perror(name);  /*Print other errors*/
			free_exit(command);
		}
	}
	else
	{
		pathways = _getPATH(env, command);
		while (pathways[i])
		{
			full_path = _strcat(pathways[i], "/");
			full_path = _strcat(full_path, command[0]); /* Create full path */
			i++;
			if (stat(full_path, &st) == 0)
			{
				if (execve(full_path, command, env) < 0)
				{
					perror(name);  /*Print permission-related error*/
					free_dp(pathways);
					free_exit(command);
				}
				return;
			}
		}
		msgerror(name, cicles, command);
		free_dp(pathways);
	}
}


/**
 * print_env - A function that prints all enviromental variables.
 * @env: The pointer to enviromental variables.
 * Return: Nothing.
 */
void print_env(char **env)
{
	size_t i = 0, len = 0;

	while (env[i])
	{
		len = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
/**
 * getpid -  a function that gets the process id
 */
pid_t get_process_id(void)
{
	pid_t pid = getpid();
	return (pid);
}

/**
 * _getPATH - A function to gets the full value from.
 * enviromental variable PATH.
 * @env: The pointer to enviromental variables.
 * Return: All tokenized pathways for commands.
 */
char **_getPATH(char **env, char **command)
{
	char *pathvalue = NULL, **pathways = NULL;
	unsigned int i = 0;
	int len;

	pid_t pid = 1;/*get process id*/

	while (env[i])
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			pathvalue = env[i] + 5;

			/*Check if PATH is empty*/
			if (pathvalue[0] == '\0')
			{
				_fprintf(stderr, "./hsh: %d: %s: not found\n", pid, command[0]);
				exit(127);
			}

			/*Remove leading and trailing colons if present*/
			while (pathvalue[0] == ':')
				pathvalue++;

			len = _strlen(pathvalue);
			while (len > 0 && pathvalue[len - 1] == ':')
			{
				pathvalue[len - 1] = '\0';
				len--;
			}

			/*Tokenize the cleaned PATH*/
			pathways = tokening(pathvalue, ":");
			return pathways;
		}
		i++;
	}

	/*Handle the case where PATH is not found or is empty*/
	_fprintf(stderr, "./hsh: %d: %s: not found\n", pid, command[0]);
	exit(127);
}

/**
 * custom_fprintf - A custom function similar to fprintf
 * @stream: The output stream (e.g., stderr)
 * @format: The format string
 * @...: Variable number of arguments to be formatted and printed
 *
 * Description: This function mimics the behavior of fprintf by taking
 * a format string and a variable number of arguments and printing
 * the formatted output to the specified stream.
 */
void _fprintf(FILE *stream, const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vfprintf(stream, format, args);
	va_end(args);
}
/**
 * msgerror - A function that prints message not found.
 * @name: The name of the shell.
 * @cicles: Number of cicles.
 * @command: The pointer to tokenized command.
 * Return: Nothing.
 */
void msgerror(char *name, int cicles, char **command)
{
	char c;

	c = cicles + '0';
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, command[0], _strlen(command[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
