SRC			= fork_cmd.c	\
			  exit_me.c
MAIN		= main.c
MAIN_B		= main_bonus.c
OBJ			= $(SRC:.c=.o)
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

bonus	: Makefile $(LIBA) $(OBJ) $(MAIN_B_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(MAIN_B_OBJ) $(OBJ) $(LIBA)

clean	:
	make -C $(LIBD) clean
	$(RM) $(SRC:.c=.d) $(MAIN:.c=.d) $(MAIN_B:.c=.d)
	$(RM) $(OBJ) $(MAIN_OBJ) $(MAIN_B_OBJ)

fclean	: clean
	$(RM) $(LIBA)
	$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re force bonus
