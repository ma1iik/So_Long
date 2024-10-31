NAME = so_long
LIB_NAME = so_long.a
CC = gcc
FLAGS = -Wall -Wextra -Werror -g -I/home/ma1iik/minilibx-linux

SRC =	so_long.c \
		move_up.c \
		move_down.c \
		move_right.c \
		move_left.c \
		move.c \
		errors.c \
		parsing.c \

AR = ar -rcs
OBJ = $(addprefix src/,$(SRC:.c=.o))
OS := $(shell uname)

ifeq ($(OS), Darwin)  # macOS
	MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
else  # Linux/WSL
	MLX_FLAGS = /home/ma1iik/minilibx-linux/libmlx.a -lXext -lX11 -lbsd -lm
endif

src/%.o: src/%.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	mv libft/libft.a src/$(LIB_NAME)
	$(AR) src/$(LIB_NAME) $(OBJ)
	$(CC) src/$(LIB_NAME) -o $(NAME) $(MLX_FLAGS)


clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean	
	rm -f $(NAME) src/$(LIB_NAME)

re: fclean all
