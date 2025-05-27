/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:20:15 by pafuente          #+#    #+#             */
/*   Updated: 2025/05/22 13:20:15 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static bool is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E');
}

static bool check_cell(t_game *game, int y, int x, t_counter *cnt)
{
	char c = game->map[y][x];

	if (!is_valid_char(c))
		return (false);
	if (c == PLAYER)
	{
		cnt->p++;
		game->player_x = x;
		game->player_y = y;
	}
	else if (c == COLLECTIBLE)
		cnt->c++;
	else if (c == EXIT)
		cnt->e++;
	if ((y == 0 || y == game->height - 1 || x == 0 || x == game->width - 1) && c != WALL)
		return (false);
	return (true);
}

bool check_line(t_game *game, int y, t_counter *cnt)
{
	const char *line = game->map[y];
	int x = 0;

	while (line[x])
	{
		if (!check_cell(game, y, x, cnt))
			return (false);
		x++;
	}
	return (true);
}

char **duplicate_map(char **original, int height)
{
	char **copy;
	int i = 0;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		error_exit("Error allocating memory for map copy");
	while (i < height)
	{
		copy[i] = ft_strdup(original[i]);
		if (!copy[i])
			error_exit("Error duplicating map line");
		i++;
	}
	copy[i] = NULL;
	return (copy);
}