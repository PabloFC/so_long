/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:35:37 by pafuente          #+#    #+#             */
/*   Updated: 2025/05/15 12:01:49 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(const char *file, t_game *game)
{
	int		fd;
	char	*line;
	char	*joined;
	char	**map;

    (void)game;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("Could not open the map");

	joined = NULL;
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

static bool	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E');
}

bool	validate_map(t_game *game)
{
	int		y;
	int		x;
	int		player = 0;
	int		collect = 0;
	int		exit = 0;

	y = 0;
	while (y < game->height)
	{
		if ((int)ft_strlen(game->map[y]) != game->width)
			return (false); // No es rectangular

		x = 0;
		while (x < game->width)
		{
			char tile = game->map[y][x];
			if (!is_valid_char(tile))
				return (false);

			if ((y == 0 || y == game->height - 1 || x == 0 || x == game->width - 1) && tile != '1')
				return (false); // Bordes no cerrados

			if (tile == 'P')
			{
				player++;
				game->player_x = x;
				game->player_y = y;
			}
			else if (tile == 'C')
				collect++;
			else if (tile == 'E')
				exit++;
			x++;
		}
		y++;
	}
	if (player != 1 || collect < 1 || exit < 1)
		return (false);
	game->collectibles = collect;
	return (true);
}