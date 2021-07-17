#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
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
void	run_cmd(const char *cmd, char *envp[])
{
	char	**argv = ft_split(cmd, ' ');
	char	**search_dirs = ft_split(find_value(envp, "PATH="), ':');
	char	**dir;
	char	*pathname;
	int		r;

	dir = search_dirs;
	r = -1;
	if (ft_strchr(argv[0], '/'))
		r =	execve(argv[0], argv, envp);
	else
		while (r == -1 && *dir)
		{
			if ((*dir)[ft_strlen(*dir)] != '/')
				ft_strappend(dir, "/");
			pathname = ft_strjoin(*dir, argv[0]);
			r =	execve(pathname, argv, envp);
			pathname = ft_free(pathname);
			dir++;
		}
	argv = ft_freestrs(argv);
	search_dirs = ft_freestrs(search_dirs);
	if (r == -1)
		exit_me("Failed to execve()"); //TODO print argument on which error occured
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
		exit_me("Failed to fork()");  //TODO print argument on which error occured
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fd_in;
	int	fd_out;

	if (argc != 5)
		exit_me("The number of arguments is not equal to 4");
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
		exit_me(ft_strjoin("Failed to open ", argv[1])); //TODO leak?
	fd_out = open(argv[4], O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_out < 0)
		exit_me("Failed to open file2");
	fork_cmd(argv[2], envp, fd_in, -1);
	fork_cmd(argv[3], envp, -1, fd_out);
	wait(NULL);
	wait(NULL);
}
