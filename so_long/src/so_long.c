/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:35:19 by meyu              #+#    #+#             */
/*   Updated: 2025/09/01 16:05:44 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	char	*map_adress;

	if (argc != 2)
		return (printf("Please input: ./Game <map adress>\n"), 0);
	map_adress = argv[1];
	if (!ft_game_init(&game, map_adress))
	{
		puts("Init failed");
		ft_free_game(&game);
		return (EXIT_FAILURE);
	}
	mlx_key_hook(game.mlx, key_hook, &game);
	mlx_loop(game.mlx);
	ft_free_game(&game);
	return (EXIT_SUCCESS);
}
