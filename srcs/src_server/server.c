/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:54:29 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/23 15:16:21 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_decode(char *str)
{
	int	result;
	int	count;
	int	temp;

	result = 0;
	temp = 0;
	count = SIZE - 1;
	while (count >= 0)
	{
		temp = ((str[count] - '0') & 1) * (1 << ((SIZE - 1) - count));
		result = result + temp;
		count--;
	}
	return (result);
}

void	handel_signal(int signum)
{
	static int		count;
	static char		msg[SIZE + 1];
	unsigned char	ch;

	if (signum == SIGUSR1)
	{
		msg[count] = '1';
		count++;
	}
	if (signum == SIGUSR2)
	{
		msg[count] = '0';
		count++;
	}
	if (count == SIZE)
	{
		msg[count] = '\0';
		ch = ft_decode(msg);
		printf("%c", ch);
		count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;
	static int		clock;

	pid = getpid();
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = handel_signal;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("Srever program (PID) : %d\n ", pid);
	printf("waiting for the binary message... \n");
	while (1)
	{
		pause();
		printf("clock : %d\n", clock);
		clock++;
	}
	return (0);
}
