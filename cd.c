#include "shell.h"
/*Global variable to store the old working directory*/
char old_working_dir[MAX_PATH_LEN] = "";
/**
 * update_oldpwd - function that updates old working dir
 * @path: path of pwd
 */
void update_oldpwd(char *path)
{
	char current_dir[1024];

	(void)path;

	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	{
		perror("simple_shell");
		return;
	}
	/*setenv("OLDPWD", current_dir, 1);*/
	if (setenv("OLDPWD", current_dir, 1) != 0)
	{
		perror("simple_shell");
	}
	strcpy(old_working_dir, current_dir);  /*Update old_working_dir*/
}
/**
 * c_dir - a function that changes the directory
 * @path: working path
 */
void c_dir(char *path)
{
	char *previous_dir = NULL;
	char current_dir[1024];

	if (strcmp(path, "-") == 0)
	{
		/*Handle "cd -" to go to the previous directory*/
		previous_dir = getenv("OLDPWD");
		if (previous_dir == NULL)
		{
			fprintf(stderr, "simple_shell: cd: OLDPWD not set\n");
			return;
		}
		/*display old working directory followed by new one*/
		/*printf("%s/%s\n", previous_dir, previous_dir);*/
		path = previous_dir;
	}
	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	{
		perror("simple_shell");
		return;
	}

	if (chdir(path) != 0)
	{
		perror("simple_shell");
		return;
	}

	update_oldpwd(path);
	/*setenv("PWD", path, 1);*/
	if (setenv("PWD", path, 1) != 0)
	{
		perror("simple_shell");
	}
	/*if (getcwd(current_dir, sizeof(current_dir)) != NULL)*/
	/*{printf("Changed directory to: %s\n", current_dir);}*/
	/*else{perror("simple_shell");}*/
}
/**
 * handle_cd - a function that handles cd command
 * @command: user command
 */
void handle_cd(char *command)
{
	char *home_dir;
	char *path;

	if (strcmp(command, "cd") == 0)
	{
		/*If "cd" is entered without an argument, change to $HOME*/
		home_dir = getenv("HOME");
		if (home_dir == NULL)
		{
			fprintf(stderr, "simple_shell: HOME dir not found\n");
		}
		else
		{
			c_dir(home_dir);
		}
	}
	else if (strstr(command, "cd ") == command)
	{
		/*Handle "cd" with an argument*/
		path = command + 3; /*Skip "cd " part*/
		c_dir(path);
	}
	else
	{
		fprintf(stderr, "simple_shell: Invalid: %s\n", command);
	}
}
