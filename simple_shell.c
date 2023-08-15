#include "main.h"
/**
 * execute_command - a function that imitates the unix shell
 * @command: const variable
 */
void execute_command(const char *command, char *args[])
{
	int status;
	pid_t pid = fork();

	if (access(command, X_OK) != 0)/*X_OK: Test for execute permission*/
	{
		fprintf(stderr, "Command not found: %s\n", command);
		return;
	}

	if (pid < 0)
	{
		perror("Fork error");
	}
	else if (pid == 0)
	{
		/* Child process */
		execv(command, args);

		/* If exec fails, print an error and exit */
		perror("Exec error");
		exit(1);
	}
	else
	{
		/* Parent process */
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			fprintf(stderr, "Error executing command: %s\n", command);
		}
	}
}

/**
 * display_prompt - a function that displays the shell prompt
 *
 */
void display_prompt(void)
{
	printf("simple_shell:) ");
	fflush(stdout);
}
/**
 * print_env - a function that prints current environment
 * @env: current environment and pass envp directly
 */
void print_env()
{
	int i;

	/*Loop through the environment variables and print them*/
	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}
/**
 * env_builtin - function to check if the command is the env built-in
 * @command: user command
 * Return: env built-in func
 */
int env_builtin(const char *command)
{
	return (strcmp(command, "env") == 0);
}
/**
 * exit_builtin - a function that exits the shell
 * @command: user command
 * Return: exit
 */
int exit_builtin(const char *command)
{
	return (strcmp(command, "exit") == 0);
}
