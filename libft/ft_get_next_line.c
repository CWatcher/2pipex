/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 23:46:20 by CWatcher          #+#    #+#             */
/*   Updated: 2021/08/20 04:53:25 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_get_next_line.h"

static ssize_t	set(ssize_t *pn, int n)
{
	*pn = n;
	return (*pn);
}

static void	*set_p(void **pp, void *p)
{
	*pp = p;
	return (*pp);
}

int	ft_get_next_line(int fd, char **ln)
{
	static t_buffer	b[FD_MAX + 1];
	t_str			s;
	size_t			j;

	if (!ln || set_p((void **)ln, NULL) || fd < 0 || fd > FD_MAX)
		return (-1);
	s.n = 0;
	while (0 < b[fd].n || 0 <= set(&b[fd].n, read(fd, b[fd].dat, BUFFER_SIZE)))
	{
		if (!set_p((void **)&s.p, malloc(s.n + b[fd].n + 1)))
			return (-1);
		j = -1;
		while (++j < s.n)
			s.p[j] = (*ln)[j];
		free(*ln);
		while (b[fd].n && b[fd].dat[b[fd].i++] != '\n' && b[fd].n--)
			s.p[s.n++] = b[fd].dat[b[fd].i - 1];
		s.p[s.n] = '\0';
		b[fd].i *= b[fd].n != 1;
		if (set_p((void **)ln, s.p) && (b[fd].n || !b[fd].i))
			return (b[fd].n-- > 0);
		b[fd].i = 0;
	}
	return (-1);
}
