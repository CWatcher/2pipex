# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 13:28:54 by CWatcher          #+#    #+#              #
#    Updated: 2021/06/15 18:47:39 by CWatcher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC		= ft_strlen.c		\
		  ft_strncmp.c		\
		  ft_strndup.c		\
		  ft_strjoin.c		\
		  ft_strappend.c	\
		  ft_skipchr.c		\
		  ft_split.c		\
		  ft_free.c
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
	$(RM) $(OBJ) $(SRC:.c=.d)

fclean:		clean
	$(RM) $(NAME) $(SO)

re:			fclean all

so:
	$(CC) -fpic -c $(SRC)
	$(CC) -shared -o $(SO) $(OBJ)

.PHONY:		all clean fclean re so
