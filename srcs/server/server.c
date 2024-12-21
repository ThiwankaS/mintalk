#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int ft_decode(char *str)
{
	int result = 0;
	int count = 7;
	while (count >= 0)
	{
		result = result + ((str[count] - '0') & 1) * (1 << (7 - count));
		count--;
	}
	return result;
}


void handel_signal(int signum)
{
	static int count = 0;
	static char msg[9];
	clock_t start, end;
    double cpu_time_used;

	start = clock();

	if(signum == SIGUSR1)
	{
		msg[count] = '1';
		count++;
	}
	else if( signum == SIGUSR2)
	{
		msg[count] = '0';
		count++;
	}
	else if( signum == SIGINT)
	{
		msg[count + 1] = '\0';
		end = clock();
		cpu_time_used = (double)((end-start)/CLOCKS_PER_SEC);
		printf("Execution time: %f seconds\n", cpu_time_used);
		exit(0);
	}
	if(count == 8)
	{
		msg[count + 1] = '\0';
		char ch = ft_decode(msg);
		printf("%c", ch);
		count = 0;
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
