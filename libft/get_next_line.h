/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 01:19:41 by CWatcher          #+#    #+#             */
/*   Updated: 2020/12/17 14:46:40 by cwatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <sys/types.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32767
# endif

# ifndef FD_MAX
#  define FD_MAX 255
# endif

# if BUFFER_SIZE == 0 || FD_MAX == 0
#  error "ISO C forbids zero-size array"
# endif

int				get_next_line(int fd, char **ln);

typedef struct s_buffer
{
	char		dat[BUFFER_SIZE + 1];
	ssize_t		i;
	ssize_t		n;
}				t_buffer;

typedef struct s_str
{
	char		*p;
	size_t		n;
}				t_str;

#endif
