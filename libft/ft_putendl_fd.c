/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:45:31 by CWatcher          #+#    #+#             */
/*   Updated: 2021/08/26 11:43:16 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

ssize_t	ft_putendl_fd(char *s, int fd)
{
	ssize_t	r;

	r = write(fd, s, ft_strlen(s) * sizeof(*s));
	if (r < 0)
		return (-1);
	if (write(fd, "\n", sizeof(char)) < 0)
		return (-1);
	return (r + 1);
}
