#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include "MLX42/MLX42.h"
#define WIDTH 256
#define HEIGHT 256


# define TILE_SIZE 64

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img_wall;
	mlx_image_t	*img_floor;
	mlx_image_t	*img_player;
	mlx_image_t	*img_exit;
	mlx_image_t	*img_collect;
	char		**map;
	int			width;
	int			height;
	int			player_x;
	int			player_y;
	int			moves;
	int			collectibles;
}	t_game;

// Map
// char	**read_map(const char *file, t_game *game);
// bool	validate_map(t_game *game);
// bool	validate_path(t_game *game);
// void	free_map(char **map);

// // Init y render
// void	init_game(t_game *game);
// void	load_textures(t_game *game);
// void	render_map(t_game *game);

// // Juego
// void	move_player(t_game *game, int dx, int dy);
// void	handle_input(mlx_key_data_t keydata, void *param);

// // Utilidades
// void	error_exit(const char *msg);
// void	close_game(t_game *game);

#endif