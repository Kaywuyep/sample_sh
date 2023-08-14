#include "main.h"
/**
 * execute_command - a function that imitates the unix shell
 * @command: const variable
 */
void execute_command(const char *command)
{
	int status = system(command);
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Fork error");
	}
	else if (pid == 0)
	{
		/*Child process*/
		execlp(command, command, NULL);
		/*If exec fails, print an error and exit*/
		perror("Exec error");
		exit(1);
	}
	else
	{
		/*Parent process*/
		waitpid(pid, &status, 0);
	}
	if (status != 0)
	{
		printf("Error executing command: %s\n", command);
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
void print_env(char *env[])
{
	int i;

	/*Loop through the environment variables and print them*/
	for (i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
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
