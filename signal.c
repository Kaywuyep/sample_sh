#include "shell.h"
// Signal handler functions
void sigint_handler(int signum)
{
	printf("\nReceived SIGINT (Ctrl+C). Press Enter to continue.\n");
	fflush(stdout);
}

void sigquit_handler(int signum)
{
	printf("\nReceived SIGQUIT (Ctrl+D).\n");
	// Handle SIGQUIT behavior
}

void sigfpe_handler(int signum)
{
	printf("\nReceived SIGFPE (Floating Point Exception).\n");
	// Handle SIGFPE behavior
}

void sigkill_handler(int signum)
{
	printf("\nReceived SIGKILL. Exiting immediately.\n");
	exit(EXIT_SUCCESS);
}

void sigterm_handler(int signum)
{
	printf("\nReceived SIGTERM (Termination).\n");
	// Handle SIGTERM behavior
}

void sigalrm_handler(int signum)
{
	printf("\nReceived SIGALRM (Alarm clock).\n");
	// Handle SIGALRM behavior
}

void sighup_handler(int signum)
{
	printf("\nReceived SIGHUP (Hang-up or terminal death).\n");
	// Handle SIGHUP behavior
}

// Function to set up signal handlers
void setup_signal_handlers()
{
	// Register signal handlers for each signal
	if (signal(SIGINT, sigint_handler) == SIG_ERR)
	{
		perror("signal");
		exit(1);
	}

	if (signal(SIGQUIT, sigquit_handler) == SIG_ERR)
	{
		perror("signal");
		exit(1);
	}

	if (signal(SIGFPE, sigfpe_handler) == SIG_ERR)
	{
		perror("signal");
		exit(1);
	}

	if (signal(SIGKILL, sigkill_handler) == SIG_ERR)
	{
		perror("signal");
		exit(1);
	}

	if (signal(SIGTERM, sigterm_handler) == SIG_ERR)
	{
		perror("signal");
		exit(1);
	}

	if (signal(SIGALRM, sigalrm_handler) == SIG_ERR)
	{
		perror("signal");
		exit(1);
	}

	if (signal(SIGHUP, sighup_handler) == SIG_ERR)
	{
		perror("signal");
		exit(1);
	}
}
