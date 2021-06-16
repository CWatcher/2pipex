/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:32:57 by CWatcher          #+#    #+#             */
/*   Updated: 2021/06/15 18:46:56 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <sys/types.h>

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
ssize_t			ft_strlen(const char *s);
ssize_t			ft_strnlen(const char *s, ssize_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strdup(const char *s);
char			*ft_strndup(const char *s, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s, const char *s2);
char			*ft_strnstr(const char *s, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(char *str);
int				ft_atoi_skip(char **ps);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(char c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strappend(char **ps, const char *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_skipchr(const char *s, char delim);
char			*ft_skipchrs(const char *s, const char *delim);
char			*ft_skipwd(const char *s, char delim);
char			**ft_split(char const *s, char c);
char			**ft_freestrs(char **ps);
char			*ft_itoa(int n);
char			*ft_ulltoa_base(unsigned long long int num, unsigned char b);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
ssize_t			ft_putc(int c);
ssize_t			ft_putcn(char c, ssize_t n);
void			ft_putchar_fd(char c, int fd);
ssize_t			ft_puts(const char *s);
ssize_t			ft_putsn(const char *s, ssize_t n);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)
					(void *));

int				min(int x, int y);
int				max(int x, int y);
int				sign(int x);
void			ft_swap(int *px, int *py);
void			ft_swap_double(double *px, double *py);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32768
# endif

# ifndef FD_MAX
#  define FD_MAX 255
# endif

# if BUFFER_SIZE == 0 || FD_MAX == 0
#  error "ISO C forbids zero-size array"
# endif

void			*ft_free(void *pp);

int				get_next_line(int fd, char **ln);
#endif
