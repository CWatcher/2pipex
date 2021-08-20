/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:01:39 by CWatcher          #+#    #+#             */
/*   Updated: 2021/07/21 18:05:29 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	size_t	l;
	char	*d;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (l < n)
		n = l;
	d = malloc((n + 1) * sizeof(char));
	if (!d)
		return (NULL);
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		++i;
	}
	d[n] = '\0';
	return (d);
}
