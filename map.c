<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:35:37 by pafuente          #+#    #+#             */
/*   Updated: 2025/05/15 10:34:35 by pafuente         ###   ########.fr       */
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
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:35:37 by pafuente          #+#    #+#             */
/*   Updated: 2025/05/13 12:35:38 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> 8bb18afef03965abb57c8c2ff233a83ff57d4e58
