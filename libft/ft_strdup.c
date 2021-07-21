/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 21:03:38 by cwatcher          #+#    #+#             */
/*   Updated: 2020/11/16 13:01:25 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	n;
	size_t	i;
	char	*d;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	i = -1;
	d = malloc((n + 1) * sizeof(char));
	while (d && ++i <= n)
		d[i] = s[i];
	return (d);
}
