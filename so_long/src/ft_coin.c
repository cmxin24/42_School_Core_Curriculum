/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:43:17 by xin               #+#    #+#             */
/*   Updated: 2025/09/01 18:27:41 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	collcet_coin(t_game *g, int x, int y)
{
	int	i;

	if (g->map[y][x] != 'C')
		return ;
	g->map[y][x] = '0';
	if (!g->coins)
		return ;
	i = 0;
	while (i < g->coin_count)
	{
		if (!g->coins[i].collected && g->coins[i].x == x && g->coins[i].y == y)
		{
			if (g->coin && (int)g->coin->count > g->coins[i].coin_id)
				g->coin->instances[g->coins[i].coin_id].enabled = false;
			g->coins[i].collected = true;
			break ;
		}
		i++;
	}
	if (g->coin_left > 0)
		g->coin_left--;
}

int	count_coins(char **map, int width, int height)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
