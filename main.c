#include "shell.h"
/*declare the display prompt function*/
void display_prompt(void);
/*declare the function to print current environment*/
void print_env(void);
/*declare a function to chect env built in*/
int env_builtin(const char *command);
/*function that gets the path directories*/
void get_path_dir(char *path_dirs[], int *num_dirs);
/**
 * main - entry point
 *
 * Return: 0
 */
int main(void)
{
	char *command;
	size_t command_len = 0;
	ssize_t num_chars;
	char *path_dirs[MAX_ARGS];
	int num_dirs = 0;
	int exit_status = 0;
	char old_working_dir[MAX_PATH_LEN] = "";

	get_path_dir(path_dirs, &num_dirs);

	while (1)
	{
		display_prompt();

		num_chars = _getline(&command, &command_len, stdin);
		if (num_chars == -1)
		{
			printf("\n\n\nDisconnecting...\n\n");
			break;/*handle CTRL+D or EOF*/
		}
		/*remove newline characters*/
		if (num_chars > 0 && command[num_chars - 1] == '\n')
		{
			command[num_chars - 1] = '\0';
		}
		if (strlen(command) == 0)
		{
			continue;
		}
		if (strcmp(command, "setenv") == 0)
		{
			setenv_builtin(command);
		}
		else if (strcmp(command, "unsetenv") == 0)
		{
			unsetenv_builtin(command);
		}
		else if (exit_builtin(command, &exit_status))
		{
			/*Exit the shell with specified exit status*/
			free(command);
			exit_shell(exit_status);
		}
		else if (env_builtin(command))
		{
			print_env();/*print the current environment*/
		}
		else if (strstr(command, "cd") == command)
		{
			handle_cd(command, old_working_dir, sizeof(old_working_dir));
			/*handle_cd(command)*/
		}
		else
		{
			handle_command(command, path_dirs, num_dirs);
		}
	}
	/*free allocated memory*/
	free(command);
	return (0);
}
