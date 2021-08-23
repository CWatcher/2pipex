#include <unistd.h>
#include <errno.h>
#include "libft.h"
#include "exit_me.h"

static char	*find_value(char *vars[], char *var_name_with_delimiter)
{
	const ssize_t	var_name_w_d_l = ft_strlen(var_name_with_delimiter);

	while (*vars && ft_strncmp(*vars, var_name_with_delimiter, var_name_w_d_l))
		vars++;
	if (!*vars)
		return (NULL);
	return (*vars + var_name_w_d_l);
}

static char	*get_exec_pathname(const char *filename, const char *path_var)
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

static void	run_cmd(const char *cmd, char *envp[])
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
	exit_me(pathname);
}

void	fork_cmd(const char *cmd, char *envp[], int fd_in, int fd_out)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (fd_in >= 0 && dup2(fd_in, STDIN_FILENO) != STDIN_FILENO)
			exit_me(ft_strjoin("failed to dup2 on:", cmd));
		if (fd_out >= 0 && dup2(fd_out, STDOUT_FILENO) != STDOUT_FILENO)
			exit_me(ft_strjoin("failed to dup2 on:", cmd));
	}
	if (fd_in != STDIN_FILENO)
		close(fd_in);
	if (fd_out != STDOUT_FILENO)
		close(fd_out);
	errno = 0;
	if (pid == 0)
		run_cmd(cmd, envp);
	if (pid < 0)
		exit_me(ft_strjoin("Failed to fork() on:", cmd));
}
