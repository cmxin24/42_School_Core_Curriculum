/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:49:28 by xin               #+#    #+#             */
/*   Updated: 2025/09/01 20:40:54 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ft_init_pos(t_game *game, int x, int y)
{
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				if (mlx_image_to_window(game->mlx, game->player_right,
						x * 32, y * 32) < 0)
					return (0);
				if (mlx_image_to_window(game->mlx, game->player_left,
						-100, -100) < 0)
					return (0);
				game->player_left->instances[game->player_left->count - 1]
					.enabled = false;
				game->current = game->player_right;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static int	ft_game_load_png(t_game *game)
{
	game->tex_bg = mlx_load_png("./textures/background.png");
	game->tex_wall = mlx_load_png("./textures/wall.png");
	game->tex_coin = mlx_load_png("./textures/collect.png");
	game->tex_exit = mlx_load_png("./textures/exit.png");
	game->tex_left = mlx_load_png("./textures/hollow_knight_left.png");
	game->tex_right = mlx_load_png("./textures/hollow_knight_right.png");
	if (!game->tex_bg || !game->tex_wall || !game->tex_coin
		|| !game->tex_exit || !game->tex_left || !game->tex_right)
	{
		ft_printf("Error\nLoad png failed!\n");
		return (ft_free_game(game), 0);
	}
	return (1);
}

static int	ft_game_texture_to_image(t_game *game)
{
	game->background = mlx_texture_to_image(game->mlx, game->tex_bg);
	game->wall = mlx_texture_to_image(game->mlx, game->tex_wall);
	game->coin = mlx_texture_to_image(game->mlx, game->tex_coin);
	game->exit = mlx_texture_to_image(game->mlx, game->tex_exit);
	game->player_left = mlx_texture_to_image(game->mlx, game->tex_left);
	game->player_right = mlx_texture_to_image(game->mlx, game->tex_right);
	if (!game->background || !game->wall || !game->coin
		|| !game->exit || !game->player_left || !game->player_right)
	{
		ft_printf("Error\nMake texture to image failed!\n");
		return (ft_free_game(game), 0);
	}
	return (1);
}

int	ft_game_init(t_game *game, char *map_path)
{
	ft_memset(game, 0, sizeof(t_game));
	game->map = load_maps(map_path, &game->width, &game->height, 0);
	if (!game->map || !ft_validate_map(game->map, game->width, game->height))
		return (ft_free_game(game), exit(EXIT_FAILURE), 0);
	game->coin_left = count_coins(game->map, game->width, game->height);
	game->coins = NULL;
	if (game->coin_left > 0)
	{
		game->coins = (t_coin *)malloc(sizeof(t_coin) * game->coin_left);
		if (!game->coins)
			return (0);
		ft_memset(game->coins, 0, sizeof(t_coin) * game->coin_left);
	}
	game->mlx = mlx_init(game->width * 32, game->height * 32, "So_long!", true);
	if (!game->mlx)
		return (ft_free_game(game), 0);
	if (!ft_game_load_png(game))
		return (0);
	if (!ft_game_texture_to_image(game))
		return (0);
	if (!draw_bg(game) || !draw_map(game, 0, 0) || !ft_init_pos(game, 0, 0))
		return (ft_free_game(game), 0);
	return (1);
}
