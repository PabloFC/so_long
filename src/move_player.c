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
	int		new_x;
	int		new_y;
	char	tile;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	tile = game->map[new_y][new_x];
	if (tile == WALL)
		return ;
	if (tile == COLLECTIBLE)
	{
		game->collectibles--;
		game->map[new_y][new_x] = FLOOR;
	}
	if (tile == EXIT && game->collectibles == 0)
	{
		ft_printf("You have won in %d moves!\n", ++game->moves);
		close_game(game);
	}
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	render_map(game);
}
