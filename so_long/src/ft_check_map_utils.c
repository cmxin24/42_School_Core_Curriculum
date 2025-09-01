/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:39:25 by xin               #+#    #+#             */
/*   Updated: 2025/09/01 15:39:51 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_check_char(char c, char **map, int height)
{
	if (!(c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C'))
	{
		ft_printf("Error: Map contains wrong character!\n");
		ft_free_map(map, height);
		exit(EXIT_FAILURE);
	}
}

void	ft_check_rectangle(char **map, int y, int width, int height)
{
	if ((int)ft_strlen(map[y]) != width)
	{
		ft_printf("Error: Map is not rectangular!\n");
		ft_free_map(map, height);
		exit(EXIT_FAILURE);
	}
}

void	ft_check_player(char **map, int x, int y, int *player)
{
	if (map[y][x] == 'P')
		*(player) += 1;
}

void	ft_check_exit(char **map, int x, int y, int *exit)
{
	if (map[y][x] == 'E')
		*(exit) += 1;
}

void	ft_check_coin(char **map, int x, int y, int *coin)
{
	if (map[y][x] == 'C')
		*(coin) += 1;
}
