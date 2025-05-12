# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 13:05:32 by pafuente          #+#    #+#              #
#    Updated: 2025/05/12 11:47:19 by pafuente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = MLX42
MLX_FLAGS = -L$(MLX_DIR)/build -lmlx42 -ldl -lm -lglfw -pthread
INCLUDES = -Iinclude -I$(MLX_DIR)/include

SRC = main.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@cmake -S $(MLX_DIR) -B $(MLX_DIR)/build
	@cmake --build $(MLX_DIR)/build
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	cmake --build $(MLX_DIR)/build --target clean

re: fclean all

.PHONY: all clean fclean re
