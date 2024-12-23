#include "minitalk.h"

size_t ft_strlen(char *str)
{
	size_t len;

	len = 0;
	while(str && str[len])
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
