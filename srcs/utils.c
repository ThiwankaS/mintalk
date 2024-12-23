/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:01:17 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/23 14:02:09 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

size_t	ft_print_string(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int	ft_isnum(char c)
{
	if (c - '0' >= 0 && c - '9' <= 9)
		return (1);
	return (0);
}

int	is_valid(char *pid)
{
	int	count;

	count = 0;
	while (pid && pid[count])
	{
		if (!ft_isnum(pid[count]))
			return (0);
		count++;
	}
	return (1);
}
