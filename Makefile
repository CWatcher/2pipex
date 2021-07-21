SRC		= main.c	\
		  exit_me.c
SRC_B	= main_bonus.c	\
		  exit_me.c
OBJ		= $(SRC:.c=.o)
OBJ_B	= $(SRC_B:.c=.o)
CFLAGS	= -Wall -Wextra -Wpedantic -Werror -g -fsanitize=address
NAME	= pipex
LIB		= ft
LIBD	= lib$(LIB)
LIBA	= $(LIBD)/lib$(LIB).a

all		: $(NAME)

%.o		: %.c Makefile
	$(CC) $(CFLAGS) -I$(LIBD) -MMD -c $<

-include $(SRC:.c=.d)force	:

$(LIBA)	: force
	make -C $(LIBD) CC='$(CC)' CFLAGS='$(CFLAGS)'

$(NAME)	: $(OBJ) $(LIBA) Makefile
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBA)

bonus	: $(OBJ_B) $(LIBA) Makefile
	$(CC) $(CFLAGS) -o $(NAME)_bonus $(OBJ_B) $(LIBA)

clean	:
	make -C $(LIBD) clean
	$(RM) $(OBJ) $(SRC:.c=.d)

fclean	: clean
	$(RM) $(LIBA)
	$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re force
