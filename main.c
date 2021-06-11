#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>	//UNAUTH
#include "libft.h"

int	main(int argc, char *argv[], char *envp[])
{
	if (argc != 5)
	{
		puts("Error:\nThe number of arguments is not equal to 4"); //UNAUTHORIZED
		exit(4);
	}
	char *argv1[] = {".", NULL};
	char *path1 = ft_strjoin("/bin/", argv[2]);
	int r =	execve(path1, argv1, envp);
	path1 = ft_free(path1);
	if (r < 0)
	{
		perror("Failed to execve()");
		exit(errno);
	}
}
