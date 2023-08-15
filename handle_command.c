#include "main.h"
/**
 * handle_command - Function to handle command execution
 * @command: user command
 * @path_dirs: an array to the path directories
 * @num_dirs: number of directories
 */
void handle_command(char *command, char *path_dirs[], int num_dirs)
{
	char *args[MAX_ARGS];
	char *token = strtok(command, " ");
	int count = 0;
	char *exec_path;

	while (token != NULL && count < MAX_ARGS - 1)
	{
		args[count] = token;
		token = strtok(NULL, " ");
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
		printf("Command '%s' not found.\n", args[0]);
	}
}
