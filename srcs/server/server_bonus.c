#include "srcs/minitalk.h"

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


void handel_signal(int signum, siginfo_t *info, void *p)
{
	static int count = 0;
	static char msg[9];

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
		printf("\n");
	}
	if(count == 8)
	{
		msg[count + 1] = '\0';
		char ch = ft_decode(msg);
		printf("%c", ch);
		kill(info->si_pid,SIGUSR1);
		count = 0;
	}
}

int main()
{
	struct	sigaction sa;
	int		pid;


	pid = getpid();

	memset(&sa,0,sizeof(sa));
	sa.sa_sigaction = handel_signal;
	sa.sa_flags |= SA_SIGINFO;
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
