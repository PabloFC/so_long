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

/* read_map opens the map file, reads all its lines,
joins them together and then splits them into an array of strings,
thus returning the map ready to be used in the game. */
char **read_map(const char *file)
{
	int fd;
	char *line;
	char *joined = NULL;
	char **map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("Could not open the map");
	while ((line = get_next_line(fd)))
	{
		joined = ft_strjoin_temp(joined, line);
		free(line);
	}
	close(fd);
	map = ft_split(joined, '\n');
	free(joined);
	return (map);
}

static bool check_elements_count(int player, int collect, int exit_count)
{
	return (player == 1 && collect >= 1 && exit_count >= 1);
}

static bool	check_collectibles_access(t_game *game)
{
	char	**copy;
	int		y;
	int		x;

	copy = duplicate_map(game->map, game->height);
	flood_fill(copy, game->width, game->height,
		game->player_x, game->player_y);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (copy[y][x])
		{
			if (copy[y][x] == 'C')
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
	int		y;
	int		x;

	copy = duplicate_map(game->map, game->height);
	flood_fill_exit(copy, game->width, game->height,
		game->player_x, game->player_y);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (copy[y][x])
		{
			if (copy[y][x] == 'E')
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
/*validate_map ensures that the map is rectangular,
 is surrounded by walls, contains only valid characters,
 has exactly one player, at least one collectible, and at least one exit.
 If everything is correct, it returns true;
 otherwise, it returns false.*/
bool validate_map(t_game *game)
{
	int y = 0;
	int player = 0;
	int collect = 0;
	int exit_count = 0;

	while (y < game->height)
	{
		if ((int)ft_strlen(game->map[y]) != game->width)
			return (false);
		if (!check_line(game, y, &player, &collect, &exit_count))
			return (false);
		y++;
	}
	if (!check_elements_count(player, collect, exit_count))
		return (false);
	game->collectibles = collect;
	return (check_collectibles_access(game) && check_exit_access(game));
}
