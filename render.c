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

void	render_map(t_game *game)
{
	int	x;
	int	y;
	char	tile;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			tile = game->map[y][x];
			if (tile == '1')
				mlx_image_to_window(game->mlx, game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == '0')
				mlx_image_to_window(game->mlx, game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'P')
				mlx_image_to_window(game->mlx, game->img_player, x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'C')
				mlx_image_to_window(game->mlx, game->img_collect, x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'E')
				mlx_image_to_window(game->mlx, game->img_exit, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
