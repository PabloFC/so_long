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

bool	is_valid_char(char c);

bool	check_line(t_game *game, int y, int *p, int *c, int *e)
{
	const char	*line;
	int			x;

	line = game->map[y];
	x = 0;
	while (line[x])
	{
		if (!is_valid_char(line[x]))
			return (false);
		if (line[x] == PLAYER)
		{
			(*p)++;
			game->player_x = x;
			game->player_y = y;
		}
		else if (line[x] == COLLECTIBLE)
			(*c)++;
		else if (line[x] == EXIT)
			(*e)++;
		if ((y == 0 || y == game->height - 1
				|| x == 0 || x == game->width - 1)
			&& line[x] != WALL)
			return (false);
		x++;
	}
	return (true);
}

bool	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E');
}

void	flood_fill_collect(char **map, int w, int h, int x, int y)
{
	if (x < 0 || x >= w || y < 0 || y >= h)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill_collect(map, w, h, x + 1, y);
	flood_fill_collect(map, w, h, x - 1, y);
	flood_fill_collect(map, w, h, x, y + 1);
	flood_fill_collect(map, w, h, x, y - 1);
}

void	flood_fill_exit(char **map, int w, int h, int x, int y)
{
	if (x < 0 || x >= w || y < 0 || y >= h)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'V';
		return ;
	}
	map[y][x] = 'V';
	flood_fill_exit(map, w, h, x + 1, y);
	flood_fill_exit(map, w, h, x - 1, y);
	flood_fill_exit(map, w, h, x, y + 1);
	flood_fill_exit(map, w, h, x, y - 1);
}

char	**duplicate_map(char **original, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		error_exit("Error allocating memory for map copy");
	i = 0;
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
