# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/25 05:39:35 by CWatcher          #+#    #+#              #
#    Updated: 2021/08/28 12:38:51 by CWatcher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= fork_cmd.c	\
			  exit_me.c
MAIN		= main.c
MAIN_B		= main_bonus.c
OBJ			= $(SRC:.c=.o)
OBJ_B		= $(SRC_B:.c=.o)
MAIN_OBJ	= $(MAIN:.c=.o)
MAIN_B_OBJ	= $(MAIN_B:.c=.o)
CFLAGS	= -Wall -Wextra -Wpedantic -Werror -g -fsanitize=address
NAME	= pipex
LIB		= ft
LIBD	= lib$(LIB)
LIBA	= $(LIBD)/lib$(LIB).a

all		: $(NAME)

%.o		: %.c Makefile
	$(CC) $(CFLAGS) -I$(LIBD) -MMD -c $<

-include $(SRC:.c=.d) $(MAIN:.c=.d) $(MAIN_B:.c=.d)

force	:

$(LIBA)	: force
	make -C $(LIBD) CC='$(CC)' CFLAGS='$(CFLAGS)'

$(NAME)	: Makefile $(LIBA) $(OBJ) $(MAIN_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(MAIN_OBJ) $(OBJ) $(LIBA)

bonus	: Makefile $(LIBA) $(OBJ) $(OBJ_B) $(MAIN_B_OBJ)
	$(CC) $(CFLAGS) -o bonus $ $(MAIN_B_OBJ) $(OBJ_B) $(OBJ) $(LIBA)
	ln -f bonus pipex

clean	:
	make -C $(LIBD) clean
	$(RM) $(SRC:.c=.d) $(SRC_B:.c=.d) $(MAIN:.c=.d) $(MAIN_B:.c=.d)
	$(RM) $(OBJ) $(OBJ_B) $(MAIN_OBJ) $(MAIN_B_OBJ)

fclean	: clean
	$(RM) $(LIBA)
	$(RM) $(NAME) bonus

re		: fclean all

.PHONY	: all clean fclean re force
