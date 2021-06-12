#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>	//UNAUTH
#include "libft.h"

void	run_cmd(const char *cmd, char *const *envp)
{
	char *argv[] = {".", NULL};
	char *path = ft_strjoin("/bin/", cmd);
	int r =	execve(path, argv, envp);
	path = ft_free(path);
	if (r < 0)
	{
		perror("Failed to execve()");
		exit(errno);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc != 5)
	{
		puts("Error:\nThe number of arguments is not equal to 4"); //UNAUTHORIZED
		exit(4);
	}
	run_cmd(argv[2], envp);
}
