
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 13:05:32 by pafuente          #+#    #+#              #
#    Updated: 2025/05/27 13:55:00 by pafuente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MLX_DIR = MLX42
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -Iinclude -I$(LIBFT_DIR) -I$(MLX_DIR)/include

SRC = src/main.c \
	  src/game.c \
	  src/init.c \
	  src/map.c \
	  src/map_utils.c \
	  src/flood_fill.c \
	  src/maps_checks.c \
	  src/move_player.c \
	  src/render.c \
	  src/utils.c

OBJ = main.o \
	  game.o \
	  init.o \
	  map.o \
	  map_utils.o \
	  flood_fill.o \
	  maps_checks.o \
	  move_player.o \
	  render.o \
	  utils.o

# ========================
# FLAGS TO COMPILE ACCORDING TO SYSTEM
# ========================

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
	MLX_FLAGS = -L$(MLX_DIR)/build -lmlx42 -ldl -lm -lglfw -framework Cocoa -framework OpenGL -framework IOKit
else
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

%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
