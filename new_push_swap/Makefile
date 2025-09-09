NAME		=	push_swap
CHECKER		=	checker


CFLAGS		= 	-Wall -Werror -Wextra -Iincludes

LIBFT		=	libft.a
LIB_DIR		=	lib/libft

PRINTF		=	printf.a
PTF_DIR		=	lib/printf

SRCS 		:=	$(filter-out ./src/checker/%, $(shell find ./src -iname "*.c"))
OBJ			:= $(SRCS:%.c=build/push_swap/%.o)

SRCS_SHARE	:= $(filter-out ./src/push_swap/main.c, $(SRCS))
SHARE_OBJ	:= $(SRCS_SHARE:%.c=build/push_swap/%.o)

CHECKER_SRC	:=	$(shell find ./src/checker -iname "*.c")
CHECKER_OBJ	:=	$(CHECKER_SRC:%.c=build/checker/%.o)

.PHONY: build all bonus clean fclean re

build:
	mkdir -p build/push_swap build/checker build/get_next_line

all: build $(NAME) $(LIB_DIR)/$(LIBFT) $(PTF_DIR)/$(PRINTF)

$(NAME): $(OBJ) $(LIB_DIR)/$(LIBFT) $(PTF_DIR)/$(PRINTF)
	cc $(CFLAGS) $^ -o $@

bonus: build $(CHECKER)

$(CHECKER): $(CHECKER_OBJ) $(SHARE_OBJ) $(LIB_DIR)/$(LIBFT) $(PTF_DIR)/$(PRINTF) 
	cc $(CFLAGS) $^ -o $@

build/push_swap/%.o: %.c
	@mkdir -p $(dir $@)
	cc $(CFLAGS) -c $< -o $@

build/checker/%.o: %.c
	@mkdir -p $(dir $@)
	cc $(CFLAGS) -c $< -o $@

$(LIB_DIR)/$(LIBFT):
	make -C $(LIB_DIR)

$(PTF_DIR)/$(PRINTF):
	make -C $(PTF_DIR)

clean: 
	rm -rf build
	make -C $(LIB_DIR) clean
	make -C $(PTF_DIR) clean

fclean: clean
	rm -f $(NAME) $(CHECKER)
	make -C $(LIB_DIR) fclean
	make -C $(PTF_DIR) fclean

re: fclean all