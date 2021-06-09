#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>	//UNAUTH

int	main(int argc, char *argv[], char *envp[])
{
	if (argc != 5)
	{
		puts("Error:\nThe number of arguments is not equal to 4"); //UNAUTHORIZED
		exit(4);
	}
	int r =	execve("/bin/", argv, envp);
	if (r < 0)
	{
		perror("Failed to execve()");
		exit(errno);
	}
}
