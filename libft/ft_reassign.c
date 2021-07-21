#include <stdlib.h>

void	ft_reassign(void **p, void *new_address)
{
	free(*p);
	*p = new_address;
}
