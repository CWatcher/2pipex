/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:04:17 by CWatcher          #+#    #+#             */
/*   Updated: 2021/08/29 18:26:44 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"
#include "fork_cmd.h"
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

static void	get_put_heredoc(const char *limiter, int fd_out)
{
	char		*s;
	int			r;

	ft_putstr("> ");
	r = get_next_line(STDIN_FILENO, &s);
	while (r > 0 && ft_strncmp(limiter, s, ft_strlen(limiter) + 1) != 0)
	{
		r = ft_putendl_fd(s, fd_out);
		s = ft_free(s);
		if (r < 0)
			exit_me(ft_strdup("heredoc: failed to ft_putendl_fd()"));
		if (ft_putstr("> ") < 0)
			exit_me(ft_strdup("heredoc: failed to ft_putstr()"));
		r = get_next_line(STDIN_FILENO, &s);
	}
	s = ft_free(s);
	if (close(fd_out) != 0)
		exit_me(ft_strdup("Failed to close() in get_put_heredoc()"));
	if (r < 0)
		exit_me(ft_strdup("heredoc: failed to get_next_line()"));
}

static void	fork_heredoc(const char *limiter, int fd_out)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		get_put_heredoc(limiter, fd_out);
		exit_me(NULL);
	}
	else if (pid > 0)
	{
		if (close(fd_out) != 0)
			exit_me(ft_strdup("Failed to close() in fork_heredoc()"));
	}
	else if (pid < 0)
		exit_me(ft_strjoin("Failed to fork() on here_doc ", limiter));
}

static pid_t	fork_multipipe(char *cmds[], char *envp[], int fd_in, int fd_out)
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

int	main(int argc, char *argv[], char *envp[])
{
	int	fd_in;
	int	fd_out;
	int	i;
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
	waitpid(fork_multipipe(argv + cmd_offset, envp, fd_in, fd_out), &status, 0);
	i = 2;
	while (i < argc - 2)
	{
		wait(NULL);
		i++;
	}
	return (WEXITSTATUS(status));
}
