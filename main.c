/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:04:17 by CWatcher          #+#    #+#             */
/*   Updated: 2021/12/10 16:26:38 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "libft.h"
#include "exit_me.h"
#include "fork_boost.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		fd_in;
	int		fd_out;
	int		pipe_fds[2];
	pid_t	last_process;
	int		status;

	if (argc != 5)
		exit_me(ft_strdup("The number of arguments is not equal to 4"));
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
		exit_me(ft_strjoin("Failed to open:", argv[1]));
	if (pipe(pipe_fds) < 0)
		exit_me(ft_strdup("Failed to pipe()"));
	fd_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_out < 0)
		exit_me(ft_strjoin("Failed to open:", argv[4]));
	fork_cmd(argv[2], envp, fd_in, pipe_fds[1]);
	last_process = fork_cmd(argv[3], envp, pipe_fds[0], fd_out);
	waitpid(last_process, &status, 0);
	// while (wait(NULL) > 0)
	// 	;
	while (1)
	{
		pid_t pid = wait(&status);
		if (pid <= 0)
			break;
	}
	return (WEXITSTATUS(status));
}
