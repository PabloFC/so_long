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

char **read_map(const char *file)
{
	int fd;
	char *line;
	char *joined;
	char **map;

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
