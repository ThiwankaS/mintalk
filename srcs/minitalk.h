#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <string.h>

#define SIZE 8

int	is_valid(char *pid);

size_t	ft_strlen(char *str);
size_t	ft_print_string(char *str);

#endif
