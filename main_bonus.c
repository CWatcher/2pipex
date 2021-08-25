/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:04:17 by CWatcher          #+#    #+#             */
/*   Updated: 2021/08/25 09:45:38 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "libft.h"
#include "fork_cmd.h"
#include "exit_me.h"

static void	init(int argc, char *argv[], int *p_fd_in, int *p_fd_out)
{
	if (argc < 5)
		exit_me(ft_strdup("The number of arguments is less than 4"));
	if (ft_strcmp(argv[1], "here_doc") == 0 && argc == 6)
	{
		*p_fd_in = 0;
		*p_fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
		argv[2] = ft_strjoin("./heredoc ", argv[2]);
		if (!argv[2])
			exit_me(ft_strdup("Failed to ft_strjoin()"));
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

static void	fork_multipipe(char *cmds[], char *envp[], int fd_in, int fd_out)
{
	int			pipe_fds[2];

	while (*(cmds + 2))
	{
		if (pipe(pipe_fds) < 0)
			exit_me(ft_strjoin("Failed to pipe() on:", *cmds));
		fork_cmd(*cmds, envp, fd_in, pipe_fds[1]);
		fd_in = pipe_fds[0];
		cmds++;
	}
	fork_cmd(*cmds, envp, fd_in, fd_out);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd_in;
	int		fd_out;
	int		i;

	init(argc, argv, &fd_in, &fd_out);
	fork_multipipe(argv + 2, envp, fd_in, fd_out);
	i = 2;
	while (i < argc - 1)
	{
		wait(NULL);
		i++;
	}
	if (ft_strcmp(argv[1], "here_doc") == 0 && argc == 6)
		free(argv[2]);
}
