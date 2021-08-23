#include <unistd.h>
#include "libft.h"
#include "exit_me.h"
#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	char		*s;
	const char	*limiter = argv[1];
	int			r;

	if (argc != 2)
		exit_me(ft_strdup("heredoc: an argument is needed"));
	ft_putstr("> ");
	r = get_next_line(STDIN_FILENO, &s);
	while (r > 0 && ft_strncmp(limiter, s, ft_strlen(limiter) + 1) != 0)
	{
		if (ft_putendl(s) < 0)
			exit_me(ft_strdup("heredoc: failed to write()"));
		s = ft_free(s);
		ft_putstr("> ");
		r = get_next_line(STDIN_FILENO, &s);
	}
	s = ft_free(s);
	if (r < 0)
		exit_me(ft_strdup("heredoc: failed to get_next_line()"));
}
