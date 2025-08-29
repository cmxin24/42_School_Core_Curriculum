NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror -Iincludes

SRC_PATH = srcs
SRC =	ft_print_csp.c		\
		ft_print_di.c		\
		ft_print_uxX.c		\
		ft_printf.c 		

OBJ = $(addprefix $(SRC_PATH)/, $(SRC:.c=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: $(SRC_PATH)/%.clean
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
