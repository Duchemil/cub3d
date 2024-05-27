# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 13:31:42 by lduchemi          #+#    #+#              #
#    Updated: 2024/05/27 15:11:39 by lduchemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @gcc -Wall -Wextra -Werror -g
RM = @rm -f
NAME = cub3D
SRC =	./src/ft_check.c \
		./src/ft_exec.c \
		./src/ft_movement.c \
		./src/ft_print.c \
		./src/main.c \
		./src/gnl.c \
		./src/on_action.c \
		./src/parsing.c \
		./src/utils.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) mlx/libmlx.a -lXext -lX11 -lm -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re:	fclean all
