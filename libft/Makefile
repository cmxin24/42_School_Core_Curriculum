NAME = libft.a
SOURCE = $(wildcard *.c)
CFLAGS = -Wall -Wextra -Werror
OBJECT = $(SOURCE:.c=.o)

.PHONY: clean fclean re all

all: $(NAME)

$(NAME): $(OBJECT)
	ar rcs $(NAME) $(OBJECT)

%o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all