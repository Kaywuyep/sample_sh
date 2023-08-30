#include "shell.h"
/**
 * get_path_dir - a function that handles the path directories
 * @path_dirs: an array to the path directories
 * @num_dirs: number of directories
 */
void get_path_dir(char *path_dirs[], int *num_dirs)
{
	char *path_env = getenv("PATH");
	char *copy_path = strdup(path_env);
	char *token;
	int count = 0;

	token = _strtok(copy_path, ":");

	if (path_env == NULL)
	{
		*num_dirs = 0;
		return;
	}

	while (token != NULL && count < MAX_DIRS)
	{
		path_dirs[count] = token;
		token = _strtok(NULL, ":");
		count++;
	}

	*num_dirs = count;
	free(copy_path);
}
/**
 * find_executable - a function that finds executable files
 * @command: user command
 * @path_dirs: path directories
 * @num_dirs: number of directories
 * Return: NULL
 */
char *find_executable(char *command, char *path_dirs[], int num_dirs)
{
	int i;
	char exec_path[MAX_COMMAND_LENGTH];
	char *result = NULL ;/*initialize to null*/

	for (i = 0; i < num_dirs; i++)
	{
		snprintf(exec_path, sizeof(exec_path),
				"%s/%s", path_dirs[i], command);
		/*snprintf is used to ensure safe or secure printf*/

		if (access(exec_path, X_OK) == 0)
			/*X_OK: Test for execute permission*/
		{
			result = strdup(exec_path);
			if (result == NULL)
			{
				/*Handle memory allocation failure*/
				return (NULL);
			}
			return (result);
		}
	}
	free (result);
	return (NULL);
}
