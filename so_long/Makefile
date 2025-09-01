NAME	:= so_long
CFLAGS	:= -O3 -ffast-math -Wextra -Wall -Werror -Wunreachable-code
LIBMLX	:= ./lib/MLX42
MYLIB	:= lib

HEADERS	:= -I ./include -I $(LIBMLX)/include
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

MYLIB_PATH = ./$(MYLIB)

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
    LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
endif

ifeq ($(UNAME), Darwin)
    LIBS := $(LIBMLX)/build/libmlx42.a -lglfw -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
endif

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS) $(MYLIB_PATH)/$(MYLIB).a
	@$(CC) $(OBJS) $(MYLIB_PATH)/libft.a $(LIBS) -o $(NAME)

$(MYLIB_PATH)/$(MYLIB).a:
	make -C $(MYLIB_PATH)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	make -C $(MYLIB_PATH) clean

fclean: clean
	@rm -rf $(NAME)
	make -C $(MYLIB_PATH) fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx