#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>	//UNAUTH
#include "libft.h"


void	exit_me(const char *error)
{
	if (!error)
		exit(EXIT_SUCCESS);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (errno)
	{
		perror(error);
		exit(errno);
	}
	else
	{
		ft_putstr_fd(error, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
