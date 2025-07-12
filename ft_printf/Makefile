NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror
SRC =	ft_print_csp.c		\
		ft_print_di.c		\
		ft_print_uxX.c		\
		ft_printf.c 		
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
