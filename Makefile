# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 13:31:42 by lduchemi          #+#    #+#              #
#    Updated: 2024/10/10 14:52:35 by lduchemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @gcc -Wall -Wextra -Werror -g
RM = @rm -f
NAME = cub3D
SRC =	./src/ft_check.c \
		./src/ft_exec.c \
		./src/ft_exec2.c \
		./src/free.c \
		./src/ft_movement.c \
		./src/ft_movement2.c \
		./src/ft_print.c \
		./src/ft_split.c \
		./src/get_image.c \
		./src/get_image2.c \
		./src/get_map.c \
		./src/get_texture.c \
		./src/gnl.c \
		./src/init.c \
		./src/main.c \
		./src/minimap.c \
		./src/on_action.c \
		./src/parsing.c \
		./src/utils.c \
		./src/utils2.c

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
