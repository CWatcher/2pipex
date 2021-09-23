/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:04:17 by CWatcher          #+#    #+#             */
/*   Updated: 2021/09/25 23:49:58 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_io.h"
#include "fork_boost.h"
#include "exit_me.h"

static void	init(int argc, char *argv[], int *p_fd_in, int *p_fd_out)
{
	int		pipe_fds[2];

	if (argc < 5)
		exit_me(ft_strdup("The number of arguments is less than 4"));
	if (ft_strcmp(argv[1], "here_doc") == 0 && argc == 6)
	{
		if (pipe(pipe_fds) < 0)
			exit_me(ft_strjoin("Failed to pipe() on here_doc", argv[2]));
		*p_fd_out = pipe_fds[1];
		*p_fd_in = pipe_fds[0];
	}
	else
	{
		*p_fd_in = open(argv[1], O_RDONLY);
		*p_fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	}
	if (*p_fd_in < 0)
		exit_me(ft_strjoin("Failed to open:", argv[1]));
	if (*p_fd_out < 0)
		exit_me(ft_strjoin("Failed to open:", argv[argc - 1]));
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fd_in;
	int	fd_out;
	int	cmd_offset;
	int	status;

	init(argc, argv, &fd_in, &fd_out);
	cmd_offset = 2;
	if (ft_strcmp(argv[1], "here_doc") == 0 && argc == 6)
	{
		fork_heredoc(argv[2], fd_out);
		fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (fd_out < 0)
			exit_me(ft_strjoin("Failed to open:", argv[argc - 1]));
		cmd_offset = 3;
	}
	waitpid(fork_pipeline(argv + cmd_offset, envp, fd_in, fd_out), &status, 0);
	return (WEXITSTATUS(status));
}
