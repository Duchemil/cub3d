# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 13:31:42 by lduchemi          #+#    #+#              #
#    Updated: 2024/05/17 17:09:11 by lduchemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = gcc -Wall -Wextra -Werror -g3
OBJS = ./src/main.c ./src/on_action.c ./src/cub3D.h ./src/ft_check.c
INCLUDES = -I/usr/include -Imlx

%.o: %.c
	$(CC) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) ./mlx/libmlx.a -lXext -lX11 -o $(NAME)

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
