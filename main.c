#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h> //debug
#include "libft.h"
#include "exit_me.h"

char	*find_value(char *vars[], char *var_name_with_delimiter)
{
	const ssize_t	var_name_w_d_l = ft_strlen(var_name_with_delimiter);

	while (*vars && ft_strncmp(*vars, var_name_with_delimiter, var_name_w_d_l))
		vars++;
	if (!*vars)
		return (NULL);
	return (*vars + var_name_w_d_l);
}
char	*get_exec_pathname(const char *filename, const char *path_var)
{
	char **const	search_dirs = ft_split(path_var, ':');
	char			*pathname;
	char			*found_pathname;
	char			**dir;
	int				r;

	dir = search_dirs;
	r = -1;
	found_pathname = ft_strdup(filename);
	while (*dir && r == -1)
	{
		if ((*dir)[ft_strlen(*dir)] != '/')
			ft_strappend(dir, "/");
		pathname = ft_strjoin(*dir, filename);
		r = access(pathname, X_OK);
		if (r == 0 || errno != ENOENT)
			ft_reassign((void **)&found_pathname, pathname);
		else
			pathname = ft_free(pathname);
		dir++;
	}
	ft_freestrs(search_dirs);
	return (found_pathname);
}
void	run_cmd(const char *cmd, char *envp[])
{
	char	**argv;
	char	*pathname;

	argv = ft_split(cmd, ' ');
	if (ft_strchr(argv[0], '/'))
		pathname = ft_strdup(argv[0]);
	else
		pathname = get_exec_pathname(argv[0], find_value(envp, "PATH="));
	execve(pathname, argv, envp);
	ft_freestrs(argv);
	exit_me(pathname); //TODO free pathname
}
void	fork_cmd(const char *cmd, char *envp[], int fd_in, int fd_out)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (fd_in >= 0 && dup2(fd_in, STDIN_FILENO) != STDIN_FILENO)
			exit_me(ft_strjoin("fork_cmd(): failed to dup2 on ", cmd));
		if (fd_out >= 0 && dup2(fd_out, STDOUT_FILENO) != STDOUT_FILENO)
			exit_me("fork_cmd(): failed to dup2");
	}
	close(fd_in);
	close(fd_out);
	errno = 0;
	if (pid == 0)
		run_cmd(cmd, envp);
	if (pid < 0)
		exit_me("Failed to fork()"); //TODO print argument on error
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fd_in;
	int	fd_out;
	int pipe_fds[2];

	if (argc != 5)
		exit_me("The number of arguments is not equal to 4");
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
		exit_me(ft_strjoin("Failed to open ", argv[1])); //not a leak (pointer is not lost). Tested by valgrind and andress sanitizer
	if (pipe(pipe_fds) < 0)
		exit_me("Failed to pipe()");
	fd_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_out < 0)
		exit_me("Failed to open file2");
	fork_cmd(argv[2], envp, fd_in, pipe_fds[1]);
	fork_cmd(argv[3], envp, pipe_fds[0], fd_out);
	wait(NULL);
	wait(NULL);
}
