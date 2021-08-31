/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_multipipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:04:17 by CWatcher          #+#    #+#             */
/*   Updated: 2021/09/01 14:32:24 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "fork_boost.h"
#include "exit_me.h"

pid_t	fork_multipipe(char *cmds[], char *envp[], int fd_in, int fd_out)
{
	int		pipe_fds[2];

	while (*(cmds + 2))
	{
		if (pipe(pipe_fds) < 0)
			exit_me(ft_strjoin("Failed to pipe() on:", *cmds));
		fork_cmd(*cmds, envp, fd_in, pipe_fds[1]);
		fd_in = pipe_fds[0];
		cmds++;
	}
	return (fork_cmd(*cmds, envp, fd_in, fd_out));
}
