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
	signal(SIGINT,handel_signal);
	printf("Press Ctrl + C to stop this program!\n");
	while(keep_running)
	{
		printf("The program is still running....\n");
		sleep(1);
	}
	printf("Program terminated.\n");
	return (0);
}
