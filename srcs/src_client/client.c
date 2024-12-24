/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:54:02 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/23 15:01:46 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_encode(unsigned char ch)
{
	char			*result;
	int				count;
	unsigned char	mask;

	mask = 0x80;
	count = 0;
	result = malloc(sizeof(char) * (SIZE + 1));
	if (!result)
		return (NULL);
	while (count < SIZE)
	{
		if (ch & mask)
			result[count] = '1';
		else
			result[count] = '0';
		mask = mask >> 1;
		count++;
	}
	result[count] = '\0';
	return (result);
}

int	ft_valid_pid(int pid)
{
	if (kill(pid, SIGUSR1) == 0)
		return (1);
	ft_print_string("Invalid PID value!\n");
	return (0);
}

void	ft_send_msg(int pid, char *str)
{
	int		count;
	int		step;
	char	*msg;

	count = 0;
	while (str && str[count])
	{
		msg = ft_encode(str[count]);
		step = 0;
		while (msg && msg[step])
		{
			if (msg[step] - '0' == 1)
				kill(pid, SIGUSR1);
			if (msg[step] - '0' == 0)
				kill(pid, SIGUSR2);
			usleep(500);
			step++;
		}
		free(msg);
		count++;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str;

	if (argc != 3)
	{
		ft_print_string("Follow format : ./client <srever_PID> <string>\n");
		return (0);
	}
	if (!is_valid(argv[2]))
	{
		ft_print_string("PID contains invalid characters!\n");
		return (0);
	}
	pid = atoi(argv[2]);
	str = argv[1];
	ft_send_msg(pid, str);
	return (0);
}
