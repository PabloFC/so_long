# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 13:05:32 by pafuente          #+#    #+#              #
#    Updated: 2025/05/09 14:16:05 by pafuente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = MLX42
MLX_FLAGS = -L$(MLX_DIR)/build -lmlx42 -ldl -lm -lglfw -pthread
INCLUDES = -I./include -I$(MLX_DIR)/include

SRC = src/main.c src/map.c src/render.c src/init.c src/game.c src/utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@cmake -S $(MLX_DIR) -B $(MLX_DIR)/build
	@cmake --build $(MLX_DIR)/build
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS) $(INCLUDES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	cmake --build $(MLX_DIR)/build --target clean


re: fclean all

.PHONY: all clean fclean re
