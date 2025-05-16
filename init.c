/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:43:17 by pafuente          #+#    #+#             */
/*   Updated: 2025/05/13 12:29:07 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_game(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "so_long", false);
	if (!game->mlx)
		error_exit("Error initializing MLX");
	game->moves = 0;
}

void load_textures(t_game *game)
{
	mlx_texture_t *tex;

	tex = mlx_load_png("assets/wall.png");
	game->img_wall = mlx_texture_to_image(game->mlx, tex);
	mlx_delete_texture(tex);

	tex = mlx_load_png("assets/floor.png");
	game->img_floor = mlx_texture_to_image(game->mlx, tex);
	mlx_delete_texture(tex);

	tex = mlx_load_png("assets/player.png");
	game->img_player = mlx_texture_to_image(game->mlx, tex);
	mlx_delete_texture(tex);

	tex = mlx_load_png("assets/collect.png");
	game->img_collect = mlx_texture_to_image(game->mlx, tex);
	mlx_delete_texture(tex);

	tex = mlx_load_png("assets/exit.png");
	game->img_exit = mlx_texture_to_image(game->mlx, tex);
	mlx_delete_texture(tex);
}
