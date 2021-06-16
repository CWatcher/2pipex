#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>	//UNAUTH
#include "libft.h"

char	*find_value(char *vars[], char *var_name_with_delimiter)
{
	const ssize_t	var_name_w_d_l = ft_strlen(var_name_with_delimiter);

	while (*vars && ft_strncmp(*vars, var_name_with_delimiter, var_name_w_d_l))
		vars++;
	if (!*vars)
		return (NULL);
	return (*vars + var_name_w_d_l);
}
void	run_cmd(const char *cmd, char *paths[], char *envp[])
{
	char	**argv = ft_split(cmd, ' ');
	char	*path;

	int r =	execve(argv[0], argv, envp);
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
	{
		perror("Failed to execve()");
		exit(errno);
	}
}
void	print_strs(char *strs[])
{
	while (*strs)
	{
		printf("%s\n", *strs);
		strs++;
	}
}
int	main(int argc, char *argv[], char *envp[])
{
	if (argc != 5)
	{
		puts("Error:\nThe number of arguments is not equal to 4"); //UNAUTHORIZED
		exit(4);
	}
	print_strs(envp);
	char **paths = ft_split(find_value(envp, "PATH="), ':');
	run_cmd(argv[2], paths, envp);
}
