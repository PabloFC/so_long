/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:33:06 by pafuente          #+#    #+#             */
/*   Updated: 2025/05/14 13:02:57 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error_exit(const char *msg)
{
	ft_printf("Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}

int count_rows(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void free_map(char **map)
{
	int i;

	if (!map)
		return;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
