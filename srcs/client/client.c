#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int main()
{
	int pid;
	printf("Enter the PID to end the program : ");
	scanf("%d", &pid);
	if(kill(pid, SIGINT) == 0)
	{
		printf("Successfull terminate the program. PID : %d\n", pid);
	}
	else
	{
		printf("Program terminating unsuccesfull PID : %d\n", pid);
	}
	return (0);
}
