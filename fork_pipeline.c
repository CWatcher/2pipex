/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:04:17 by CWatcher          #+#    #+#             */
/*   Updated: 2021/12/10 19:56:50 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "fork_boost.h"
#include "exit_me.h"
#include <fcntl.h>

pid_t fork_pipeline(char *cmds[], char *envp[], int fd_in, char *filename_out)
{
	int pipe_fds[2];

	while (*(cmds + 2))
	{
		if (pipe(pipe_fds) < 0)
			exit_me(ft_strjoin("Failed to pipe() on:", *cmds));
		fork_cmd(*cmds, envp, fd_in, pipe_fds[1]);
		fd_in = pipe_fds[0];
		cmds++;
	}
	int fd_out = open(filename_out, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd_out < 0)
		exit_me(ft_strjoin("Failed to open:", filename_out));
	return (fork_cmd(*cmds, envp, fd_in, fd_out));
}
