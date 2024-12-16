#include <stdio.h>
#include <unistd.h>
#include <signal.h>


volatile int keep_running = 1;

void handel_signal(int signum)
{
	printf("Caught signal : %d\n", signum);
	keep_running = 0;
}

int main()
{
	struct	sigaction sa;
	int		pid;

	pid = getpid();

	sa.sa_handler = handel_signal;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);

	if(sigaction(SIGINT,&sa,NULL)== -1)
	{
		printf("An Eror occured!\n");
	}
	printf("PID : %d start to run ...\n", pid);
	printf("Press Ctrl + C to stop this program!\n");
	while(keep_running)
	{
		printf("The program is still running....\n");
		sleep(1);
	}
	printf("Program terminated.\n");
	return (0);
}
