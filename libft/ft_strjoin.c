/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 10:32:52 by CWatcher          #+#    #+#             */
/*   Updated: 2020/12/20 17:32:04 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *s0;
	char *s;

	if ((!s1 && !s2)
		|| !(s0 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	s = s0;
	while (s1 && *s1)
		*s++ = *s1++;
	while (s2 && *s2)
		*s++ = *s2++;
	*s = '\0';
	return (s0);
}
