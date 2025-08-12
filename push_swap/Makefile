NAME	=	ft_push_swap.a

CFLAGS	= 	-Wall -Werror -Wextra -Iincludes

SRC		=	$(wildcard srcs/*.c)

OBJ		=	$(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all