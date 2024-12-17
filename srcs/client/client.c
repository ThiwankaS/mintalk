#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int main()
{
	int pid;
	int count = 0;
	char *str;

	printf("Enter the PID of the program : ");
	scanf("%d", &pid);
	printf("Enter the message (Binary) : \n");
	scanf("%s", str);
	while(str && str[count])
	{
		if(str[count] - '0' == 1)
			kill(pid,SIGUSR1);
		if(str[count] - '0' == 0)
			kill(pid,SIGUSR2);
		usleep(10000);
		count++;
	}
	return (0);
}
