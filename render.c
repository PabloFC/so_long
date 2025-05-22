/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:47:06 by pafuente          #+#    #+#             */
/*   Updated: 2025/05/15 12:47:29 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_tile(t_game *game, int x, int y)
{
	char	tile = game->map[y][x];

	if (tile == WALL)
		mlx_image_to_window(game->mlx, game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
	else
		mlx_image_to_window(game->mlx, game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
	if (tile == COLLECTIBLE)
		mlx_image_to_window(game->mlx, game->img_collect, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == EXIT)
		mlx_image_to_window(game->mlx, game->img_exit, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->mlx, game->img_player,
		game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
}


