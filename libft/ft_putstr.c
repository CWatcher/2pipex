/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 21:07:56 by CWatcher          #+#    #+#             */
/*   Updated: 2021/08/23 21:07:57 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

ssize_t	ft_putstr(const char *s)
{
	return (write(STDOUT_FILENO, s, ft_strlen(s) * sizeof(*s)));
}
