/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:09:34 by pafuente          #+#    #+#             */
/*   Updated: 2025/05/15 14:08:05 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

// Standard libraries
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// External libraries
#include "MLX42/MLX42.h"
#include "libft.h"

// Window size
#define WIDTH 800
#define HEIGHT 600

// Tile size
#define TILE_SIZE 64

// Map tile characters
#define WALL '1'
#define FLOOR '0'
#define PLAYER 'P'
#define COLLECTIBLE 'C'
#define EXIT 'E'

// Structs
typedef struct s_game
{
	mlx_t *mlx;
	mlx_image_t *img_wall;
	mlx_image_t *img_floor;
	mlx_image_t *img_player;
	mlx_image_t *img_exit;
	mlx_image_t *img_collect;
	char **map;
	int width;
	int height;
	int player_x;
	int player_y;
	int moves;
	int collectibles;
} t_game;

typedef struct s_counter
{
	int p;
	int c;
	int e;
} t_counter;

typedef struct s_dim
{
	int w;
	int h;
} t_dim;

typedef struct s_coord
{
	int x;
	int y;
} t_coord;

// Function prototypes
void error_exit(const char *msg);
void init_game(t_game *game);
char **read_map(const char *file);
bool validate_map(t_game *game);
bool check_line(t_game *game, int y, t_counter *cnt);
char **duplicate_map(char **original, int height);
void flood_fill_collect(char **map, t_dim dim, t_coord pt);
void flood_fill_exit(char **map, t_dim dim, t_coord pt);
void render_map(t_game *game);
void handle_input(mlx_key_data_t keydata, void *param);
void close_game(t_game *game);
int count_rows(char **map);
void move_player(t_game *game, int dx, int dy);
bool load_textures(t_game *game);
void free_map(char **map);
bool check_elements_count(t_counter *cnt);

#endif