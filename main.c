#include "main.h"
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

	get_path_dir(path_dirs, &num_dirs);

	while (1)
	{
		display_prompt();

		num_chars = getline(&command, &command_len, stdin);
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
		if (exit_builtin(command))
		{
			/*Exit the shell*/
			break;
		}
		else if (env_builtin(command))
		{
			print_env();/*print the current environment*/
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
