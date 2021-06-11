SRC		= main.c
OBJ		= $(SRC:.c=.o)
CFLAGS	= -Wall -Wextra -Wpedantic -Werror
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

clean	:
	make -C $(LIBD) clean
	$(RM) $(OBJ) $(SRC:.c=.d)

fclean	: clean
	$(RM) $(LIBA)
	$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re force
