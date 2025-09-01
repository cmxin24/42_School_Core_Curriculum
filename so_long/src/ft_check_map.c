/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:57:01 by xin               #+#    #+#             */
/*   Updated: 2025/09/01 16:12:06 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_check_wall(char **map, int x, int y, int height)
{
	if (map[y][x] != '1')
	{
		printf("Error: Map border must be walls!\n");
		ft_free_map(map, height);
		exit(EXIT_FAILURE);
	}
}

static int	ft_check_num(int player, int exit, int coin)
{
	if (player != 1)
	{
		ft_printf("Error: The number of player should be 1!\n");
		return (0);
	}
	if (exit < 1)
	{
		ft_printf("Error: Map should have at least 1 exit!\n");
		return (0);
	}
	if (coin < 1)
	{
		ft_printf("Error: Map should have at least 1 coin!\n");
		return (0);
	}
	return (1);
}

static int	ft_check_map(char **map, int width, int heigth, int coin)
{
	int	x;
	int	y;
	int	player;
	int	exit;

	player = 0;
	exit = 0;
	y = 0;
	while (y < heigth)
	{
		ft_check_rectangle(map, y, width, heigth);
		x = 0;
		while (x < width)
		{
			ft_check_char(map[y][x], map, heigth);
			ft_check_player(map, x, y, &player);
			ft_check_exit(map, x, y, &exit);
			ft_check_coin(map, x, y, &coin);
			if (y == 0 || y == heigth -1 || x == 0 || x == width - 1)
				ft_check_wall(map, x, y, heigth);
			x++;
		}
		y++;
	}
	return (ft_check_num(player, exit, coin));
}

int	ft_validate_map(char **map, int width, int height)
{
	t_map	temp;

	if (!ft_check_map(map, width, height, 0))
		return (0);
	temp.map = map;
	temp.width = width;
	temp.height = height;
	if (!ft_check_path(&temp))
		return (0);
	return (1);
}
