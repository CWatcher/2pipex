SRC		= main.c
OBJ		= $(SRC:.c=.o)
CFLAGS	= -Wall -Wextra -Wpedantic -Werror
NAME	= pipex

$(NAME)	: $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all		: $(NAME)

clean	:
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
