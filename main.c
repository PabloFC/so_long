/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:37:35 by pafuente          #+#    #+#             */
/*   Updated: 2025/05/13 11:44:01 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		error_exit("Usage: ./so_long maps/file.ber");

	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		error_exit("The file must have a .ber extension");

	game.map = read_map(argv[1], &game);
	game.height = count_rows(game.map);
	game.width = ft_strlen(game.map[0]);

	if (!validate_map(&game) || !validate_path(&game))
	{
		free_map(game.map);
		error_exit("Invalid map");
	}

	init_game(&game);
	load_textures(&game);
	render_map(&game);

	mlx_key_hook(game.mlx, handle_input, &game);
	mlx_close_hook(game.mlx, (void *)close_game, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free_map(game.map);
	return (0);
}
