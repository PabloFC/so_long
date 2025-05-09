/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:37:35 by pafuente          #+#    #+#             */
/*   Updated: 2025/05/09 14:16:36 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("Uso: ./so_long maps/map.ber");

	game.map = read_map(argv[1], &game);
	if (!validate_map(&game))
		error_exit("Mapa inválido");

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


/*Estructura


so_long/
├── Makefile
├── MLX42/
│   
├── include/
│   └── so_long.h
├── src/
│   ├── main.c
│   ├── init.c
│   ├── map.c
│   ├── render.c
│   ├── game.c
│   └── utils.c
├── assets/
│   ├── wall.png
│   ├── floor.png
│   ├── player.png
│   ├── collect.png
│   └── exit.png
├── maps/
│   └── map.ber
└── libft/ 
*/