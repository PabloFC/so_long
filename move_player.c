/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:58:48 by pafuente          #+#    #+#             */
/*   Updated: 2025/05/15 13:58:50 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x = game->player_x + dx;
	int		new_y = game->player_y + dy;
	char	tile = game->map[new_y][new_x];

	if (tile == WALL)
		return;
	if (tile == COLLECTIBLE)
	{
		game->collectibles--;
		game->map[new_y][new_x] = FLOOR;
	}
	if (tile == EXIT)
	{
		if (game->collectibles == 0)
		{
			ft_printf("¡Has ganado en %d movimientos!\n", ++game->moves);
			close_game(game);
		}
		return;
	}
	// Actualiza posición del jugador
	game->map[game->player_y][game->player_x] = FLOOR;
	game->map[new_y][new_x] = PLAYER;
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf("Movimientos: %d\n", game->moves);
	render_map(game);
}
