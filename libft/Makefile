# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 19:37:01 by misrailo          #+#    #+#              #
#    Updated: 2022/05/16 18:47:49 by misrailo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

NAME=libft.a

AR= ar -rc

FLAG=-Wall -Werror -Wextra 

SRC=	ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strchr.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strncmp.c \
		get_next_line.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_B)

fclean: clean
	rm -f $(NAME)

re: fclean all