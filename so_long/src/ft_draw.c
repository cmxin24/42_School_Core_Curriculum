/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:44:34 by xin               #+#    #+#             */
/*   Updated: 2025/09/01 16:12:55 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	draw_bg(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			mlx_image_to_window(game->mlx, game->background, x * 32, y * 32);
			x ++;
		}
		y ++;
	}
	return (1);
}

static void	draw_coin(t_game *game, int *id, int x, int y)
{
	*id = mlx_image_to_window(game->mlx, game->coin, x * 32, y * 32);
	if (*id >= 0)
	{
		game->coins[game->coin_count].x = x;
		game->coins[game->coin_count].y = y;
		game->coins[game->coin_count].coin_id = *id;
		game->coin_count++;
	}
}

int	draw_map(t_game *game, int x, int y)
{
	char		character;
	mlx_image_t	*img;
	int			id;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			character = game->map[y][x];
			img = NULL;
			if (character == '1')
				img = game->wall;
			else if (character == 'C')
				draw_coin(game, &id, x, y);
			else if (character == 'E')
				img = game->exit;
			if (img)
				mlx_image_to_window(game->mlx, img, x * TILE, y * TILE);
			x++;
		}
		y ++;
	}
	return (1);
}
