/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:05:01 by CWatcher          #+#    #+#             */
/*   Updated: 2021/08/25 12:43:10 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "libft.h"

static int	count_strs(char *strs[])
{
	int	n_strs;

	if (!strs)
		return (0);
	n_strs = 0;
	while (strs[n_strs])
		n_strs++;
	return (n_strs);
}

void	exit_me(char *dynamic_error, char *cmds[])
{
	int	status;

	if (ft_strncmp(cmds[0], "./heredoc", ft_strlen("./heredoc")) == 0
		&& count_strs(cmds) == 4)
		free(cmds[0]);
	if (!dynamic_error)
		exit(EXIT_SUCCESS);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (errno)
	{
		perror(dynamic_error);
		status = errno;
	}
	else
	{
		ft_putendl_fd(dynamic_error, STDERR_FILENO);
		status = EXIT_FAILURE;
	}
	free(dynamic_error);
	exit(status);
}
