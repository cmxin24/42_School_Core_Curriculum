NAME_1 = client
NAME_2 = server
LIB = libft
CFLAGS = -Wall -Wextra -Werror

SRC_1 = client_bonus.c
SRC_2 = server_bonus.c

OBJ_1 = $(SRC_1:.c=.o)
OBJ_2 = $(SRC_2:.c=.o)

LIB_PATH = ./$(LIB)

all : $(NAME_1) $(NAME_2)

$(NAME_1) : $(OBJ_1) $(LIB_PATH)/$(LIB).a
	cc $(CFLAGS) $^ -o $(NAME_1)

$(NAME_2) : $(OBJ_2) $(LIB_PATH)/$(LIB).a
	cc $(CFLAGS) $^ -o $(NAME_2)

$(LIB_PATH)/$(LIB).a:
	make -C $(LIB_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_1) $(OBJ_2)
	make -C $(LIB_PATH) clean

fclean: clean
	rm -f $(NAME_1) $(NAME_2)
	make -C $(LIB_PATH) fclean

re: fclean all