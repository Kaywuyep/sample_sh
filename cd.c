#include "shell.h"
/**
 * change_dir - Afunction that changes working directory.
 * @path: The new current working directory.
 * Return: 0 on success, -1 on failure.
 */
int change_dir(const char *path)
{
	char *new_path = NULL, *current_path;
	char *prev_dir = NULL;
	const char *home, *oldpwd;

	if (path == NULL || _strcmp(path, "-") == 0)
	{
		home = getenv("HOME");
		if (home == NULL)
		{
			_fprintf(stderr, "HOME env variable not set\n");
			return (1);
		}
		unsetenv("HOME");
		new_path = strdup(home);
	}
	else
	{
		new_path = strdup(path);
	}
	if (new_path == NULL)
	{
		perror("strdup");
		return (1);
	}
	current_path = getcwd(NULL, 0);
	if (current_path == NULL)
	{
		perror("getcwd");
		free(new_path);
		return (1);
	}
	if (_strcmp(new_path, "/root") == 0)
	{
		_fprintf(stderr, "Permission denied: %s\n", new_path);
		free(new_path);
		free(current_path);
		return (1);
	}
	if (_strcmp(new_path, "-") == 0)
	{
		oldpwd = getenv("OLDPWD");
		if (oldpwd != NULL)
		{
			new_path = strdup(oldpwd);
		}
	}
	if (access(new_path, F_OK) != 0)
	{
		_fprintf(stderr, "./hsh: 1: cd: can't cd to %s\n", new_path);
		free(new_path);
		free(current_path);
		return (1);
	}
	if (chdir(new_path) == -1)
	{
		perror(new_path);
		free(new_path);
		free(current_path);
		return (1);
	}
	if (set_pwd_env() == -1)
	{
		free(new_path);
		free(current_path);
		return (1);
	}
	if (path == NULL || _strcmp(path, "-") == 0)
	{
		if (restore_home() == -1)
		{
			free(new_path);
			free(current_path);
			return (1);
		}
	}

	free(new_path);
	if (prev_dir != NULL)
	{
		free(prev_dir);
	}

	return (0);
}
/**
 * set_pwd_env -Function to set the PWD environment variable
 * Return: 0 success
 */
int set_pwd_env(void)
{
	char *cwd = getcwd(NULL, 0);

	if (cwd == NULL)
	{
		perror("getcwd");
		return (-1);
	}

	if (setenv("PWD", cwd, 1) == -1)
	{
		perror("setenv");
		free(cwd);
		return (-1);
	}

	free(cwd);
	return (0);
}
/**
 * restore_home - Function to restore the HOME environment variable
 * Return: 0 success
 */
int restore_home(void)
{
	const char *home = getenv("HOME");

	if (home != NULL)
	{
		if (setenv("HOME", home, 1) == -1)
		{
			perror("setenv");
			return (-1);
		}
	}
	return (0);
}
