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

static bool	is_valid_char(char c)
{
	return (c == '0'
		|| c == '1'
		|| c == 'P'
		|| c == 'C'
		|| c == 'E');
}

bool	check_line(t_game *game, int y, t_counter *cnt)
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
			cnt->p++;
			game->player_x = x;
			game->player_y = y;
		}
		else if (line[x] == COLLECTIBLE)
			cnt->c++;
		else if (line[x] == EXIT)
			cnt->e++;
		if ((y == 0 || y == game->height - 1
				|| x == 0 || x == game->width - 1)
			&& line[x] != WALL)
			return (false);
		x++;
	}
	return (true);
}

void	flood_fill_collect(char **map, t_dim dim, t_coord pt)
{
	if (pt.x < 0 || pt.x >= dim.w
		|| pt.y < 0 || pt.y >= dim.h)
		return ;
	if (map[pt.y][pt.x] == '1'
		|| map[pt.y][pt.x] == 'V'
		|| map[pt.y][pt.x] == 'E')
		return ;
	map[pt.y][pt.x] = 'V';
	flood_fill_collect(map, dim, (t_coord){pt.x + 1, pt.y});
	flood_fill_collect(map, dim, (t_coord){pt.x - 1, pt.y});
	flood_fill_collect(map, dim, (t_coord){pt.x, pt.y + 1});
	flood_fill_collect(map, dim, (t_coord){pt.x, pt.y - 1});
}

void	flood_fill_exit(char **map, t_dim dim, t_coord pt)
{
	if (pt.x < 0 || pt.x >= dim.w
		|| pt.y < 0 || pt.y >= dim.h)
		return ;
	if (map[pt.y][pt.x] == '1'
		|| map[pt.y][pt.x] == 'V')
		return ;
	if (map[pt.y][pt.x] == 'E')
	{
		map[pt.y][pt.x] = 'V';
		return ;
	}
	map[pt.y][pt.x] = 'V';
	flood_fill_exit(map, dim, (t_coord){pt.x + 1, pt.y});
	flood_fill_exit(map, dim, (t_coord){pt.x - 1, pt.y});
	flood_fill_exit(map, dim, (t_coord){pt.x, pt.y + 1});
	flood_fill_exit(map, dim, (t_coord){pt.x, pt.y - 1});
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
