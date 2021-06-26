#include <unistd.h>
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
	char **argv = ft_split(cmd, ' ');
	char **paths = ft_split(find_value(envp, "PATH="), ':');
	char	*path;
	int		r;

	r = -1;
	if (ft_strchr(argv[0], '/'))
		r =	execve(argv[0], argv, envp);
	else
		while (r == -1 && *paths)
		{
			if ((*paths)[ft_strlen(*paths)] != '/')
				ft_strappend(paths, "/");
			path = ft_strjoin(*paths, argv[0]);
			r =	execve(path, argv, envp);
			path = ft_free(path);
			paths++;
		}
	argv = ft_freestrs(argv);
	if (r == -1)
		exit_me("Failed to execve()"); //TODO print argument on which error occured
}
void	fork_cmd(const char *cmd, char *envp[])
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		run_cmd(cmd, envp);
	if (pid < 0)
		exit_me("Failed to fork()");  //TODO print argument on which error occured
}
int	main(int argc, char *argv[], char *envp[])
{
	if (argc != 5)
		exit_me("The number of arguments is not equal to 4");
	fork_cmd(argv[2], envp);
	fork_cmd(argv[3], envp);
}
