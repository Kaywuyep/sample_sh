#include "shell.h"
/**
 * sigint_handler - Signal handler functions
 * @signum: parameter
 */
void sigint_handler(int signum)
{
	printf("\nReceived SIGINT (Ctrl+C). Press Enter to continue.\n");
	fflush(stdout);
}
/**
 * sigquit_handler - handle SIGQUIT behavior
 * @signum: parameter
 */
void sigquit_handler(int signum)
{
	printf("\nReceived SIGQUIT (Ctrl+D).\n");
}
/**
 * sigfpe_handler - handles floating point execptions. SIGFPE behavior
 * @signum: parameter
 */
void sigfpe_handler(int signum)
{
	printf("\nReceived SIGFPE (Floating Point Exception).\n");
}
/**
 * sigkill_handler - used to terminate a process forcefully
 * @signum: parameter
 */
void sigkill_handler(int signum)
{
	printf("\nReceived SIGKILL. Exiting immediately.\n");
	exit(EXIT_SUCCESS);
}
/**
 * sigterm_handler - terminates a session, handle SIGTERM behavior
 * @signum: parameter
 */
void sigterm_handler(int signum)
{
	printf("\nReceived SIGTERM (Termination).\n");
}
/**
 * sigalrm_handler - handle alarm signal behaviour
 * @signum: parameter
 */
void sigalrm_handler(int signum)
{
	printf("\nReceived SIGALRM (Alarm clock).\n");
}
/**
 * sighup_handler - handles "hang up" signal, designed to notify the terminal
 * when a sesseion has ended
 *
 * @signum: parameter
 */
void sighup_handler(int signum)
{
	printf("\nReceived SIGHUP (Hang-up or terminal death).\n");
}
/**
 * setup_signal_handlers - Function to set up signal handlers
 */
void setup_signal_handlers(void)
{
	/*Register signal handlers for each signal*/
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
