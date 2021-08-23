/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 21:09:06 by CWatcher          #+#    #+#             */
/*   Updated: 2021/08/23 21:09:06 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

ssize_t	ft_putendl(const char *s)
{
	ssize_t	r;

	r = write(STDOUT_FILENO, s, ft_strlen(s) * sizeof(*s));
	if (r < 0)
		return (-1);
	if (write(STDOUT_FILENO, "\n", sizeof(char)) < 0)
		return (-1);
	return (r + 1);
}
