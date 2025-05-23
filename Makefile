# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 13:05:32 by pafuente          #+#    #+#              #
#    Updated: 2025/05/14 13:08:37 by pafuente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MLX_DIR = MLX42
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -Iinclude -I$(LIBFT_DIR) -I$(MLX_DIR)/include

# Auto-generate list of source files (.c)
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

# Detect operating system
UNAME_S := $(shell uname -s)

# ========================
# FLAGS TO COMPILE
# ========================
ifeq ($(UNAME_S),Darwin)
	# macOS
	MLX_FLAGS = -L$(MLX_DIR)/build -lmlx42 -ldl -lm -lglfw -framework Cocoa -framework OpenGL -framework IOKit
else
	# Linux (WSL o Linux nativo)
	MLX_FLAGS = -L$(MLX_DIR)/build -lmlx42 -ldl -lm -lglfw -pthread

endif

# ========================
# RULES
# ========================

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@cmake -S $(MLX_DIR) -B $(MLX_DIR)/build
	@cmake --build $(MLX_DIR)/build
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME) $(MLX_FLAGS)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
