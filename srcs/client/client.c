#include "srcs/minitalk.h"

char *ft_encode(unsigned char ch)
{

	char *result;
	int count = 0;
	unsigned char mask = 10000000;

	result = malloc(sizeof(char) * 8);
	if(!result)
		return (NULL);
			while(count < 8)
			{
				if (ch & mask)
					result[count] = '1';
				else
					result[count] = '0';
				mask = mask >> 1;
				count++;
			}
	return (result);
}

int main(int argc, char *argv[])
{
	int		pid;
	int		count;
	char	*str;
	char	*msg;

	if(argc != 3)
		ft_print_string("Follow the format : ./client <srever_PID> <string_to_transmite>");

	pid = atoi(argv[2]);
	str = argv[1];

	while(str && str[count])
	{
		msg = ft_encode(str[count]);
		int step = 0;
		while(msg && msg[step])
		{
			if(msg[step] - '0' == 1)
				kill(pid,SIGUSR1);
			if(msg[step] - '0' == 0)
				kill(pid,SIGUSR2);
			usleep(1000);
			step++;
		}
		free(msg);
		count++;
	}
	kill(pid,SIGINT);
	return (0);
}
