/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 01:19:41 by CWatcher          #+#    #+#             */
/*   Updated: 2021/09/25 23:51:36 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

int				ft_get_next_line(int fd, char **ln);
void			ft_putchar_fd(char c, int fd);
ssize_t			ft_putstr(const char *s);
void			ft_putstr_fd(const char *s, int fd);
ssize_t			ft_putendl(const char *s);
ssize_t			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

#endif
