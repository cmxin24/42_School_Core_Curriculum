# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/10 14:09:57 by meyu              #+#    #+#              #
#    Updated: 2025/09/10 18:03:19 by meyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CHECKER		=	checker

CFLAGS		= 	-Wall -Werror -Wextra -Iincludes

LIBFT		=	libft.a
LIB_DIR		=	lib/libft

PRINTF		=	printf.a
PTF_DIR		=	lib/printf

SRCS 		:=	src/push_swap/main.c					\
				src/push_swap/move.c					\
				src/push_swap/optimization.c			\
				src/push_swap/optimization_utils.c		\
				src/push_swap/sort_stack.c				\
				src/push_swap/sort_three.c				\
				src/push_swap/sort_one_and_two.c		\
				src/stack/data.c						\
				src/stack/data_utils.c					\
				src/stack/stack_init.c					\
				src/stack/stack_utils.c					\
				src/chunk/chunk.c 						\
				src/chunk/chunk_sort.c					\
				src/chunk/chunk_sort_untils.c 			\
				src/chunk/easy_sort.c					\
				src/operations/ft_push.c				\
				src/operations/ft_swap.c				\
				src/operations/ft_rotate.c				\
				src/operations/ft_reverse_rotate.c		\
				src/operations/operations.c				\
				src/operations/operation_print.c

OBJ := $(SRCS:src/%.c=build/push_swap/%.o)

CHECKER_SRC	:=	src/checker/checker_bonus.c				\
				src/checker/checker_utils_bonus.c		\
				src/stack/data.c						\
				src/stack/data_utils.c					\
				src/operations/ft_push.c				\
				src/operations/ft_swap.c				\
				src/operations/ft_rotate.c				\
				src/operations/ft_reverse_rotate.c		\
				src/stack/stack_init.c					\
				src/stack/stack_utils.c					\
				src/operations/operations.c

CHECKER_OBJ := $(CHECKER_SRC:src/%.c=build/checker/%.o)

.PHONY: all build bonus clean fclean re

all: $(NAME) $(LIB_DIR)/$(LIBFT) $(PTF_DIR)/$(PRINTF)

$(NAME): $(OBJ) $(LIB_DIR)/$(LIBFT) $(PTF_DIR)/$(PRINTF)
	cc $(CFLAGS) $^ -o $@

bonus: build $(CHECKER)

$(CHECKER): $(CHECKER_OBJ) $(LIB_DIR)/$(LIBFT) $(PTF_DIR)/$(PRINTF) 
	cc $(CFLAGS) $^ -o $@

build/push_swap/%.o: src/%.c
	@mkdir -p $(dir $@)
	cc $(CFLAGS) -c $< -o $@

build/checker/%.o: src/%.c
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