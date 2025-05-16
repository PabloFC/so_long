/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:26:10 by pafuente          #+#    #+#             */
/*   Updated: 2025/05/15 13:27:35 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_input(mlx_key_data_t keydata, void *param)
{
	t_game	*game = (t_game *)param;

	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		close_game(game);
	else if (keydata.key == MLX_KEY_W)
		move_player(game, 0, -1);
	else if (keydata.key == MLX_KEY_S)
		move_player(game, 0, 1);
	else if (keydata.key == MLX_KEY_A)
		move_player(game, -1, 0);
	else if (keydata.key == MLX_KEY_D)
		move_player(game, 1, 0);
}

void	handle_input(mlx_key_data_t keydata, void *param)
{
	t_game	*game = (t_game *)param;

	if (keydata.action != MLX_PRESS)
		return;

	if (keydata.key == MLX_KEY_ESCAPE)
		close_game(game);
	else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		move_player(game, 0, -1);
	else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		move_player(game, 0, 1);
	else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		move_player(game, -1, 0);
	else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		move_player(game, 1, 0);
}

void	close_game(t_game *game)
{
	if (game->mlx)
		mlx_terminate(game->mlx);
	free_map(game->map);
	exit(EXIT_SUCCESS);
}
