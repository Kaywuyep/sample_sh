#include "shell.h"

/**
 * update_oldpwd - function that updates old working dir
 * @path: path of pwd
 * @old_dir: buffer to store the old directory
 * @max_len: maximum length of the old directory buffer
 * Return: 1 if successful, 0 otherwise
 */
int update_oldpwd(char *path, char *old_dir, size_t max_len)
{
	char current_dir[MAX_PATH_LEN];
	(void)path;

	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	{
		perror("simple_shell");
		return (0);
	}

	if (setenv("OLDPWD", current_dir, 1) != 0)
	{
		perror("simple_shell");
		return (0);
	}

	if (strlen(current_dir) >= max_len)
	{
		fprintf(stderr, "simple_shell: OWD path is too long\n");
		return (0);
	}

	strncpy(old_dir, current_dir, max_len);
	return (1);
}

/**
 * c_dir - a function that changes the directory
 * @path: working path
 * @old_dir: buffer to store the old directory
 * @max_len: maximum length of the old directory buffer
 * Return: 1 if successful, 0 otherwise
 */
int c_dir(char *path, char *old_dir, size_t max_len)
{
	char *previous_dir = NULL;
	char current_dir[MAX_PATH_LEN];

	if (strcmp(path, "-") == 0)
	{
		/* Handle "cd -" to go to the previous directory */
		previous_dir = getenv("OLDPWD");
		if (previous_dir == NULL)
		{
			fprintf(stderr, "simple_shell: cd: OLDPWD not set\n");
			return (0);
		}
		path = previous_dir;
	}

	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	{
		perror("simple_shell");
		return (0);
	}

	if (chdir(path) != 0)
	{
		perror("simple_shell");
		return (0);
	}

	if (!update_oldpwd(path, old_dir, max_len))
	{
		return (0);
	}

	if (setenv("PWD", path, 1) != 0)
	{
		perror("simple_shell");
		return (0);
	}

	return (1);
}

/**
 * handle_cd - a function that handles cd command
 * @command: user command
 * @old_dir: buffer to store the old directory
 * @max_len: maximum length of the old directory buffer
 */
void handle_cd(char *command, char *old_dir, size_t max_len)
{
	char *home_dir;
	char *path;

	if (strcmp(command, "cd") == 0)
	{
		/* If "cd" is entered without an argument, change to $HOME */
		home_dir = getenv("HOME");
		if (home_dir == NULL)
		{
			fprintf(stderr, "simple_shell: HOME dir not found\n");
		}
		else
		{
			c_dir(home_dir, old_dir, max_len);
		}
	}
	else if (strstr(command, "cd ") == command)
	{
		/* Handle "cd" with an argument */
		path = command + 3; /* Skip "cd " part */
		/*if (chdir(path) != 0)*/
		/*{perror("simple_shell");}*/
		/*else{update_oldpwd(path, old_dir, max_len);*/
		/*Update old working directory}*/
		c_dir(path, old_dir, max_len);
	}
else
{
	fprintf(stderr, "simple_shell: Invalid: %s\n", command);
}
}
