# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xin <xin@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/25 13:16:16 by xin               #+#    #+#              #
#    Updated: 2025/10/02 17:12:11 by xin              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

CFLAGS		= 	-Wall -Werror -Wextra -Iincludes

SRCS		=	src/main.c			\
				src/check_argv.c	\
				src/action.c		\
				src/dead.c			\
				src/init.c

OBJ			=	$(SRCS:src/%.c=build/%.o)

.PHONY: all build clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $^ -o $@

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	cc $(CFLAGS) -c $< -o $@

clean: 
	rm -rf build

fclean: clean
	rm -f $(NAME)

re: fclean all