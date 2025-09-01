/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:12:25 by xin               #+#    #+#             */
/*   Updated: 2025/09/01 15:21:40 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_visited(t_map *map, int **visited)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		free(visited[y]);
		y++;
	}
	free(visited);
}

void	dfs(t_map *map, int x, int y, int **visited)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return ;
	if (map->map[y][x] == '1' || visited[y][x])
		return ;
	visited[y][x] = 1;
	dfs(map, x + 1, y, visited);
	dfs(map, x - 1, y, visited);
	dfs(map, x, y + 1, visited);
	dfs(map, x, y - 1, visited);
}

int	ft_find_player(t_map *map, int *px, int *py)
{
	int	y;
	int	x;

	y = 0;
	*px = -1;
	*py = -1;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'P')
			{
				*px = x;
				*py = y;
			}
			x++;
		}
		y++;
	}
	if (*px == -1 || *py == -1)
		return (0);
	return (1);
}

int	ft_check_accessible(t_map *map, int **visited)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if ((map->map[y][x] == 'C' || map->map[y][x] == 'E')
				&& !visited[y][x])
			{
				ft_printf("Error: Not all coins and exits are reachable!\n");
				ft_free_visited(map, visited);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_check_path(t_map *map)
{
	int	**visited;
	int	y;
	int	px;
	int	py;

	visited = malloc(sizeof(int *) * map->height);
	if (!visited)
		return (0);
	y = 0;
	while (y < map->height)
	{
		visited[y] = ft_calloc(map->width, sizeof(int));
		if (!visited[y])
			return (0);
		y++;
	}
	if (!ft_find_player(map, &px, &py))
		return (ft_free_visited(map, visited), 0);
	dfs(map, px, py, visited);
	if (!ft_check_accessible(map, visited))
		return (0);
	ft_free_visited(map, visited);
	return (1);
}
