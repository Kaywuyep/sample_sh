#include "shell.h"
/**
 * execute_single_command - Function to execute a single command
 * @command: user input
 * Return: success
 */
int execute_single_command(char *command)
{
	int result;

	/*printf("Executing command: %s\n", command);*/
	result = system(command);

	if (WIFEXITED(result))
	{
		return (WEXITSTATUS(result));
	}
	else
	{
		return (-1); /*Command execution failed*/
	}
}
/**
 * handle_command - Function to handle command execution
 * @command: user command
 * @path_dirs: an array to the path directories
 * @num_dirs: number of directories
 * @old_working_dir: ...
 * @exit_status: ...
 * Return: ...
 */
void handle_command(char *command, int *exit_status,
		char old_working_dir[], char *path_dirs[], int num_dirs)
{
	char *args[MAX_ARGS], *exec_path, *next_separator, *token;
	int command_exit_status, count = 0;
	(void)old_working_dir;
	command_exit_status = execute_single_command(command);
	next_separator = strstr(command, "&&");
	if (next_separator)
	{/*Handle '&&' and execute the next command conditionally*/
		execute_commands_separated(next_separator + 2);
	}
	else
	{
		next_separator = strstr(command, "||");
		if (next_separator)
		{/*Handle '||' and execute the next command conditionally*/
			execute_commands_separated(next_separator + 2);
		}
	}
	*exit_status = command_exit_status;
	if (!next_separator)
	{
		token = _strtok(command, " ");
		while (token != NULL && count < MAX_ARGS - 1)
		{
			args[count] = token;
			token = _strtok(NULL, " ");
			count++;
		}
		args[count] = NULL;
		exec_path = find_executable(args[0], path_dirs, num_dirs);
		if (exec_path != NULL)
		{
			execute_command(exec_path, args);
			free(exec_path);
		}
		else
		{
			perror("Command not found");
			free(exec_path);
		}
	}
}
