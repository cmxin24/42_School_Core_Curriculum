NAME	=	ft_push_swap.a

CFLAGS	= 	-Wall -Werror -Wextra

SRC		=	push_swap.c 		\
			push_swap_utils.c 	\
			push_swap_utils_2.c

OBJ		=	$(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)
	ar rcs $(NAME) $(OBJ)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all