#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handel_signal(int signum)
{
	if(signum == SIGUSR1)
	{
		printf("1");
		fflush(stdout);
	}
	else if( signum == SIGUSR2)
	{
		printf("0");
		fflush(stdout);
	}
	else if( signum == SIGINT)
	{
		printf("\n");
		fflush(stdout);
		exit(0);
	}
}

int main()
{
	struct	sigaction sa;
	int		pid;

	pid = getpid();

	sa.sa_handler = handel_signal;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGINT, &sa, NULL);

	printf("Srever program (PID) : %d\n ", pid);
	printf("waiting for the binary message... \n");

	while(1)
	{
		pause();
	}
	return (0);
}
