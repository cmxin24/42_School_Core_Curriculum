# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xin <xin@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/25 13:16:16 by xin               #+#    #+#              #
#    Updated: 2025/10/07 17:08:26 by xin              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

BONUS		=	philo_bonus

CFLAGS		= 	-Wall -Werror -Wextra

SRCS		=	philo/src/main.c			\
				philo/src/check_argv.c		\
				philo/src/action.c			\
				philo/src/dead.c			\
				philo/src/init.c

OBJ			=	$(SRCS:philo/src/%.c=build/%.o)

SRCS_BONUS	=	philo_bonus/src/main_bonus.c		\
				philo_bonus/src/check_argv_bonus.c	\
				philo_bonus/src/action_bonus.c		\
				philo_bonus/src/dead_bonus.c		\
				philo_bonus/src/init_bonus.c

OBJ_BONUS	=	$(SRCS_BONUS:philo_bonus/src/%.c=build/%.o)

.PHONY: all build clean fclean re

all: philo/$(NAME)

philo/$(NAME): $(OBJ)
	cc $(CFLAGS) $^ -o $@

build/%.o: philo/src/%.c
	@mkdir -p $(dir $@)
	cc $(CFLAGS) -c $< -o $@

bonus: philo_bonus/$(BONUS)

philo_bonus/$(BONUS): $(OBJ_BONUS)
	cc $(CFLAGS) $^ -o $@

build/%.o: philo_bonus/src/%.c
	@mkdir -p $(dir $@)
	cc $(CFLAGS) -c $< -o $@

clean: 
	rm -rf build

fclean: clean
	rm -f philo/$(NAME)
	rm -f philo_bonus/$(BONUS)

re: fclean all