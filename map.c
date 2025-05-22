/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:35:37 by pafuente          #+#    #+#             */
/*   Updated: 2025/05/17 16:00:00 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


char	**read_map(const char *file)
{
	int		fd;
	char	*line;
	char	*joined;
	char	**map;

	joined = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("Could not open the map");
	line = get_next_line(fd);
	while (line)
	{
		joined = ft_strjoin_temp(joined, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map = ft_split(joined, '\n');
	free(joined);
	return (map);
}

static bool	check_elements_count(t_counter *cnt)
{
	if (cnt->p == 1 && cnt->c >= 1 && cnt->e == 1)
		return (true);
	return (false);
}

static bool	check_collectibles_access(t_game *game)
{
	char	**copy;
	t_dim	dim;
	t_coord	start;
	int		y;
	int		x;

	dim = (t_dim){game->width, game->height};
	start = (t_coord){game->player_x, game->player_y};
	copy = duplicate_map(game->map, game->height);
	flood_fill_collect(copy, dim, start);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (copy[y][x])
		{
			if (copy[y][x] == COLLECTIBLE)
			{
				free_map(copy);
				return (false);
			}
			x++;
		}
		y++;
	}
	free_map(copy);
	return (true);
}

static bool	check_exit_access(t_game *game)
{
	char	**copy;
	t_dim	dim;
	t_coord	start;
	int		y;
	int		x;

	dim = (t_dim){game->width, game->height};
	start = (t_coord){game->player_x, game->player_y};
	copy = duplicate_map(game->map, game->height);
	flood_fill_exit(copy, dim, start);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (copy[y][x])
		{
			if (copy[y][x] == EXIT)
			{
				free_map(copy);
				return (false);
			}
			x++;
		}
		y++;
	}
	free_map(copy);
	return (true);
}

bool	validate_map(t_game *game)
{
	t_counter	cnt;
	int			y;

	cnt = (t_counter){0, 0, 0};
	y = 0;
	while (y < game->height)
	{
		if ((int)ft_strlen(game->map[y]) != game->width
			|| !check_line(game, y, &cnt))
			return (false);
		y++;
	}
	if (!check_elements_count(&cnt))
		return (false);
	game->collectibles = cnt.c;
	return (check_collectibles_access(game)
		&& check_exit_access(game));
}