/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:04:17 by CWatcher          #+#    #+#             */
/*   Updated: 2021/07/22 13:59:54 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "libft.h"
#include "fork_cmd.h"
#include "exit_me.h"


int	main(int argc, char *argv[], char *envp[])
{
	int	fd_in;
	int	fd_out;
	int	pipe_fds[2];
	int	i;

	if (argc < 5)
		exit_me(ft_strdup("The number of arguments is less than 4"));
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
		exit_me(ft_strjoin("Failed to open:", argv[1]));
	i = 1;
	fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_out < 0)
		exit_me(ft_strjoin("Failed to open:", argv[argc - 1]));
	while (++i < argc - 2)
	{
		if (pipe(pipe_fds) < 0)
			exit_me(ft_strjoin("Failed to pipe() on:", argv[i]));
		fork_cmd(argv[i], envp, fd_in, pipe_fds[1]);
		fd_in = pipe_fds[0];
	}
	fork_cmd(argv[i], envp, fd_in, fd_out);
	i = 1;
	while (++i < argc - 1)
		wait(NULL);
}
