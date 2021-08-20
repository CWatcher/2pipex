/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:05:01 by CWatcher          #+#    #+#             */
/*   Updated: 2021/07/21 17:17:00 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "libft.h"

void	exit_me(char *dynamic_error)
{
	int	status;

	status = EXIT_SUCCESS;
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (errno)
	{
		perror(dynamic_error);
		status = errno;
	}
	else
	{
		ft_putstr_fd(dynamic_error, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		status = EXIT_FAILURE;
	}
	free(dynamic_error);
	exit(status);
}
