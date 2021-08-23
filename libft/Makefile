# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/15 16:37:00 by CWatcher          #+#    #+#              #
#    Updated: 2021/08/20 13:44:07 by CWatcher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ft_free.c			\
		  ft_putendl.c		\
		  ft_putstr_fd.c	\
		  ft_reassign.c		\
		  ft_skipchr.c		\
		  ft_split.c		\
		  ft_strappend.c	\
		  ft_strchr.c		\
		  ft_strdup.c		\
		  ft_strjoin.c		\
		  ft_strlen.c		\
		  ft_strncmp.c		\
		  ft_strndup.c		\
		  get_next_line.c

OBJ		= $(SRC:.c=.o)
NAME	= libft.a
SO		= $(NAME:.a=.so)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs

$(NAME):	$(OBJ) Makefile
	$(AR) $@ $(OBJ)

%.o:	%.c Makefile
	$(CC) $(CFLAGS) -MMD -c $<

-include	$(SRC:.c=.d)

all:		$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(SRC:.c=.d)

fclean:		clean
	$(RM) $(NAME) $(SO)

re:			fclean all

so:
	$(CC) $(CFLAGS) -fpic -c $(SRC)
	$(CC) -shared -o $(SO) $(OBJ)

.PHONY:		all clean fclean re so
